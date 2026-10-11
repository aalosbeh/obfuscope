#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned hmmesnlmzwghnt[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        hmmesnlmzwghnt[h % 16u]++;
    }
    int pkukssopczdhho = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (hmmesnlmzwghnt[i]) pkukssopczdhho++; if ((int)hmmesnlmzwghnt[i] > maxload) maxload = hmmesnlmzwghnt[i]; }
    printf("%d %d\n", pkukssopczdhho, maxload);
    return 0;
}
