#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned nytcesstgdcauepi[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        nytcesstgdcauepi[h % 16u]++;
    }
    int exxutorbakrheuecmuwutb = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (nytcesstgdcauepi[i]) exxutorbakrheuecmuwutb++; if ((int)nytcesstgdcauepi[i] > maxload) maxload = nytcesstgdcauepi[i]; }
    printf("%d %d\n", exxutorbakrheuecmuwutb, maxload);
    return 0;
}
