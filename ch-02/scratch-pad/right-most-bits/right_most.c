#include <stdio.h>
#include "bit_utils.h"


typedef unsigned int uint32;
typedef void const* const const_void_ptr;
typedef char* char_ptr;
typedef size_t const const_size_t;

void print_ops_bits(
        char_ptr ops,
        const_void_ptr lhs_ptr, 
        const_void_ptr rhs_ptr,
        const_void_ptr res_ptr,
        const_size_t lhs_size,
        const_size_t rhs_size,
        const_size_t res_size) {

    printf("------------------------------------\n");
    print_bits("   ", lhs_ptr, lhs_size);
    print_bits(ops, rhs_ptr, rhs_size); 
    print_bits(" = ", res_ptr, res_size);
    printf("------------------------------------\n\n");
}

/*
   Use the following formula to turn off the rightmost 1-bit in a word, producing 
   0 if none (e.g., 01011000  01010000):
   
   Formula:
        x & (x - 1)
*/
uint32 off_rightmost(uint32 lhs) {
    uint32 rhs = lhs - 1;
    uint32 res = lhs & rhs;
    printf("------------------------------------\n");
    printf("off_rightmost(%u)\n", lhs);
    print_ops_bits(" & ", &lhs, &rhs, &res, sizeof(lhs), sizeof(rhs), sizeof(res));  
    return res;
}

/*
   Use the following formula to turn on the rightmost 1-bit in a word, producing 
   0 if none (e.g., 10100111  10101111): 
   
   Formula:
        x | (x + 1)
*/
uint32 on_rightmost(uint32 lhs) {
    uint32 rhs = lhs + 1;
    uint32 res = lhs | rhs;
    printf("------------------------------------\n");
    printf("on_rightmost(%u)\n", lhs);
    print_ops_bits(" | ", &lhs, &rhs, &res, sizeof(lhs), sizeof(rhs), sizeof(res));  
    return res;
}

int main(int argc, char* argv[]) {
    uint32 off_n0 = 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1;
    
    uint32 off_n1 = off_rightmost(off_n0);
    uint32 off_n2 = off_rightmost(off_n1);
    uint32 off_n3 = off_rightmost(off_n2);
    uint32 off_n4 = off_rightmost(off_n3);
    uint32 off_n5 = off_rightmost(off_n4);
    uint32 off_n6 = off_rightmost(off_n5);
    uint32 off_n7 = off_rightmost(off_n6);
    
    uint32 on_n1 = on_rightmost(off_n7);
    uint32 on_n2 = on_rightmost(off_n1);
    uint32 on_n3 = on_rightmost(off_n2);
    uint32 on_n4 = on_rightmost(off_n3);
    uint32 on_n5 = on_rightmost(off_n4);
    uint32 on_n6 = on_rightmost(off_n5);
    uint32 on_n7 = on_rightmost(off_n6);

    return 0;
}
