#ifndef CPUID_CONSTANTS_H
#define CPUID_CONSTANTS_H
#include <stdint.h>

typedef enum
{
    cpuid_processor_type_reserved = 3,
    cpuid_processor_type_dual_processor = 2,
    cpuid_processor_type_overdrive_processor = 1,
    cpuid_processor_type_oem_processor = 0
} cpuid_processor_type_t;

// Non-integer enums are not iso compliant :(
extern uint32_t cpuid_feature_ecx_SSE3;
extern uint32_t cpuid_feature_ecx_PCLMUL;
extern uint32_t cpuid_feature_ecx_DTES64;
extern uint32_t cpuid_feature_ecx_MONITOR;
extern uint32_t cpuid_feature_ecx_DS_CPL;
extern uint32_t cpuid_feature_ecx_VMX;
extern uint32_t cpuid_feature_ecx_SMX;
extern uint32_t cpuid_feature_ecx_EST;
extern uint32_t cpuid_feature_ecx_TM2;
extern uint32_t cpuid_feature_ecx_SSSE3;
extern uint32_t cpuid_feature_ecx_CID;
extern uint32_t cpuid_feature_ecx_SDBG;
extern uint32_t cpuid_feature_ecx_FMA;
extern uint32_t cpuid_feature_ecx_CX16;
extern uint32_t cpuid_feature_ecx_XTPR;
extern uint32_t cpuid_feature_ecx_PDCM;
extern uint32_t cpuid_feature_ecx_PCID;
extern uint32_t cpuid_feature_ecx_DCA;
extern uint32_t cpuid_feature_ecx_SSE4_1;
extern uint32_t cpuid_feature_ecx_SSE4_2;
extern uint32_t cpuid_feature_ecx_X2APIC;
extern uint32_t cpuid_feature_ecx_MOVBE;
extern uint32_t cpuid_feature_ecx_POPCNT;
extern uint32_t cpuid_feature_ecx_TSC;
extern uint32_t cpuid_feature_ecx_AES;
extern uint32_t cpuid_feature_ecx_XSAVE;
extern uint32_t cpuid_feature_ecx_OSXSAVE;
extern uint32_t cpuid_feature_ecx_AVX;
extern uint32_t cpuid_feature_ecx_F16C;
extern uint32_t cpuid_feature_ecx_RDRAND;
extern uint32_t cpuid_feature_ecx_HYPERVISOR;
extern uint32_t cpuid_feature_edx_FPU;
extern uint32_t cpuid_feature_edx_VME;
extern uint32_t cpuid_feature_edx_DE;
extern uint32_t cpuid_feature_edx_PSE;
extern uint32_t cpuid_feature_edx_TSC;
extern uint32_t cpuid_feature_edx_MSR;
extern uint32_t cpuid_feature_edx_PAE;
extern uint32_t cpuid_feature_edx_MCE;
extern uint32_t cpuid_feature_edx_CX8;
extern uint32_t cpuid_feature_edx_APIC;
extern uint32_t cpuid_feature_edx_SEP;
extern uint32_t cpuid_feature_edx_MTRR;
extern uint32_t cpuid_feature_edx_PGE;
extern uint32_t cpuid_feature_edx_MCA;
extern uint32_t cpuid_feature_edx_CMOV;
extern uint32_t cpuid_feature_edx_PAT;
extern uint32_t cpuid_feature_edx_PSE36;
extern uint32_t cpuid_feature_edx_PSN;
extern uint32_t cpuid_feature_edx_CLFLUSH;
extern uint32_t cpuid_feature_edx_DS;
extern uint32_t cpuid_feature_edx_ACPI;
extern uint32_t cpuid_feature_edx_MMX;
extern uint32_t cpuid_feature_edx_FXSR;
extern uint32_t cpuid_feature_edx_SSE;
extern uint32_t cpuid_feature_edx_SSE2;
extern uint32_t cpuid_feature_edx_SS;
extern uint32_t cpuid_feature_edx_HTT;
extern uint32_t cpuid_feature_edx_TM;
extern uint32_t cpuid_feature_edx_IA64;
extern uint32_t cpuid_feature_edx_PBE;

typedef enum
{
    cpuid_manufacturer_intel,
    cpuid_manufacturer_amd
} cpuid_manufacturer_t;

#endif // CPUID_CONSTANTS_H
