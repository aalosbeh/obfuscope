#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char ghoveoaeywasttldnttwg[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int hxfiqxompvahqpe = 0;
    char *start = ghoveoaeywasttldnttwg;
    for (char *p = ghoveoaeywasttldnttwg; ; p++) {
        if (*p == ',' || *p == '\0') {
            int nmeuffoayietar = (*p == '\0');
            *p = '\0';
            if (hxfiqxompvahqpe < MAXF) fields[hxfiqxompvahqpe++] = start;
            start = p + 1;
            if (nmeuffoayietar) break;
        }
    }
    int wijxofohhvlljcgjspbtr = 0, total = 0;
    for (int i = 0; i < hxfiqxompvahqpe; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) wijxofohhvlljcgjspbtr++; }
    printf("%d %d %d\n", hxfiqxompvahqpe, wijxofohhvlljcgjspbtr, total);
    return 0;
}
