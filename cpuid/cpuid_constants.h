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

/* Vendor strings from CPUs. */
extern const char *cpuid_vendor_INTEL;          /* Intel */
extern const char *cpuid_vendor_OLDAMD;         /* AMD */
extern const char *cpuid_vendor_AMD;          
extern const char *cpuid_vendor_NEXGEN;         /* NexGen (1996 bought by AMD) */
extern const char *cpuid_vendor_VIA;            /* VIA Technologies, Inc. */
extern const char *cpuid_vendor_OLDTRANSMETA;   /* Transmeta (2009 dissolved) */
extern const char *cpuid_vendor_TRANSMETA;    
extern const char *cpuid_vendor_CYRIX;          /* Cyrix (1997 dissolved) */
extern const char *cpuid_vendor_CENTAUR;        /* Centaur Technology */
extern const char *cpuid_vendor_UMC;            /* United Microelectronics Corporation (UMC) */
extern const char *cpuid_vendor_SIS;            /* Silicon Integrated Systems (SIS) */
extern const char *cpuid_vendor_RISE;           /* Rise Technology (1999 bought by SIS)*/
extern const char *cpuid_vendor_VORTEX;       
extern const char *cpuid_vendor_NSC;            /* National Semiconductor (2011 bought by Texas Instruments) */
extern const char *cpuid_vendor_OLDAO486;       /* https://github.com/alfikpl/ao486 */
extern const char *cpuid_vendor_AO486;        
extern const char *cpuid_vendor_ZHAOXIN;        /* Shanghai Zhaoxin Semiconductor Co., Ltd. */
extern const char *cpuid_vendor_HYGON;          /* Tianjin Haiguang Advanced Technology Investment Co. Ltd. (Is this right the right name?) */
extern const char *cpuid_vendor_ELBRUS;         /* Moscow Center of SPARC Technologies */

/* Vendor strings from hypervisors. */
extern const char *cpuid_vendor_QEMU;           /* Qemu */
extern const char *cpuid_vendor_KVM;            /* Kernel-based VM */
extern const char *cpuid_vendor_VMWARE;         /* VMware, Inc. */
extern const char *cpuid_vendor_VIRTUALBOX;     /* Virtualbox */
extern const char *cpuid_vendor_XEN;            /* Xen project */
extern const char *cpuid_vendor_HYPERV;         /* Microsoft Corporation */
extern const char *cpuid_vendor_PARALLELS;      /* Corel (I think) */
extern const char *cpuid_vendor_PARALLELS_ALT;
extern const char *cpuid_vendor_BHYVE;          /* FreeBSD */
extern const char *cpuid_vendor_QNX;            /* Blackberry Limited */

// Non-integer enums are not iso compliant :(
extern uint32_t cpuid_feature_ecx_sse3;
extern uint32_t cpuid_feature_ecx_pclmulqdq;
extern uint32_t cpuid_feature_ecx_dtes64;
extern uint32_t cpuid_feature_ecx_monitor;
extern uint32_t cpuid_feature_ecx_ds_cpl;
extern uint32_t cpuid_feature_ecx_vmx;
extern uint32_t cpuid_feature_ecx_smx;
extern uint32_t cpuid_feature_ecx_est;
extern uint32_t cpuid_feature_ecx_tm2;
extern uint32_t cpuid_feature_ecx_ssse3;
extern uint32_t cpuid_feature_ecx_cnxt_id;
extern uint32_t cpuid_feature_ecx_sdbg;
extern uint32_t cpuid_feature_ecx_fma;
extern uint32_t cpuid_feature_ecx_cx16;
extern uint32_t cpuid_feature_ecx_xtpr;
extern uint32_t cpuid_feature_ecx_pdcm;
extern uint32_t cpuid_feature_ecx_pcid;
extern uint32_t cpuid_feature_ecx_dca;
extern uint32_t cpuid_feature_ecx_sse4_1;
extern uint32_t cpuid_feature_ecx_sse4_2;
extern uint32_t cpuid_feature_ecx_x2apic;
extern uint32_t cpuid_feature_ecx_movbe;
extern uint32_t cpuid_feature_ecx_popcnt;
extern uint32_t cpuid_feature_ecx_tsc_deadline;
extern uint32_t cpuid_feature_ecx_aes;
extern uint32_t cpuid_feature_ecx_xsave;
extern uint32_t cpuid_feature_ecx_osxsave;
extern uint32_t cpuid_feature_ecx_avx;
extern uint32_t cpuid_feature_ecx_f16c;
extern uint32_t cpuid_feature_ecx_rdrnd;
extern uint32_t cpuid_feature_ecx_hypervisor;
extern uint32_t cpuid_feature_edx_fpu;
extern uint32_t cpuid_feature_edx_vme;
extern uint32_t cpuid_feature_edx_de;
extern uint32_t cpuid_feature_edx_pse;
extern uint32_t cpuid_feature_edx_tsc;
extern uint32_t cpuid_feature_edx_msr;
extern uint32_t cpuid_feature_edx_pae;
extern uint32_t cpuid_feature_edx_mce;
extern uint32_t cpuid_feature_edx_cx8;
extern uint32_t cpuid_feature_edx_apic;
extern uint32_t cpuid_feature_edx_sep;
extern uint32_t cpuid_feature_edx_mtrr;
extern uint32_t cpuid_feature_edx_pge;
extern uint32_t cpuid_feature_edx_mca;
extern uint32_t cpuid_feature_edx_cmov;
extern uint32_t cpuid_feature_edx_pat;
extern uint32_t cpuid_feature_edx_pse_36;
extern uint32_t cpuid_feature_edx_psn;
extern uint32_t cpuid_feature_edx_clfsh;
extern uint32_t cpuid_feature_edx_ds;
extern uint32_t cpuid_feature_edx_acpi;
extern uint32_t cpuid_feature_edx_mmx;
extern uint32_t cpuid_feature_edx_fxsr;
extern uint32_t cpuid_feature_edx_sse;
extern uint32_t cpuid_feature_edx_sse2;
extern uint32_t cpuid_feature_edx_ss;
extern uint32_t cpuid_feature_edx_htt;
extern uint32_t cpuid_feature_edx_tm;
extern uint32_t cpuid_feature_edx_ia64;
extern uint32_t cpuid_feature_edx_pbe;

typedef enum
{
    cpuid_manufacturer_intel,
    cpuid_manufacturer_amd
} cpuid_manufacturer_t;

#endif // CPUID_CONSTANTS_H
