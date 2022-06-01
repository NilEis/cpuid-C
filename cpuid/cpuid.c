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

static char *amd_model = NULL;

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
    if (amd_model != NULL)
    {
        free(amd_model);
    }
    free(str->brand_str);
}

int cpuid_get_info(cpuid_t *str)
{
    uint32_t ecx;
    uint32_t edx;
    cpuid_get_features(&ecx, &edx);
    cpuid_get_name(str->name, &(str->highest_basic_calling_parameter));
    cpuid_get_processor_info(str);
    str->sse3 /*         */ = ((ecx & cpuid_feature_ecx_sse3) /*         */ != 0);
    str->pclmulqdq /*    */ = ((ecx & cpuid_feature_ecx_pclmulqdq) /*    */ != 0);
    str->dtes64 /*       */ = ((ecx & cpuid_feature_ecx_dtes64) /*       */ != 0);
    str->monitor /*      */ = ((ecx & cpuid_feature_ecx_monitor) /*      */ != 0);
    str->ds_cpl /*       */ = ((ecx & cpuid_feature_ecx_ds_cpl) /*       */ != 0);
    str->vmx /*          */ = ((ecx & cpuid_feature_ecx_vmx) /*          */ != 0);
    str->smx /*          */ = ((ecx & cpuid_feature_ecx_smx) /*          */ != 0);
    str->est /*          */ = ((ecx & cpuid_feature_ecx_est) /*          */ != 0);
    str->tm2 /*          */ = ((ecx & cpuid_feature_ecx_tm2) /*          */ != 0);
    str->ssse3 /*        */ = ((ecx & cpuid_feature_ecx_ssse3) /*        */ != 0);
    str->cnxt_id /*      */ = ((ecx & cpuid_feature_ecx_cnxt_id) /*      */ != 0);
    str->sdbg /*         */ = ((ecx & cpuid_feature_ecx_sdbg) /*         */ != 0);
    str->fma /*          */ = ((ecx & cpuid_feature_ecx_fma) /*          */ != 0);
    str->cx16 /*         */ = ((ecx & cpuid_feature_ecx_cx16) /*         */ != 0);
    str->xtpr /*         */ = ((ecx & cpuid_feature_ecx_xtpr) /*         */ != 0);
    str->pdcm /*         */ = ((ecx & cpuid_feature_ecx_pdcm) /*         */ != 0);
    str->pcid /*         */ = ((ecx & cpuid_feature_ecx_pcid) /*         */ != 0);
    str->dca /*          */ = ((ecx & cpuid_feature_ecx_dca) /*          */ != 0);
    str->sse4_1 /*       */ = ((ecx & cpuid_feature_ecx_sse4_1) /*       */ != 0);
    str->sse4_2 /*       */ = ((ecx & cpuid_feature_ecx_sse4_2) /*       */ != 0);
    str->x2apic /*       */ = ((ecx & cpuid_feature_ecx_x2apic) /*       */ != 0);
    str->movbe /*        */ = ((ecx & cpuid_feature_ecx_movbe) /*        */ != 0);
    str->popcnt /*       */ = ((ecx & cpuid_feature_ecx_popcnt) /*       */ != 0);
    str->tsc_deadline /* */ = ((ecx & cpuid_feature_ecx_tsc_deadline) /* */ != 0);
    str->aes /*          */ = ((ecx & cpuid_feature_ecx_aes) /*          */ != 0);
    str->xsave /*        */ = ((ecx & cpuid_feature_ecx_xsave) /*        */ != 0);
    str->osxsave /*      */ = ((ecx & cpuid_feature_ecx_osxsave) /*      */ != 0);
    str->avx /*          */ = ((ecx & cpuid_feature_ecx_avx) /*          */ != 0);
    str->f16c /*         */ = ((ecx & cpuid_feature_ecx_f16c) /*         */ != 0);
    str->rdrnd /*        */ = ((ecx & cpuid_feature_ecx_rdrnd) /*        */ != 0);
    str->hypervisor /*   */ = ((ecx & cpuid_feature_ecx_hypervisor) /*   */ != 0);
    str->fpu /*          */ = ((edx & cpuid_feature_edx_fpu) /*          */ != 0);
    str->vme /*          */ = ((edx & cpuid_feature_edx_vme) /*          */ != 0);
    str->de /*           */ = ((edx & cpuid_feature_edx_de) /*           */ != 0);
    str->pse /*          */ = ((edx & cpuid_feature_edx_pse) /*          */ != 0);
    str->tsc /*          */ = ((edx & cpuid_feature_edx_tsc) /*          */ != 0);
    str->msr /*          */ = ((edx & cpuid_feature_edx_msr) /*          */ != 0);
    str->pae /*          */ = ((edx & cpuid_feature_edx_pae) /*          */ != 0);
    str->mce /*          */ = ((edx & cpuid_feature_edx_mce) /*          */ != 0);
    str->cx8 /*          */ = ((edx & cpuid_feature_edx_cx8) /*          */ != 0);
    str->apic /*         */ = ((edx & cpuid_feature_edx_apic) /*         */ != 0);
    str->sep /*          */ = ((edx & cpuid_feature_edx_sep) /*          */ != 0);
    str->mtrr /*         */ = ((edx & cpuid_feature_edx_mtrr) /*         */ != 0);
    str->pge /*          */ = ((edx & cpuid_feature_edx_pge) /*          */ != 0);
    str->mca /*          */ = ((edx & cpuid_feature_edx_mca) /*          */ != 0);
    str->cmov /*         */ = ((edx & cpuid_feature_edx_cmov) /*         */ != 0);
    str->pat /*          */ = ((edx & cpuid_feature_edx_pat) /*          */ != 0);
    str->pse_36 /*       */ = ((edx & cpuid_feature_edx_pse_36) /*       */ != 0);
    str->psn /*          */ = ((edx & cpuid_feature_edx_psn) /*          */ != 0);
    str->clfsh /*        */ = ((edx & cpuid_feature_edx_clfsh) /*        */ != 0);
    str->ds /*           */ = ((edx & cpuid_feature_edx_ds) /*           */ != 0);
    str->acpi /*         */ = ((edx & cpuid_feature_edx_acpi) /*         */ != 0);
    str->mmx /*          */ = ((edx & cpuid_feature_edx_mmx) /*          */ != 0);
    str->fxsr /*         */ = ((edx & cpuid_feature_edx_fxsr) /*         */ != 0);
    str->sse /*          */ = ((edx & cpuid_feature_edx_sse) /*          */ != 0);
    str->sse2 /*         */ = ((edx & cpuid_feature_edx_sse2) /*         */ != 0);
    str->ss /*           */ = ((edx & cpuid_feature_edx_ss) /*           */ != 0);
    str->htt /*          */ = ((edx & cpuid_feature_edx_htt) /*          */ != 0);
    str->tm /*           */ = ((edx & cpuid_feature_edx_tm) /*           */ != 0);
    str->ia64 /*         */ = ((edx & cpuid_feature_edx_ia64) /*         */ != 0);
    str->pbe /*          */ = ((edx & cpuid_feature_edx_pbe) /*          */ != 0);
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

int cpuid_get_processor_info(cpuid_t *ret)
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
    uint32_t eax;
    uint32_t ebx;
    uint32_t ecx;
    uint32_t edx;
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
            }
            if (max_eax >= 0x80000003)
            {
                __cpuid_call(0x80000003, &eax, &ebx, &ecx, &edx);

                *(uint32_t *)(ret->brand_str + 16) = eax;
                *(uint32_t *)(ret->brand_str + 20) = ebx;
                *(uint32_t *)(ret->brand_str + 24) = ecx;
                *(uint32_t *)(ret->brand_str + 28) = edx;
            }
            if (max_eax >= 0x80000004)
            {
                __cpuid_call(0x80000004, &eax, &ebx, &ecx, &edx);

                *(uint32_t *)(ret->brand_str + 33) = eax;
                *(uint32_t *)(ret->brand_str + 37) = ebx;
                *(uint32_t *)(ret->brand_str + 40) = ecx;
                *(uint32_t *)(ret->brand_str + 44) = edx;

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
        amd_model = (char *)calloc(32, sizeof(char));
        switch (ret->family_id)
        {
        case 4:
            ret->family_str = "486 Model";
            sprintf(amd_model, "%" PRIu32, ret->model_id);
            break;
        case 5:
            switch (ret->model_id)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 6:
            case 7:
                ret->family_str = "K6";
                sprintf(amd_model, "%" PRIu32, ret->model_id);
                break;
            case 8:
                ret->family_str = "K6-2";
                sprintf(amd_model, "%" PRIu32, 8);
                break;
            case 9:
                sprintf(amd_model, "%" PRIu32, 9);
                ret->family_str = "K6-III";
                break;
            default:
                ret->family_str = "K5/K6";
                sprintf(amd_model, "%" PRIu32, ret->model_id);
                break;
            }
            break;
        case 6:
            switch (ret->model_id)
            {
            case 1:
            case 2:
            case 4:
                ret->family_str = "Athlon Model";
                sprintf(amd_model, "%" PRIu32, ret->model_id);
                break;
            case 3:
                ret->family_str = "Duron";
                sprintf(amd_model, "%" PRIu32, 3);
                break;
            case 6:
                ret->family_str = "Athlon MP/Mobile Athlon";
                sprintf(amd_model, "%" PRIu32, 6);
                break;
            case 7:
                ret->family_str = "Mobile Duron";
                sprintf(amd_model, "%" PRIu32, 7);
                break;
            default:
                ret->family_str = "Duron/Athlon";
                sprintf(amd_model, "%" PRIu32, ret->model_id);
                break;
            }
            break;
        }
        ret->model_str = amd_model;
        __cpuid_call(0x80000000, &eax, NULL, NULL, NULL);
        if (eax == 0)
        {
            return 0;
        }
        if (eax >= 0x80000002)
        {
            __cpuid_call(0x80000002, &eax, &ebx, &ecx, &edx);
            *(uint32_t *)ret->brand_str = eax;
            *(uint32_t *)(ret->brand_str + 4) = ebx;
            *(uint32_t *)(ret->brand_str + 8) = ecx;
            *(uint32_t *)(ret->brand_str + 12) = edx;
            __cpuid_call(0x80000003, &eax, &ebx, &ecx, &edx);
            *(uint32_t *)(ret->brand_str + 16) = eax;
            *(uint32_t *)(ret->brand_str + 20) = ebx;
            *(uint32_t *)(ret->brand_str + 24) = ecx;
            *(uint32_t *)(ret->brand_str + 28) = edx;
            __cpuid_call(0x80000004, &eax, &ebx, &ecx, &edx);
            *(uint32_t *)(ret->brand_str + 33) = eax;
            *(uint32_t *)(ret->brand_str + 37) = ebx;
            *(uint32_t *)(ret->brand_str + 40) = ecx;
            *(uint32_t *)(ret->brand_str + 44) = edx;
            (ret->brand_str)[49] = '\0';
        }
        if (eax >= 0x80000007)
        {
            __cpuid_call(0x80000007, NULL, NULL, NULL, &edx);
            if (edx & 1)
            {
                printf("Temperature Sensing Diode Detected!\n");
            }
        }
    }
    return 0;
}

void cpuid_get_features(uint32_t *ecx, uint32_t *edx)
{
    __cpuid_call(1, NULL, NULL, ecx, edx);
}