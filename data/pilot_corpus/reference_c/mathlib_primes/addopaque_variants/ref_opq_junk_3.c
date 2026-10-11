#include <stdio.h>
static volatile int opq_e72c = 7;
static volatile int opq_e72c_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_e72c * opq_e72c) % 4) == 2)) {
        { int jv_62d89 = opq_e72c ^ 0xE478;
            jv_62d89 = (jv_62d89 * 0x1C) % 0x7FFFFFFF;
          (void)jv_62d89; }
    }
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    if ((((opq_e72c * opq_e72c) % 4) == 2)) {
        { int jv_b805d = opq_e72c ^ 0x67AE;
            jv_b805d += (jv_b805d >> 2) + 0x6E;
            jv_b805d = (jv_b805d * 0x10) % 0x7FFFFFFF;
          (void)jv_b805d; }
    }
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_e72c * opq_e72c + opq_e72c_b * opq_e72c_b) % 4) == 3)) {
        { int jv_620ad = opq_e72c ^ 0xCD96;
            jv_620ad = (jv_620ad * 0x24) % 0x7FFFFFFF;
            jv_620ad += (jv_620ad >> 2) + 0xF3;
          (void)jv_620ad; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
