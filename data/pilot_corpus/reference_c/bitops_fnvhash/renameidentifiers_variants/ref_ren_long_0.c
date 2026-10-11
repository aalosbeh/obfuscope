#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned qpljxligtqtrmzncctt[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        qpljxligtqtrmzncctt[h % 16u]++;
    }
    int obkfglultgsowftqhvba = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (qpljxligtqtrmzncctt[i]) obkfglultgsowftqhvba++; if ((int)qpljxligtqtrmzncctt[i] > maxload) maxload = qpljxligtqtrmzncctt[i]; }
    printf("%d %d\n", obkfglultgsowftqhvba, maxload);
    return 0;
}
