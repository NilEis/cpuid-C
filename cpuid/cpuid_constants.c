#include "cpuid_constants.h"

/****************************************/
/* Source: https://wiki.osdev.org/CPUID */
/****************************************/

/* Vendor strings from CPUs. */
const char *cpuid_vendor_OLDAMD = "AMDisbetter!";
const char *cpuid_vendor_AMD = "AuthenticAMD";
const char *cpuid_vendor_INTEL = "GenuineIntel";
const char *cpuid_vendor_VIA = "VIA VIA VIA ";
const char *cpuid_vendor_OLDTRANSMETA = "TransmetaCPU";
const char *cpuid_vendor_TRANSMETA = "GenuineTMx86";
const char *cpuid_vendor_CYRIX = "CyrixInstead";
const char *cpuid_vendor_CENTAUR = "CentaurHauls";
const char *cpuid_vendor_NEXGEN = "NexGenDriven";
const char *cpuid_vendor_UMC = "UMC UMC UMC ";
const char *cpuid_vendor_SIS = "SiS SiS SiS ";
const char *cpuid_vendor_NSC = "Geode by NSC";
const char *cpuid_vendor_RISE = "RiseRiseRise";
const char *cpuid_vendor_VORTEX = "Vortex86 SoC";
const char *cpuid_vendor_OLDAO486 = "GenuineAO486";
const char *cpuid_vendor_AO486 = "MiSTer AO486";
const char *cpuid_vendor_ZHAOXIN = "  Shanghai  ";
const char *cpuid_vendor_HYGON = "HygonGenuine";
const char *cpuid_vendor_ELBRUS = "E2K MACHINE ";

/* Vendor strings from hypervisors. */
const char *cpuid_vendor_QEMU = "TCGTCGTCGTCG";
const char *cpuid_vendor_KVM = " KVMKVMKVM  ";
const char *cpuid_vendor_VMWARE = "VMwareVMware";
const char *cpuid_vendor_VIRTUALBOX = "VBoxVBoxVBox";
const char *cpuid_vendor_XEN = "XenVMMXenVMM";
const char *cpuid_vendor_HYPERV = "Microsoft Hv";
const char *cpuid_vendor_PARALLELS = " prl hyperv ";
const char *cpuid_vendor_PARALLELS_ALT = " lrpepyh vr ";
const char *cpuid_vendor_BHYVE = "bhyve bhyve ";
const char *cpuid_vendor_QNX = " QNXQVMBSQG ";

