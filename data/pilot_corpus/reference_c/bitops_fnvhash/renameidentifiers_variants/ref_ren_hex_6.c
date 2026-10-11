#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_320af5[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_320af5[h % 16u]++;
    }
    int v_a2a4bc = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_320af5[i]) v_a2a4bc++; if ((int)v_320af5[i] > maxload) maxload = v_320af5[i]; }
    printf("%d %d\n", v_a2a4bc, maxload);
    return 0;
}
