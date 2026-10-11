#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_bccfcc[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_bccfcc[h % 16u]++;
    }
    int v_d02ded = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_bccfcc[i]) v_d02ded++; if ((int)v_bccfcc[i] > maxload) maxload = v_bccfcc[i]; }
    printf("%d %d\n", v_d02ded, maxload);
    return 0;
}
