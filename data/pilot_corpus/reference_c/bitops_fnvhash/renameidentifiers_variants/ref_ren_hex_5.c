#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_1a04ae[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_1a04ae[h % 16u]++;
    }
    int v_d1a72e = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_1a04ae[i]) v_d1a72e++; if ((int)v_1a04ae[i] > maxload) maxload = v_1a04ae[i]; }
    printf("%d %d\n", v_d1a72e, maxload);
    return 0;
}
