#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x53263A7C ^ 0x53263A7C);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x35E9E6F9 ^ 0x35E9E6F8);
            if (last) break;
        }
    }
    int nonempty = (0x56D9F0DC ^ 0x56D9F0DC), total = (0x2F995376 ^ 0x2F995376);
    for (int i = (0xECDDB65 ^ 0xECDDB65); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x2209D8F8 ^ 0x2209D8F8);
}
