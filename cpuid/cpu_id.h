#ifndef CPUID_H
#define CPUID_H
#include <stdint.h>

typedef enum
{
    cpuid_processor_type_reserved = 3,
    cpuid_processor_type_dual_processor = 2,
    cpuid_processor_type_overdrive_processor = 1,
    cpuid_processor_type_oem_processor = 0
} cpuid_processor_type_t;

typedef enum
{
    cpuid_feature_ecx_SSE3 = 1 << 0,
    cpuid_feature_ecx_PCLMUL = 1 << 1,
    cpuid_feature_ecx_DTES64 = 1 << 2,
    cpuid_feature_ecx_MONITOR = 1 << 3,
    cpuid_feature_ecx_DS_CPL = 1 << 4,
    cpuid_feature_ecx_VMX = 1 << 5,
    cpuid_feature_ecx_SMX = 1 << 6,
    cpuid_feature_ecx_EST = 1 << 7,
    cpuid_feature_ecx_TM2 = 1 << 8,
    cpuid_feature_ecx_SSSE3 = 1 << 9,
    cpuid_feature_ecx_CID = 1 << 10,
    cpuid_feature_ecx_SDBG = 1 << 11,
    cpuid_feature_ecx_FMA = 1 << 12,
    cpuid_feature_ecx_CX16 = 1 << 13,
    cpuid_feature_ecx_XTPR = 1 << 14,
    cpuid_feature_ecx_PDCM = 1 << 15,
    cpuid_feature_ecx_PCID = 1 << 17,
    cpuid_feature_ecx_DCA = 1 << 18,
    cpuid_feature_ecx_SSE4_1 = 1 << 19,
    cpuid_feature_ecx_SSE4_2 = 1 << 20,
    cpuid_feature_ecx_X2APIC = 1 << 21,
    cpuid_feature_ecx_MOVBE = 1 << 22,
    cpuid_feature_ecx_POPCNT = 1 << 23,
    cpuid_feature_ecx_TSC = 1 << 24,
    cpuid_feature_ecx_AES = 1 << 25,
    cpuid_feature_ecx_XSAVE = 1 << 26,
    cpuid_feature_ecx_OSXSAVE = 1 << 27,
    cpuid_feature_ecx_AVX = 1 << 28,
    cpuid_feature_ecx_F16C = 1 << 29,
    cpuid_feature_ecx_RDRAND = 1 << 30,
    cpuid_feature_ecx_HYPERVISOR = 1 << 31,
    cpuid_feature_edx_FPU = 1 << 0,
    cpuid_feature_edx_VME = 1 << 1,
    cpuid_feature_edx_DE = 1 << 2,
    cpuid_feature_edx_PSE = 1 << 3,
    cpuid_feature_edx_TSC = 1 << 4,
    cpuid_feature_edx_MSR = 1 << 5,
    cpuid_feature_edx_PAE = 1 << 6,
    cpuid_feature_edx_MCE = 1 << 7,
    cpuid_feature_edx_CX8 = 1 << 8,
    cpuid_feature_edx_APIC = 1 << 9,
    cpuid_feature_edx_SEP = 1 << 11,
    cpuid_feature_edx_MTRR = 1 << 12,
    cpuid_feature_edx_PGE = 1 << 13,
    cpuid_feature_edx_MCA = 1 << 14,
    cpuid_feature_edx_CMOV = 1 << 15,
    cpuid_feature_edx_PAT = 1 << 16,
    cpuid_feature_edx_PSE36 = 1 << 17,
    cpuid_feature_edx_PSN = 1 << 18,
    cpuid_feature_edx_CLFLUSH = 1 << 19,
    cpuid_feature_edx_DS = 1 << 21,
    cpuid_feature_edx_ACPI = 1 << 22,
    cpuid_feature_edx_MMX = 1 << 23,
    cpuid_feature_edx_FXSR = 1 << 24,
    cpuid_feature_edx_SSE = 1 << 25,
    cpuid_feature_edx_SSE2 = 1 << 26,
    cpuid_feature_edx_SS = 1 << 27,
    cpuid_feature_edx_HTT = 1 << 28,
    cpuid_feature_edx_TM = 1 << 29,
    cpuid_feature_edx_IA64 = 1 << 30,
    cpuid_feature_edx_PBE = 1 << 31
} cpuid_feature_t;

typedef enum
{
    cpuid_manufacturer_intel,
    cpuid_manufacturer_amd
} cpuid_manufacturer_t;

typedef struct
{
    char name[13];
    char *manufacturer_str;
    char *model_str;
    char *family_str;
    char *brand_str;
    char *processor_type_str;
    char *extended_model_str;
    char *extended_family_str;
    cpuid_manufacturer_t manufacturer_id;
    uint32_t highest_basic_calling_parameter;
    uint32_t stepping_id;
    uint32_t model_id;
    uint32_t brand_id;
    uint32_t family_id;
    uint32_t processor_type;
    uint32_t extended_model_id;
    uint32_t extended_family_id;
} cpuid_t;

int cpuid_get_info(cpuid_t *info);

void cpuid_init_struct(cpuid_t *str);

void cpuid_free_struct(cpuid_t *str);

int cpuid_get_processor_info_and_features(cpuid_t *ret);

char *cpuid_get_name(char str[13], uint32_t *ret);

char *cpuid_get_processor_type_str(uint32_t type, char **str);

char *cpuid_get_extended_family_str(uint32_t id, char **str);

int cpuid_get_family_and_model_str(cpuid_t *ret, uint32_t signature);

#endif // CPUID_H
