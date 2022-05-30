#include "cpu_id.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#ifdef __GNUC__
#include <cpuid.h>
#else
#include <intrin.h>
#endif // __GNUC__

static uint32_t hcp = 0;

static void __cpuid_call(uint32_t p, uint32_t *ebx, uint32_t *edx, uint32_t *ecx, uint32_t *eax);

static void __cpuid_get_intel();

static void __cpuid_get_amd();

void cpuid_init_struct(cpuid_t *str)
{
    static char empty[] = "";
    str->brand_str = (char *)calloc(125, sizeof(char));
    str->extended_family_str = empty;
    str->extended_model_str = empty;
    str->family_str = empty;
    str->manufacturer_str = empty;
    str->model_str = empty;
    str->name[0] = '\0';
    str->processor_type_str = empty;
}

void cpuid_free_struct(cpuid_t *str)
{
    free(str->brand_str);
}

int cpuid_get_info(cpuid_t *str)
{
    cpuid_get_name(str->name, &(str->highest_basic_calling_parameter));
    cpuid_get_processor_info_and_features(str);
}

char *cpuid_get_name(char str[13], uint32_t *ret)
{
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    __cpuid_call(0, &eax, &ebx, &ecx, &edx);
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
    __cpuid_call(1, &eax, &ebx, &ecx, &edx);
    ret->stepping_id = eax & 0xf;
    ret->model_id = (eax >> 4) & 0xf;
    ret->brand_id = ebx & 0xff;
    ret->family_id = (eax >> 8) & 0xf;
    ret->processor_type = (eax >> 12) & 0b11;
    ret->extended_model_id = (eax >> 16) & 0xf;
    ret->extended_family_id = (eax >> 20) & 0xff;
    cpuid_get_processor_type_str(ret->processor_type, &(ret->processor_type_str));
    if (strcmp(ret->name, "GenuineIntel") == 0)
    {
        ret->manufacturer_id = cpuid_manufacturer_intel;
        cpuid_get_family_and_model_str(ret, eax);
    }
    else if (strcmp(ret->name, "AuthenticAMD") == 0)
    {
        ret->manufacturer_id = cpuid_manufacturer_amd;
        cpuid_get_family_and_model_str(ret, eax);
    }
    else
    {
        printf("Manufacturer: %" PRIx32 "\n", ebx);
    }
}

char *cpuid_get_processor_type_str(uint32_t type, char **str)
{
    static char *types[4] = {"OEM Processor", "Overdrive Processor", "Dual Processor", "Reserved"};
    *str = types[type];
    return *str;
}

static void __cpuid_call(uint32_t p, uint32_t *eax, uint32_t *ebx, uint32_t *ecx, uint32_t *edx)
{
    uint32_t a;
    uint32_t b;
    uint32_t c;
    uint32_t d;
#ifdef __GNUC__
    __cpuid(p, a, b, c, d);
#else
    __asm {
    mov EAX, 0;
    cpuid;
    mov a, EAX;
    mov b, EBX;
    mov c, ECX;
    mov d, EDX;
    }
#endif // __GNUC__
    if (eax != NULL)
    {
        *eax = a;
    }
    if (ebx != NULL)
    {
        *ebx = b;
    }
    if (ecx != NULL)
    {
        *ecx = c;
    }
    if (edx != NULL)
    {
        *edx = d;
    }
}

