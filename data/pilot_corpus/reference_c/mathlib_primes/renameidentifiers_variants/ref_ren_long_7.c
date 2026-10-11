#include <stdio.h>
#define LIM 500
int main(void) {
    char hcfhcrnivwpobnl[LIM];
    for (int i = 0; i < LIM; i++) hcfhcrnivwpobnl[i] = 1;
    hcfhcrnivwpobnl[0] = hcfhcrnivwpobnl[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (hcfhcrnivwpobnl[i])
            for (int j = i * i; j < LIM; j += i) hcfhcrnivwpobnl[j] = 0;
    int zstsfutefuxfdvl = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (hcfhcrnivwpobnl[i]) { zstsfutefuxfdvl++; last = i; }
    printf("%d %d\n", zstsfutefuxfdvl, last);
    return 0;
}