uint32_t cpuid_feature_ecx_sse3 = (uint32_t)1 << 0;
uint32_t cpuid_feature_ecx_pclmulqdq = (uint32_t)1 << 1;
uint32_t cpuid_feature_ecx_dtes64 = (uint32_t)1 << 2;
uint32_t cpuid_feature_ecx_monitor = (uint32_t)1 << 3;
uint32_t cpuid_feature_ecx_ds_cpl = (uint32_t)1 << 4;
uint32_t cpuid_feature_ecx_vmx = (uint32_t)1 << 5;
uint32_t cpuid_feature_ecx_smx = (uint32_t)1 << 6;
uint32_t cpuid_feature_ecx_est = (uint32_t)1 << 7;
uint32_t cpuid_feature_ecx_tm2 = (uint32_t)1 << 8;
uint32_t cpuid_feature_ecx_ssse3 = (uint32_t)1 << 9;
uint32_t cpuid_feature_ecx_cnxt_id = (uint32_t)1 << 10;
uint32_t cpuid_feature_ecx_sdbg = (uint32_t)1 << 11;
uint32_t cpuid_feature_ecx_fma = (uint32_t)1 << 12;
uint32_t cpuid_feature_ecx_cx16 = (uint32_t)1 << 13;
uint32_t cpuid_feature_ecx_xtpr = (uint32_t)1 << 14;
uint32_t cpuid_feature_ecx_pdcm = (uint32_t)1 << 15;
uint32_t cpuid_feature_ecx_pcid = (uint32_t)1 << 17;
uint32_t cpuid_feature_ecx_dca = (uint32_t)1 << 18;
uint32_t cpuid_feature_ecx_sse4_1 = (uint32_t)1 << 19;
uint32_t cpuid_feature_ecx_sse4_2 = (uint32_t)1 << 20;
uint32_t cpuid_feature_ecx_x2apic = (uint32_t)1 << 21;
uint32_t cpuid_feature_ecx_movbe = (uint32_t)1 << 22;
uint32_t cpuid_feature_ecx_popcnt = (uint32_t)1 << 23;
uint32_t cpuid_feature_ecx_tsc_deadline = (uint32_t)1 << 24;
uint32_t cpuid_feature_ecx_aes = (uint32_t)1 << 25;
uint32_t cpuid_feature_ecx_xsave = (uint32_t)1 << 26;
uint32_t cpuid_feature_ecx_osxsave = (uint32_t)1 << 27;
uint32_t cpuid_feature_ecx_avx = (uint32_t)1 << 28;
uint32_t cpuid_feature_ecx_f16c = (uint32_t)1 << 29;
uint32_t cpuid_feature_ecx_rdrnd = (uint32_t)1 << 30;
uint32_t cpuid_feature_ecx_hypervisor = (uint32_t)1 << 31;
uint32_t cpuid_feature_edx_fpu = (uint32_t)1 << 0;
uint32_t cpuid_feature_edx_vme = (uint32_t)1 << 1;
uint32_t cpuid_feature_edx_de = (uint32_t)1 << 2;
uint32_t cpuid_feature_edx_pse = (uint32_t)1 << 3;
uint32_t cpuid_feature_edx_tsc = (uint32_t)1 << 4;
uint32_t cpuid_feature_edx_msr = (uint32_t)1 << 5;
uint32_t cpuid_feature_edx_pae = (uint32_t)1 << 6;
uint32_t cpuid_feature_edx_mce = (uint32_t)1 << 7;
uint32_t cpuid_feature_edx_cx8 = (uint32_t)1 << 8;
uint32_t cpuid_feature_edx_apic = (uint32_t)1 << 9;
uint32_t cpuid_feature_edx_sep = (uint32_t)1 << 11;
uint32_t cpuid_feature_edx_mtrr = (uint32_t)1 << 12;
uint32_t cpuid_feature_edx_pge = (uint32_t)1 << 13;
uint32_t cpuid_feature_edx_mca = (uint32_t)1 << 14;
uint32_t cpuid_feature_edx_cmov = (uint32_t)1 << 15;
uint32_t cpuid_feature_edx_pat = (uint32_t)1 << 16;
uint32_t cpuid_feature_edx_pse_36 = (uint32_t)1 << 17;
uint32_t cpuid_feature_edx_psn = (uint32_t)1 << 18;
uint32_t cpuid_feature_edx_clfsh = (uint32_t)1 << 19;
uint32_t cpuid_feature_edx_ds = (uint32_t)1 << 21;
uint32_t cpuid_feature_edx_acpi = (uint32_t)1 << 22;
uint32_t cpuid_feature_edx_mmx = (uint32_t)1 << 23;
uint32_t cpuid_feature_edx_fxsr = (uint32_t)1 << 24;
uint32_t cpuid_feature_edx_sse = (uint32_t)1 << 25;
uint32_t cpuid_feature_edx_sse2 = (uint32_t)1 << 26;
uint32_t cpuid_feature_edx_ss = (uint32_t)1 << 27;
uint32_t cpuid_feature_edx_htt = (uint32_t)1 << 28;
uint32_t cpuid_feature_edx_tm = (uint32_t)1 << 29;
uint32_t cpuid_feature_edx_ia64 = (uint32_t)1 << 30;
uint32_t cpuid_feature_edx_pbe = (uint32_t)1 << 31;
