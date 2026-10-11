#include <stdio.h>
static volatile int opq_8cab = 7;
static volatile int opq_8cab_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    if (((opq_8cab * opq_8cab - opq_8cab) % 2 == 0)) { opq_8cab_b ^= 0; }
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_8cab * opq_8cab) % 4) == 2)) {
        { int jv_4c193 = opq_8cab ^ 0xCB80;
            jv_4c193 = (jv_4c193 * 0x26) % 0x7FFFFFFF;
          (void)jv_4c193; }
    }
    int count = 0, last = 0;
    if (((opq_8cab * opq_8cab - opq_8cab) % 2 == 0)) { opq_8cab_b ^= 0; }
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
