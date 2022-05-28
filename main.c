#include <stdio.h>
#include "cpu_id.h"

int main(int argc, char **argv)
{
    printf("main\n");
    get_cpuid();
    return 0;
}
