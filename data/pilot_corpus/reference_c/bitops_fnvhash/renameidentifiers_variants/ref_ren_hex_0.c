#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_9fb0b3[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_9fb0b3[h % 16u]++;
    }
    int v_4dae66 = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_9fb0b3[i]) v_4dae66++; if ((int)v_9fb0b3[i] > maxload) maxload = v_9fb0b3[i]; }
    printf("%d %d\n", v_4dae66, maxload);
    return 0;
}
