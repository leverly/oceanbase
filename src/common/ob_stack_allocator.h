/**
 * (C) 2007-2010 Taobao Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Version: $Id$
 *
 * Authors:
 *   yuanqi <yuanqi.xhf@taobao.com>
 *     - some work details if you want
 */
#ifndef __OB_COMMON_OB_STACK_ALLOCATOR_H__
#define __OB_COMMON_OB_STACK_ALLOCATOR_H__
#include "ob_define.h"
#include "pthread.h"
#include "tbsys.h"
#include "ob_allocator.h"

namespace oceanbase
{
  namespace common
  {
    class DefaultBlockAllocator: public ObIAllocator
    {
      public:
        DefaultBlockAllocator();
        ~DefaultBlockAllocator();
      public:
        void set_mod_id(int32_t mod);
        int set_limit(const int64_t limit);
        const int64_t get_allocated() const;
        void* alloc(const int64_t size);
        void free(void* p);
      private:
        int32_t mod_;
        int64_t limit_;
        volatile int64_t allocated_;
    };

    class StackAllocator: public ObIAllocator
    {
      struct Block
      {
        int init(const int64_t limit);
        int64_t remain() const;
	int64_t magic_;
        Block* next_;
        int64_t limit_;
        int64_t pos_;
        int64_t checksum_;
      };
      public:
        StackAllocator();
        ~StackAllocator();
      public:
        int init(ObIAllocator* allocator, const int64_t block_size);
        int clear(const bool slow=false);
        int reserve(const int64_t size);
        void* alloc(const int64_t size);
        void free(void* p);
        void set_mod_id(int32_t mod_id) {allocator_->set_mod_id(mod_id);};
        int start_batch_alloc();
        int end_batch_alloc(const bool rollback);
      protected:
        int set_reserved_block(Block* block);
        int reserve_block(const int64_t size);
        int alloc_block(Block*& block, const int64_t size);
        int free_block(Block* block);
        int alloc_head(const int64_t size);
        int free_head();
        int save_top(int64_t& top) const;
        int restore_top(const int64_t top, const bool slow=false);
      private:
        ObIAllocator* allocator_;
        int64_t block_size_;
        int64_t top_;
        int64_t saved_top_;
        Block* head_;
        Block* reserved_;
    };

    template<typename Factory, typename T>
    class TSIContainer
    {
      public:
        enum {INIT, DOING, DONE};
        TSIContainer(Factory& factory): create_stat_(INIT), factory_(factory) {}
        ~TSIContainer() { clear(); }
        T* get(){
          int err = 0;
          T* val = NULL;
          while(create_stat_ != DONE)
          {
            if (!__sync_bool_compare_and_swap(&create_stat_, INIT, DOING))
            {} // do nothing
            else if (0 != (err = pthread_key_create(&key_, destroy)))
            {
              __sync_bool_compare_and_swap(&create_stat_, DOING, INIT);
              TBSYS_LOG(ERROR, "pthread_key_create() fail, err=%d", err);
              break;
            }
            else
            {
              __sync_bool_compare_and_swap(&create_stat_, DOING, DONE);
            }
          }
          if (create_stat_ != DONE)
          {}
          else if (NULL != (val = (T*)pthread_getspecific(key_)))
          {}
          else if (0 != (err = factory_.new_instance(val)))
          {}
          else if (0 != (err = pthread_setspecific(key_, val)))
          {}
          if (0 != err)
          {
            destroy(val);
            val = NULL;
          }
          return val;
        }
        void clear()
        {
          int err = 0;
          while(create_stat_ != INIT)
          {
            if (!__sync_bool_compare_and_swap(&create_stat_, DONE, DOING))
            {} // do nothing
            else
            {
              if (0 != (err = pthread_key_delete(key_)))
              {
                TBSYS_LOG(ERROR, "pthread_key_delete() fail, err=%d", err);
              }
              __sync_bool_compare_and_swap(&create_stat_, DOING, INIT);
            }
          }
        }
      private:
        static void destroy(void* arg) {
          if (NULL != arg)
          {
            //(T*)arg->destroy();
          }
        }
        volatile int create_stat_;
        pthread_key_t key_;
        Factory& factory_;
    };

    class TSIStackAllocator
    {
      public:
        struct AllocatorNode
        {
          AllocatorNode* next_;
          StackAllocator allocator_;
        };
        struct BatchAllocGuard
        {
          BatchAllocGuard(TSIStackAllocator& allocator, int& err): allocator_(allocator), err_(err)
          {
            if (OB_SUCCESS != allocator_.start_batch_alloc())
            {
              TBSYS_LOG(ERROR, "start_batch_alloc() fail");
            }
          }
          ~BatchAllocGuard()
          {
            if (OB_SUCCESS != allocator_.end_batch_alloc(OB_SUCCESS != err_))
            {
              TBSYS_LOG(ERROR, "end_batch_alloc(OB_SUCCESS != err[%d]) fail", err_);
            }
          }
          TSIStackAllocator& allocator_;
          int& err_;
        };
      public:
        TSIStackAllocator();
        ~TSIStackAllocator();
        int init(ObIAllocator* block_allocator, int64_t block_size);
        int clear(const bool slow=false);
        int reserve(const int64_t size);
        void* alloc(const int64_t size);
        void free(void* p);
        int start_batch_alloc();
        int end_batch_alloc(const bool rollback);
        int new_instance(StackAllocator*& allocator);
        StackAllocator* get();
      private:
        volatile uint64_t seq_;
        int64_t block_size_;
        StackAllocator inst_allocator_;
        AllocatorNode* head_;
        ObIAllocator* block_allocator_;
        TSIContainer<TSIStackAllocator, StackAllocator> container_;
    };
  }; // end namespace common
}; // end namespace oceanbase

#endif /* __OB_COMMON_OB_STACK_ALLOCATOR_H__ */
