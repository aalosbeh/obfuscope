#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x75DC00F1 ^ 0x75DC00F1);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x58074A89 ^ 0x58074A88);
            if (last) break;
        }
    }
    int nonempty = (0x405CE655 ^ 0x405CE655), total = (0x547F61CF ^ 0x547F61CF);
    for (int i = (0x6049629E ^ 0x6049629E); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x24AC939D ^ 0x24AC939D);
}
