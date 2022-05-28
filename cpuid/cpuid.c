#include "cpu_id.h"
#include <stdio.h>
#ifdef __GNUC__
#include <cpuid.h>
#else
#include <intrin.h>
#endif // __GNUC__

static uint32_t hcp = 0;

int cpuid_get_info(cpuid_t *str)
{
    cpuid_get_name(str->name, &(str->highest_basic_calling_parameter));
}

char *cpuid_get_name(char str[13], uint32_t *ret)
{
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
#ifdef __GNUC__
    __cpuid(0, eax, ebx, ecx, edx);
#else
    __asm {
    mov EAX, 0;
    cpuid;
    mov eax, EAX;
    mov ebx, EBX;
    mov ecx, ECX;
    mov edx, EDX;
    }
#endif // __GNUC__
    *(uint32_t *)str = ebx;
    *(uint32_t *)(str + 4) = edx;
    *(uint32_t *)(str + 8) = ecx;
    str[12] = '\0';
    hcp = eax;
    if (ret != NULL)
    {
        *ret = eax;
    }
    return (char *)str;
}

int cpuid_get_processor_info_and_features(cpuid_t *ret)
{
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
#ifdef __GNUC__
    __cpuid(1, eax, ebx, ecx, edx);
#else
    __asm {
    mov EAX, 1;
    cpuid;
    mov eax, EAX;
    mov ebx, EBX;
    mov ecx, ECX;
    mov edx, EDX;
    }
#endif // __GNUC__
    ret->stepping_id = eax & 0b1111;
    ret->model = (eax >> 4) & 0b1111;
    ret->family_id = (eax >> 8) & 0b1111;
    ret->processor_type = (eax >> 12) & 0b11;
    ret->extended_model_id = (eax >> 16) & 0b1111;
    ret->extended_family_id = (eax >> 20) & 0b11111111;
    cpuid_get_processor_type(ret->processor_type, &(ret->processor_type_str));
}

char *cpuid_get_processor_type_str(uint32_t type, char **str)
{
    static char *types[4] = {"oem_processor", "overdrive_processor", "dual_processor", "reserved"};
    *str = types[type];
    return str;
}

char *cpuid_get_extended_family_str(uint32_t id, char **str)
{
    static char *types[4] = {"oem_processor", "overdrive_processor", "dual_processor", "reserved"};
    *str = types[id];
    return str;
}