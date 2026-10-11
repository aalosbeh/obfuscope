#include <stdio.h>
static volatile int opq_6ddb = 7;
static volatile int opq_6ddb_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_6ddb * (opq_6ddb + 1)) % 2) == 0)) { opq_6ddb_b ^= 0; }
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_6ddb * (opq_6ddb + 1)) % 2) == 0)) { opq_6ddb_b ^= 0; }
    int count = 0, last = 0;
    if ((((opq_6ddb * opq_6ddb + opq_6ddb_b * opq_6ddb_b) % 4) == 3)) {
        { int jv_dd7f9 = opq_6ddb ^ 0x4A94;
            jv_dd7f9 ^= (jv_dd7f9 << 3) | 0x6005;
            jv_dd7f9 = (jv_dd7f9 * 0x26) % 0x7FFFFFFF;
            jv_dd7f9 += (jv_dd7f9 >> 2) + 0xDE;
          (void)jv_dd7f9; }
    }
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
