/*
 * Generated file - do not edit
 *
 * simon_sysbench.cc
 *
 * This file was generated by SimonTool
 */

// this macro is used in stdint.h and causes the UINT64_C macro to be defined
#ifndef __STDC_CONSTANT_MACROS
#define __STDC_CONSTANT_MACROS
#endif

#include "simon_sysbench.h"

using namespace simon;

/*
 * Initialize static data for class Simon_sysbenchContextC
 */

// The singleton context object
Simon_sysbenchContextC Simon_sysbenchContextC::sTheInstance;

// The app name
std::string Simon_sysbenchContextC::sAppName("OceanBase");

// The Blurb Message signature(s)
Simon_sysbenchContextC::SimonSigC Simon_sysbenchContextC::sBlurbMessageSigs[] = {
    SimonSigC("SysbenchState", 0x1000000, 0x1e0c30a0, 5)
};

// Array of Report signatures
Simon_sysbenchContextC::SimonSigC Simon_sysbenchContextC::sReportSigs[] = {
    SimonSigC("sysbench report", 0x1000000, 0x792b01d9)
};

// Compressed config files as byte array
static unsigned char compressedConfigFileBytes[] = {
    0x1f,0x8b,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x95,0x54,0xd1,0x6e,0x82,0x30,
    0x14,0x7d,0x1e,0x5f,0xd1,0xf5,0x69,0x7b,0x70,0xdd,0x1e,0xf6,0x56,0x31,0x6a,0x8c,
    0x33,0x71,0x4a,0x00,0x9f,0x49,0xc5,0x2b,0x23,0x83,0xd6,0xb5,0xc5,0xcc,0xbf,0x5f,
    0x85,0x22,0x88,0x66,0x6e,0x7d,0x20,0x70,0xd3,0x73,0xee,0xbd,0xe7,0x9c,0x40,0x07,
    0xdf,0x79,0x86,0xf6,0x20,0x55,0x2a,0x78,0x1f,0xbf,0x3c,0x3d,0xe3,0x81,0xeb,0x38,
    0x54,0xa5,0xb9,0xe0,0x63,0xc1,0xb7,0x69,0x82,0x38,0xcb,0xa1,0x8f,0x97,0x31,0x30,
    0x3e,0x62,0x0a,0x30,0x72,0x1d,0x64,0x4e,0xf9,0xa0,0xf7,0xbd,0x1e,0x1a,0xcd,0x57,
    0xfe,0x28,0x40,0x0f,0xc3,0xe9,0xd4,0x9f,0x4c,0x87,0xe1,0xd2,0x47,0xb3,0x85,0xb7,
    0x0a,0x51,0xaf,0x57,0x5d,0xa5,0xeb,0xac,0x90,0xeb,0x77,0x50,0x8a,0x25,0x60,0xf9,
    0x82,0x83,0x5a,0x03,0x8f,0x3f,0x02,0xcd,0xb4,0xe1,0x6c,0x46,0xc0,0x68,0x07,0x32,
    0x15,0x9b,0x3e,0x7e,0xad,0x5b,0x35,0x1c,0x1d,0xb0,0x07,0xf2,0x4d,0x28,0x8d,0x5d,
    0xe7,0xce,0xdc,0xd0,0xac,0x1e,0xf6,0x58,0x3c,0xbe,0x61,0xa4,0x0f,0x3b,0xf3,0xad,
    0xb4,0x4c,0x79,0x82,0x49,0x43,0x67,0xae,0xc7,0xa2,0xe0,0x1a,0xa4,0x85,0xf8,0xf0,
    0x55,0x80,0xd2,0xe3,0x63,0xb1,0x86,0x65,0xe2,0x02,0x94,0xb0,0xe2,0xb4,0x82,0x85,
    0xcc,0xcd,0x02,0x3c,0x3e,0xfc,0x02,0x3a,0xef,0xe4,0x49,0xd8,0x31,0x09,0xff,0xe9,
    0x64,0x21,0x37,0x3a,0x51,0x52,0x6a,0x64,0x35,0x27,0x6d,0xd1,0xdb,0x96,0x19,0x2e,
    0x21,0xb5,0x57,0x8a,0x6c,0xf9,0x37,0xb0,0x65,0x45,0x66,0x6b,0x18,0x29,0x88,0x05,
    0xdf,0xa8,0xa3,0x03,0xa4,0x6b,0xb6,0x3f,0xf1,0x96,0x7e,0x78,0xee,0xf6,0x72,0x15,
    0x1a,0xbb,0x1f,0x1b,0xbf,0xab,0x16,0x96,0x5c,0x59,0xb3,0x50,0x55,0xbd,0xe6,0xb5,
    0xea,0x8e,0x60,0x32,0x78,0xda,0xaa,0x82,0xcd,0x34,0xe4,0x1d,0xf7,0x31,0x2a,0x57,
    0xbc,0x16,0x07,0xd4,0x3a,0xf4,0x13,0x0e,0xad,0x5c,0x2c,0xaa,0x5c,0xb0,0xa4,0x15,
    0x13,0xd2,0x41,0xec,0x59,0x56,0x74,0x5c,0x56,0x91,0x61,0x8f,0x82,0x52,0x19,0xec,
    0xb6,0xd3,0x42,0xaa,0x1d,0x28,0x29,0x51,0xb7,0x99,0xa2,0xda,0x46,0xf7,0x3c,0x40,
    0xb7,0x09,0x6c,0x0c,0x22,0xdf,0x0b,0xb0,0xdb,0x8e,0xd1,0x9f,0x47,0xa8,0x19,0x4e,
    0x23,0x9c,0x27,0xeb,0x82,0x80,0x92,0x46,0xfd,0x3a,0x57,0x55,0xc5,0xe6,0x82,0x92,
    0xd6,0xaf,0xc2,0x75,0x7e,0x00,0xdc,0x7f,0x9c,0x02,0x50,0x04,0x00,0x00
};

// The compressed config file as a string
ustring Simon_sysbenchContextC::sCompressedConfigFile(compressedConfigFileBytes, 414);

// The time (millisecs since the epoch) that this file was generated
uint64_t Simon_sysbenchContextC::sTimeStamp = UINT64_C(1361252127550);




/*
 * Initialize static data for class SysbenchPerHostBlurbC
 */

static SysbenchPerHostBlurbC _dummyBlurb1;
static char *base1 = reinterpret_cast<char*>(&_dummyBlurb1);

uint8_t SysbenchPerHostBlurbC::sBlurbCode = 1;

char *SysbenchPerHostBlurbC::sTagFormat = "P";

size_t SysbenchPerHostBlurbC::sTagOffsets[] = {
    reinterpret_cast<char*>(&_dummyBlurb1.hostname) - base1
};


char *SysbenchPerHostBlurbC::sMetricFormat = "lLlL";
size_t SysbenchPerHostBlurbC::sMetricOffsets[] = {
    reinterpret_cast<char*>(&_dummyBlurb1.requestCount) - base1,
    reinterpret_cast<char*>(&_dummyBlurb1.requestLatency) - base1,
    reinterpret_cast<char*>(&_dummyBlurb1.prepareCount) - base1,
    reinterpret_cast<char*>(&_dummyBlurb1.prepareLatency) - base1
};


