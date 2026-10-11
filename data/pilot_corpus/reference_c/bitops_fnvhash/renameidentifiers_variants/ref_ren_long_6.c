#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned ysnqzqojhklwxf[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        ysnqzqojhklwxf[h % 16u]++;
    }
    int fmwlnmcggsftcguiyjgzt = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (ysnqzqojhklwxf[i]) fmwlnmcggsftcguiyjgzt++; if ((int)ysnqzqojhklwxf[i] > maxload) maxload = ysnqzqojhklwxf[i]; }
    printf("%d %d\n", fmwlnmcggsftcguiyjgzt, maxload);
    return 0;
}
