#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_42883b[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_42883b[h % 16u]++;
    }
    int v_8de434 = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_42883b[i]) v_8de434++; if ((int)v_42883b[i] > maxload) maxload = v_42883b[i]; }
    printf("%d %d\n", v_8de434, maxload);
    return 0;
}
