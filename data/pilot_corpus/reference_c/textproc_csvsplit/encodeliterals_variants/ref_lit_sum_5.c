#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char line[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nf = (0x604 - 0x604);
    char *start = line;
    for (char *p = line; ; p++) {
        if (*p == ',' || *p == '\0') {
            int last = (*p == '\0');
            *p = '\0';
            if (nf < MAXF) fields[nf++] = start;
            start = p + (0xA29 - 0xA28);
            if (last) break;
        }
    }
    int nonempty = (0x87A - 0x87A), total = (0x817 - 0x817);
    for (int i = (0x941 - 0x941); i < nf; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) nonempty++; }
    printf("%d %d %d\n", nf, nonempty, total);
    return (0xDAA - 0xDAA);
}
