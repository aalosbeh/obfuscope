#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned uojncudtoquiawalathbf[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        uojncudtoquiawalathbf[h % 16u]++;
    }
    int mbnrufwiixduiynozsjm = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (uojncudtoquiawalathbf[i]) mbnrufwiixduiynozsjm++; if ((int)uojncudtoquiawalathbf[i] > maxload) maxload = uojncudtoquiawalathbf[i]; }
    printf("%d %d\n", mbnrufwiixduiynozsjm, maxload);
    return 0;
}
