#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0xF08E919 ^ 0xF08E919);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x65DCEA32 ^ 0x65DCEA33);
            if (last) break;
        }
    }
    int nonempty = (0x63736CDA ^ 0x63736CDA), total = (0x1454D9B3 ^ 0x1454D9B3);
    for (int i = (0x35F0292D ^ 0x35F0292D); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x1E54535A ^ 0x1E54535A);
}
