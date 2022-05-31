#include <stdio.h>
#include <inttypes.h>
#include "cpu_id.h"

int main(void)
{
    cpuid_t str;
    cpuid_init_struct(&str);
    cpuid_get_info(&str);
    printf("%s\nHighest basic calling parameter: %" PRIu32 " -> 0x%" PRIx32 "\n", str.name, str.highest_basic_calling_parameter, str.highest_basic_calling_parameter);
    printf("Type: %s\n", str.processor_type_str);
    printf("Manufacturer: %s\n", str.manufacturer_str);
    printf("Family: %s\n", str.family_str);
    printf("Model: %s\n", str.model_str);
    printf("Brand: %s\n", str.brand_str);
    cpuid_free_struct(&str);
    printf("Press Enter to exit...\n");
    while (getchar() != '\n')
        ;
    return 0;
}