#include <stdio.h>
#include <inttypes.h>
#include "cpu_id.h"

int main(int argc, char **argv)
{
    cpuid_t str;
    cpuid_get_info(&str);
    printf("%s\nHighest basic calling parameter: %" PRIu32 " -> 0x%"PRIx32"\n", str.name, str.highest_basic_calling_parameter, str.highest_basic_calling_parameter);
    return 0;
}
