#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x4E768B82 ^ 0x4E768B82); while (v) { c += v & (0x4B9C6BD3u ^ 0x4B9C6BD2u); v >>= (0x2F1222FB ^ 0x2F1222FA); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x10BBEF33 ^ 0x10BBEF33); while (v) { v &= v - (0x42792E68u ^ 0x42792E69u); c++; } return c; }
int main(void) {
    long a = (0x62334FF1 ^ 0x62334FF1), b = (0x682788BA ^ 0x682788BA);
    for (unsigned i = (0x4B390EA3 ^ 0x4B390EA3); i < (0x1EBC6FC3 ^ 0x1EBC7FC3); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x6D5C36E4u ^ 0x6D5C36E3u) + (0x54ED5C6u ^ 0x54ED5C5u)); }
    printf("%ld %ld\n", a, b);
    return (0x6762DAC0 ^ 0x6762DAC0);
}
