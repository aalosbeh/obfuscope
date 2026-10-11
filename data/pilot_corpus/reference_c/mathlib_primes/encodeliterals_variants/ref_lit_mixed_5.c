#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x894 - 0x894); i < LIM; i++) sieve[i] = (0xABE - 0xABD);
    sieve[(0x7159D27E ^ 0x7159D27E)] = sieve[(0xDF5 - 0xDF4)] = (0x7FB - 0x7FB);
    for (int i = (0x9BF6423 ^ 0x9BF6421); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x81F - 0x81F);
    int count = (0xAAFCB5 ^ 0xAAFCB5), last = (0xBBC - 0xBBC);
    for (int i = (0x51A8B19A ^ 0x51A8B19A); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0xB45 - 0xB45);
}
