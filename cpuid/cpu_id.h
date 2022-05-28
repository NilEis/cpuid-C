#ifndef CPUID_H
#define CPUID_H
#include <stdint.h>

typedef struct
{
    char name[13];
    char *model_str;
    char *family_id_str;
    char *processor_type_str;
    char *extended_model_id_str;
    char *extended_family_id_str;
    uint32_t highest_basic_calling_parameter;
    uint32_t stepping_id;
    uint32_t model;
    uint32_t family_id;
    uint32_t processor_type;
    uint32_t extended_model_id;
    uint32_t extended_family_id;
} cpuid_t;

enum processor_type_e
{
    processor_type_reserved = 3,
    processor_type_dual_processor = 2,
    processor_type_overdrive_processor = 1,
    processor_type_oem_processor = 0
};

int cpuid_get_info(cpuid_t *info);

int cpuid_get_processor_info_and_features(cpuid_t *ret);

char *cpuid_get_name(char str[13], uint32_t *ret);

char *cpuid_get_processor_type_str(uint32_t type, char **str);

char *cpuid_get_extended_family_str(uint32_t id, char **str);

#endif // CPUID_H
