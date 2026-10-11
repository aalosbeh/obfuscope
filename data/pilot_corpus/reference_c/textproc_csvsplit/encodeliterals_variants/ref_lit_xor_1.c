#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x12CB5737 ^ 0x12CB5737);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x6BF6FBA4 ^ 0x6BF6FBA5);
            if (last) break;
        }
    }
    int nonempty = (0x863CFB4 ^ 0x863CFB4), total = (0x79BF18D ^ 0x79BF18D);
    for (int i = (0x3059496C ^ 0x3059496C); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x72A4C846 ^ 0x72A4C846);
}
