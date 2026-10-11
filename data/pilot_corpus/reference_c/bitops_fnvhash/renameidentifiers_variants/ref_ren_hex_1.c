#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_c5ae3c[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_c5ae3c[h % 16u]++;
    }
    int v_4552ae = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_c5ae3c[i]) v_4552ae++; if ((int)v_c5ae3c[i] > maxload) maxload = v_c5ae3c[i]; }
    printf("%d %d\n", v_4552ae, maxload);
    return 0;
}
