#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned v_968885[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        v_968885[h % 16u]++;
    }
    int v_ddba0d = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (v_968885[i]) v_ddba0d++; if ((int)v_968885[i] > maxload) maxload = v_968885[i]; }
    printf("%d %d\n", v_ddba0d, maxload);
    return 0;
}
