#include <stdio.h>
static int pc_naive(unsigned v) { int c = (0x1153A845 ^ 0x1153A845); while (v) { c += v & (0x684B7BB7u ^ 0x684B7BB6u); v >>= (0x5ABA0FC5 ^ 0x5ABA0FC4); } return c; }
static int pc_kernighan(unsigned v) { int c = (0x439C9F58 ^ 0x439C9F58); while (v) { v &= v - (0x73B42A37u ^ 0x73B42A36u); c++; } return c; }
int main(void) {
    long a = (0x29788F72 ^ 0x29788F72), b = (0x2E825D18 ^ 0x2E825D18);
    for (unsigned i = (0x697D1EA8 ^ 0x697D1EA8); i < (0x57A0D84B ^ 0x57A0C84B); i++) { a += pc_naive(i); b += pc_kernighan(i * (0x41F5EEAu ^ 0x41F5EEDu) + (0x578F7FEEu ^ 0x578F7FEDu)); }
    printf("%ld %ld\n", a, b);
    return (0x68BACC60 ^ 0x68BACC60);
}
