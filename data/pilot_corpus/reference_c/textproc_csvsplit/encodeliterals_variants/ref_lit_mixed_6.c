#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x7173E44 ^ 0x7173E44);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x58DAA8D7 ^ 0x58DAA8D6);
            if (last) break;
        }
    }
    int nonempty = (0x5E8 - 0x5E8), total = (0x677AAD04 ^ 0x677AAD04);
    for (int i = (0xB8A - 0xB8A); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x12D868C3 ^ 0x12D868C3);
}
