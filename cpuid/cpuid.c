#include "cpu_id.h"
#ifdef __GNUC__
#include <cpuid.h>
#else
#include <intrin.h>
#endif // __GNUC__

int get_cpuid(cpuid_t *str)
{
    unsigned int InfoType = 0;
    unsigned int a, b, c, d;
#ifdef __GNUC__
#else
#endif // __GNUC__
}
