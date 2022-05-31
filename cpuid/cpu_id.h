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
