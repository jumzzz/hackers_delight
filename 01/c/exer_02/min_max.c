#include <stdio.h>
#include <limits.h>
#include <math.h>

void expected_limits() {
    unsigned long uint_size = 8 * sizeof(unsigned int);
    unsigned long num_values = pow(2, uint_size) - 1;
    
    printf("--------------------------------------------\n");
    printf("Expected Limits: \n");
    printf("--------------------------------------------\n");
    printf("uint_32 (min) = %u, hex = 0x%08X\n", 0, 0);
    printf("uint_32 (max) = %u, hex = 0x%08X\n", UINT_MAX, UINT_MAX);
    printf("sizeof(unsigned int) = %lu\n", uint_size); 
    printf("num_values  = %lu\n", num_values); 
    printf("--------------------------------------------\n");
}

void loop_all() {
    unsigned int start = 0x00000000;
    unsigned int end = 0xFFFFFFFF;
    
    printf("\n");
    printf("--------------------------------------------\n");
    printf("start_result = 0x%08X\n", start);
    printf("expected_end_result = %u, hex = 0x%08X\n", end, end);

    for (; start < end;  start++); 

    printf("end_result = 0x%08X\n", start);
    printf("--------------------------------------------\n");
}

int main() {
    expected_limits();
    loop_all();
    return 0;
}

