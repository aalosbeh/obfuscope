#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0xCC4 - 0xCC4);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x7E760F2 ^ 0x7E760F3);
            if (last) break;
        }
    }
    int nonempty = (0x17C985C8 ^ 0x17C985C8), total = (0xCEF6679 ^ 0xCEF6679);
    for (int i = (0x13 - 0x13); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0xECE - 0xECE);
}
