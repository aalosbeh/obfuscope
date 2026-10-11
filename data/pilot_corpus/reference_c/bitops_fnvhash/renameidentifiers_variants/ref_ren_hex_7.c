#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_89a0a9[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_89a0a9[h % 16u]++;
    }
    int v_e9c6d2 = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_89a0a9[i]) v_e9c6d2++; if ((int)v_89a0a9[i] > maxload) maxload = v_89a0a9[i]; }
    printf("%d %d\n", v_e9c6d2, maxload);
    return 0;
}
