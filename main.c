#include <stdio.h>
#include <inttypes.h>
#include "cpu_id.h"

int main(void)
{
    cpuid_t str;
    static const char true_str[] = "true";
    static const char false_str[] = "false";
    printf("Compiled on "__DATE__
           " at "__TIME__
           " with gcc-version "__VERSION__
           "\n");
    cpuid_init_struct(&str);
    cpuid_get_info(&str);
    printf("%s\nHighest basic calling parameter: %" PRIu32 " -> 0x%" PRIx32 "\n", str.name, str.highest_basic_calling_parameter, str.highest_basic_calling_parameter);
    printf("Type: %s\n", str.processor_type_str);
    printf("Manufacturer: %s\n", str.manufacturer_str);
    printf("Family: %s\n", str.family_str);
    printf("Model: %s\n", str.model_str);
    printf("Brand: %s\n", str.brand_str);
    printf("Prescott New Instructions-SSE3 (PNI) supported:                          %s\n", str.sse3 != 0 ? true_str : false_str);
    printf("PCLMULQDQ supported:                                                     %s\n", str.pclmulqdq != 0 ? true_str : false_str);
    printf("64-bit debug store (edx bit 21) supported:                               %s\n", str.dtes64 != 0 ? true_str : false_str);
    printf("MONITOR and MWAIT instructions (SSE3) supported:                         %s\n", str.monitor != 0 ? true_str : false_str);
    printf("CPL qualified debug store supported:                                     %s\n", str.ds_cpl != 0 ? true_str : false_str);
    printf("Virtual Machine eXtensions supported:                                    %s\n", str.vmx != 0 ? true_str : false_str);
    printf("Safer Mode Extensions (LaGrande) supported:                              %s\n", str.smx != 0 ? true_str : false_str);
    printf("Enhanced SpeedStep supported:                                            %s\n", str.est != 0 ? true_str : false_str);
    printf("Thermal Monitor 2 supported:                                             %s\n", str.tm2 != 0 ? true_str : false_str);
    printf("Supplemental SSE3 instructions supported:                                %s\n", str.ssse3 != 0 ? true_str : false_str);
    printf("L1 Context ID supported:                                                 %s\n", str.cnxt_id != 0 ? true_str : false_str);
    printf("Silicon Debug interface supported:                                       %s\n", str.sdbg != 0 ? true_str : false_str);
    printf("Fused multiply-add (FMA3) supported:                                     %s\n", str.fma != 0 ? true_str : false_str);
    printf("CMPXCHG16B instruction supported:                                        %s\n", str.cx16 != 0 ? true_str : false_str);
    printf("Can disable sending task priority messages supported:                    %s\n", str.xtpr != 0 ? true_str : false_str);
    printf("Perfmon & debug capability supported:                                    %s\n", str.pdcm != 0 ? true_str : false_str);
    printf("Process context identifiers (CR4 bit 17) supported:                      %s\n", str.pcid != 0 ? true_str : false_str);
    printf("Direct cache access for DMA writes supported:                            %s\n", str.dca != 0 ? true_str : false_str);
    printf("SSE4.1 instructions supported:                                           %s\n", str.sse4_1 != 0 ? true_str : false_str);
    printf("SSE4.2 instructions supported:                                           %s\n", str.sse4_2 != 0 ? true_str : false_str);
    printf("x2APIC supported:                                                        %s\n", str.x2apic != 0 ? true_str : false_str);
    printf("MOVBE instruction (big-endian) supported:                                %s\n", str.movbe != 0 ? true_str : false_str);
    printf("POPCNT instruction supported:                                            %s\n", str.popcnt != 0 ? true_str : false_str);
    printf("APIC implements one-shot operation using a TSC deadline value supported: %s\n", str.tsc_deadline != 0 ? true_str : false_str);
    printf("AES instruction set supported:                                           %s\n", str.aes != 0 ? true_str : false_str);
    printf("XSAVE, XRESTOR, XSETBV, XGETBV supported:                                %s\n", str.xsave != 0 ? true_str : false_str);
    printf("XSAVE enabled by OS supported:                                           %s\n", str.osxsave != 0 ? true_str : false_str);
    printf("Advanced Vector Extensions supported:                                    %s\n", str.avx != 0 ? true_str : false_str);
    printf("F16C (half-precision) FP feature supported:                              %s\n", str.f16c != 0 ? true_str : false_str);
    printf("RDRAND (on-chip random number generator) feature supported:              %s\n", str.rdrnd != 0 ? true_str : false_str);
    printf("Hypervisor present (always zero on physical CPUs) supported:             %s\n", str.hypervisor != 0 ? true_str : false_str);
    printf("Onboard x87 FPU supported:                                               %s\n", str.fpu != 0 ? true_str : false_str);
    printf("Virtual 8086 mode extensions (such as VIF, VIP, PIV) supported:          %s\n", str.vme != 0 ? true_str : false_str);
    printf("Debugging extensions (CR4 bit 3) supported:                              %s\n", str.de != 0 ? true_str : false_str);
    printf("Page Size Extension supported:                                           %s\n", str.pse != 0 ? true_str : false_str);
    printf("Time Stamp Counter supported:                                            %s\n", str.tsc != 0 ? true_str : false_str);
    printf("Model-specific registers supported:                                      %s\n", str.msr != 0 ? true_str : false_str);
    printf("Physical Address Extension supported:                                    %s\n", str.pae != 0 ? true_str : false_str);
    printf("Machine Check Exception supported:                                       %s\n", str.mce != 0 ? true_str : false_str);
    printf("CMPXCHG8 (compare-and-swap) instruction supported:                       %s\n", str.cx8 != 0 ? true_str : false_str);
    printf("Onboard Advanced Programmable Interrupt Controller supported:            %s\n", str.apic != 0 ? true_str : false_str);
    printf("SYSENTER and SYSEXIT instructions supported:                             %s\n", str.sep != 0 ? true_str : false_str);
    printf("Memory Type Range Registers supported:                                   %s\n", str.mtrr != 0 ? true_str : false_str);
    printf("Page Global Enable bit in CR4 supported:                                 %s\n", str.pge != 0 ? true_str : false_str);
    printf("Machine check architecture supported:                                    %s\n", str.mca != 0 ? true_str : false_str);
    printf("Conditional move and FCMOV instructions supported:                       %s\n", str.cmov != 0 ? true_str : false_str);
    printf("Page Attribute Table supported:                                          %s\n", str.pat != 0 ? true_str : false_str);
    printf("36-bit page size extension supported:                                    %s\n", str.pse_36 != 0 ? true_str : false_str);
    printf("Processor Serial Number supported:                                       %s\n", str.psn != 0 ? true_str : false_str);
    printf("CLFLUSH instruction (SSE2) supported:                                    %s\n", str.clfsh != 0 ? true_str : false_str);
    printf("Debug store: save trace of executed jumps supported:                     %s\n", str.ds != 0 ? true_str : false_str);
    printf("Onboard thermal control MSRs for ACPI supported:                         %s\n", str.acpi != 0 ? true_str : false_str);
    printf("MMX instructions supported:                                              %s\n", str.mmx != 0 ? true_str : false_str);
    printf("FXSAVE, FXRESTOR instructions, CR4 bit 9 supported:                      %s\n", str.fxsr != 0 ? true_str : false_str);
    printf("SSE instructions (a.k.a. Katmai New Instructions) supported:             %s\n", str.sse != 0 ? true_str : false_str);
    printf("SSE2 instructions supported:                                             %s\n", str.sse2 != 0 ? true_str : false_str);
    printf("CPU cache implements self-snoop supported:                               %s\n", str.ss != 0 ? true_str : false_str);
    printf("Hyper-threading supported:                                               %s\n", str.htt != 0 ? true_str : false_str);
    printf("Thermal monitor automatically limits temperature supported:              %s\n", str.tm != 0 ? true_str : false_str);
    printf("IA64 processor emulating x86 supported:                                  %s\n", str.ia64 != 0 ? true_str : false_str);
    printf("Pending Break Enable (PBE# pin) wakeup capability supported:             %s\n", str.pbe != 0 ? true_str : false_str);
    cpuid_free_struct(&str);
    printf("Press Enter to exit...\n");
    while (getchar() != '\n')
        ;
    return 0;
}