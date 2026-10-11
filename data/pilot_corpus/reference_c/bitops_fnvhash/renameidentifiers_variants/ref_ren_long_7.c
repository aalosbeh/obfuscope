#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned lopfnlbxcyardepqzheoaq[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        lopfnlbxcyardepqzheoaq[h % 16u]++;
    }
    int fgncjlwskuwlyoiaci = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (lopfnlbxcyardepqzheoaq[i]) fgncjlwskuwlyoiaci++; if ((int)lopfnlbxcyardepqzheoaq[i] > maxload) maxload = lopfnlbxcyardepqzheoaq[i]; }
    printf("%d %d\n", fgncjlwskuwlyoiaci, maxload);
    return 0;
}
