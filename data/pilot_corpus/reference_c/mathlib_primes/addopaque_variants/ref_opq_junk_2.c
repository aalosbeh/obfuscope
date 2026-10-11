#include <stdio.h>
static volatile int opq_ab87 = 7;
static volatile int opq_ab87_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    if ((((opq_ab87 * opq_ab87 + opq_ab87_b * opq_ab87_b) % 4) == 3)) {
        { int jv_91adb = opq_ab87 ^ 0x858C;
            jv_91adb ^= (jv_91adb << 3) | 0x7A7A;
            jv_91adb += (jv_91adb >> 2) + 0xF9;
            jv_91adb = (jv_91adb * 0x6) % 0x7FFFFFFF;
          (void)jv_91adb; }
    }
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_ab87 * opq_ab87) % 4) == 2)) {
        { int jv_817ae = opq_ab87 ^ 0x734D;
            jv_817ae = (jv_817ae * 0xB) % 0x7FFFFFFF;
            jv_817ae ^= (jv_817ae << 3) | 0x8CFE;
          (void)jv_817ae; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if ((((opq_ab87 * opq_ab87) % 4) == 2)) {
        { int jv_a6d64 = opq_ab87 ^ 0x98B4;
            jv_a6d64 += (jv_a6d64 >> 2) + 0xA4;
            jv_a6d64 = (jv_a6d64 * 0x2D) % 0x7FFFFFFF;
            jv_a6d64 ^= (jv_a6d64 << 3) | 0x913C;
          (void)jv_a6d64; }
    }
    return 0;
}
