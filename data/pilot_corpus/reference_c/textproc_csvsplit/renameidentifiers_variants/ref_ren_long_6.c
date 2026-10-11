#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char zjcnxdtgwhcshpf[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int pqiygsfiypcrhfxo = 0;
    char *start = zjcnxdtgwhcshpf;
    for (char *p = zjcnxdtgwhcshpf; ; p++) {
        if (*p == ',' || *p == '\0') {
            int yhmlyiqbotigxpp = (*p == '\0');
            *p = '\0';
            if (pqiygsfiypcrhfxo < MAXF) fields[pqiygsfiypcrhfxo++] = start;
            start = p + 1;
            if (yhmlyiqbotigxpp) break;
        }
    }
    int yocnbpqlmcacfocblkue = 0, total = 0;
    for (int i = 0; i < pqiygsfiypcrhfxo; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) yocnbpqlmcacfocblkue++; }
    printf("%d %d %d\n", pqiygsfiypcrhfxo, yocnbpqlmcacfocblkue, total);
    return 0;
}
