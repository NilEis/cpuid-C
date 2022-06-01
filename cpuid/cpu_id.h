#ifndef CPUID_H
#define CPUID_H
#include <stdint.h>
#include "cpuid_constants.h"

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
    uint8_t sse3;
    uint8_t pclmulqdq;
    uint8_t dtes64;
    uint8_t monitor;
    uint8_t ds_cpl;
    uint8_t vmx;
    uint8_t smx;
    uint8_t est;
    uint8_t tm2;
    uint8_t ssse3;
    uint8_t cnxt_id;
    uint8_t sdbg;
    uint8_t fma;
    uint8_t cx16;
    uint8_t xtpr;
    uint8_t pdcm;
    uint8_t pcid;
    uint8_t dca;
    uint8_t sse4_1;
    uint8_t sse4_2;
    uint8_t x2apic;
    uint8_t movbe;
    uint8_t popcnt;
    uint8_t tsc_deadline;
    uint8_t aes;
    uint8_t xsave;
    uint8_t osxsave;
    uint8_t avx;
    uint8_t f16c;
    uint8_t rdrnd;
    uint8_t hypervisor;
    uint8_t fpu;
    uint8_t vme;
    uint8_t de;
    uint8_t pse;
    uint8_t tsc;
    uint8_t msr;
    uint8_t pae;
    uint8_t mce;
    uint8_t cx8;
    uint8_t apic;
    uint8_t sep;
    uint8_t mtrr;
    uint8_t pge;
    uint8_t mca;
    uint8_t cmov;
    uint8_t pat;
    uint8_t pse_36;
    uint8_t psn;
    uint8_t clfsh;
    uint8_t ds;
    uint8_t acpi;
    uint8_t mmx;
    uint8_t fxsr;
    uint8_t sse;
    uint8_t sse2;
    uint8_t ss;
    uint8_t htt;
    uint8_t tm;
    uint8_t ia64;
    uint8_t pbe;
} cpuid_t;

int cpuid_get_info(cpuid_t *info);

void cpuid_init_struct(cpuid_t *str);

void cpuid_free_struct(cpuid_t *str);

int cpuid_get_processor_info(cpuid_t *ret);

char *cpuid_get_name(char str[13], uint32_t *ret);

char *cpuid_get_processor_type_str(uint32_t type, char **str);

char *cpuid_get_extended_family_str(uint32_t id, char **str);

int cpuid_get_family_and_model_str(cpuid_t *ret, uint32_t signature);

void cpuid_get_features(uint32_t *ecx, uint32_t *edx);

#endif // CPUID_H
