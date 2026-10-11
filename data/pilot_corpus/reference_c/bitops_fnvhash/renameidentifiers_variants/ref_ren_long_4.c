#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned cpnrrwdnnbahlfbfirxk[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        cpnrrwdnnbahlfbfirxk[h % 16u]++;
    }
    int yuzsgxqkqwttbsuwlahq = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (cpnrrwdnnbahlfbfirxk[i]) yuzsgxqkqwttbsuwlahq++; if ((int)cpnrrwdnnbahlfbfirxk[i] > maxload) maxload = cpnrrwdnnbahlfbfirxk[i]; }
    printf("%d %d\n", yuzsgxqkqwttbsuwlahq, maxload);
    return 0;
}
