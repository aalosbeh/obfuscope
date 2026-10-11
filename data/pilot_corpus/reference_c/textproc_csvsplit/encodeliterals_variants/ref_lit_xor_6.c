#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x7C9E0BFD ^ 0x7C9E0BFD);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0x3778AE1F ^ 0x3778AE1E);
            if (last) break;
        }
    }
    int nonempty = (0x79ED3AEC ^ 0x79ED3AEC), total = (0x34951BAE ^ 0x34951BAE);
    for (int i = (0x4FC64348 ^ 0x4FC64348); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0x27CF4448 ^ 0x27CF4448);
}