int cpuid_get_family_and_model_str(cpuid_t *ret, uint32_t signature)
{
    static char *Intel[] = {"Brand ID Not Supported.", "Intel(R) Celeron(R) processor", "Intel(R) Pentium(R) III processor", "Intel(R) Pentium(R) III Xeon(R) processor", "Intel(R) Pentium(R) III processor", "Reserved", "Mobile Intel(R) Pentium(R) III processor-M", "Mobile Intel(R) Celeron(R) processor", "Intel(R) Pentium(R) 4 processor", "Intel(R) Pentium(R) 4 processor", "Intel(R) Celeron(R) processor", "Intel(R) Xeon(R) Processor", "Intel(R) Xeon(R) processor MP", "Reserved", "Mobile Intel(R) Pentium(R) 4 processor-M", "Mobile Intel(R) Pentium(R) Celeron(R) processor", "Reserved", "Mobile Genuine Intel(R) processor", "Intel(R) Celeron(R) M processor", "Mobile Intel(R) Celeron(R) processor", "Intel(R) Celeron(R) processor", "Mobile Geniune Intel(R) processor", "Intel(R) Pentium(R) M processor", "Mobile Intel(R) Celeron(R) processor"};
    static char *Intel_Other[] = {"Reserved", "Reserved", "Reserved", "Intel(R) Celeron(R) processor", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Intel(R) Xeon(R) processor MP", "Reserved", "Reserved", "Intel(R) Xeon(R) processor", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved", "Reserved"};
    if (ret->manufacturer_id == cpuid_manufacturer_intel)
    {
        ret->manufacturer_str = "Intel";
        switch (ret->family_id)
        {
        case 3:
            ret->family_str = "i386";
            ret->model_str = ret->family_str;
            break;
        case 4:
            ret->family_str = "i486";
            switch (ret->model_id)
            {
            case 0:
            case 1:
                ret->model_str = "DX";
                break;
            case 2:
                ret->model_str = "SX";
                break;
            case 3:
                ret->model_str = "487/DX2";
                break;
            case 4:
                ret->model_str = "SL";
                break;
            case 5:
                ret->model_str = "SX2";
                break;
            case 7:
                ret->model_str = "Write-back enhanced DX2";
                break;
            case 8:
                ret->model_str = "DX4";
                break;
            default:
                ret->model_str = ret->family_str;
                break;
            }
            break;
        case 5:
            ret->family_str = "Pentium";
            switch (ret->model_id)
            {
            case 1:
                ret->model_str = "60/66";
                break;
            case 2:
                ret->model_str = "75-200";
                break;
            case 3:
                ret->model_str = "for 486 system";
                break;
            case 4:
                ret->model_str = "MMX";
                break;
            default:
                ret->model_str = ret->family_str;
                break;
            }
            break;
        case 6:
            ret->family_str = "Pentium Pro";
            switch (ret->model_id)
            {
            case 1:
                ret->model_str = "Pentium Pro";
                break;
            case 3:
                ret->model_str = "Pentium II Model 3";
                break;
            case 5:
                ret->model_str = "Pentium II Model 5/Xeon/Celeron";
                break;
            case 6:
                ret->model_str = "Celeron";
                break;
            case 7:
                ret->model_str = "Pentium III/Pentium III Xeon - external L2 cache";
                break;
            case 8:
                ret->model_str = "Pentium III/Pentium III Xeon - internal L2 cache";
                break;
            default:
                ret->model_str = ret->family_str;
                break;
            }
            break;
        case 15:
            ret->family_str = "Pentium 4";
            ret->model_str = ret->family_str;
            break;
        default:
            ret->family_str = "Not supported";
            ret->model_str = ret->family_str;
            break;
        }
        uint32_t max_eax = 0;
        uint32_t eax;
        uint32_t ebx;
        uint32_t ecx;
        uint32_t edx;
        __cpuid_call(0x80000000, &max_eax, NULL, NULL, NULL);
        if (max_eax >= 0x80000004)
        {
            if (max_eax >= 0x80000002)
            {
                __cpuid_call(0x80000002, &eax, &ebx, &ecx, &edx);
                *(uint32_t *)ret->brand_str = eax;
                *(uint32_t *)(ret->brand_str + 4) = ebx;
                *(uint32_t *)(ret->brand_str + 8) = ecx;
                *(uint32_t *)(ret->brand_str + 12) = edx;
                (ret->brand_str)[16] = ' ';
            }
            if (max_eax >= 0x80000003)
            {
                __cpuid_call(0x80000003, &eax, &ebx, &ecx, &edx);

                *(uint32_t *)(ret->brand_str + 17) = eax;
                *(uint32_t *)(ret->brand_str + 21) = ebx;
                *(uint32_t *)(ret->brand_str + 25) = ecx;
                *(uint32_t *)(ret->brand_str + 29) = edx;

                (ret->brand_str)[33] = ' ';
            }
            if (max_eax >= 0x80000004)
            {
                __cpuid_call(0x80000004, &eax, &ebx, &ecx, &edx);

                *(uint32_t *)(ret->brand_str + 34) = eax;
                *(uint32_t *)(ret->brand_str + 38) = ebx;
                *(uint32_t *)(ret->brand_str + 41) = ecx;
                *(uint32_t *)(ret->brand_str + 45) = edx;

                (ret->brand_str)[49] = '\0';
            }
        }
        else if (ret->brand_id > 0)
        {
            if (ret->brand_id < 0x18)
            {
                if (signature == 0x000006B1 || signature == 0x00000F13)
                {
                    ret->brand_str = Intel_Other[ret->brand_id];
                }
                else
                {
                    ret->brand_str = Intel[ret->brand_id];
                }
            }
            else
            {
                ret->brand_str = "Reserved";
            }
        }
    }
    else
    {
        ret->manufacturer_str = "AMD";
    }
    return 0;
}