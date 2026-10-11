#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char cxwkknmdbfzpntet[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int vbgabzcamrzuvhxiisd = 0;
    char *start = cxwkknmdbfzpntet;
    for (char *p = cxwkknmdbfzpntet; ; p++) {
        if (*p == ',' || *p == '\0') {
            int vkrqneplvxoxanienlf = (*p == '\0');
            *p = '\0';
            if (vbgabzcamrzuvhxiisd < MAXF) fields[vbgabzcamrzuvhxiisd++] = start;
            start = p + 1;
            if (vkrqneplvxoxanienlf) break;
        }
    }
    int zbizjkkhkboaozdqqas = 0, total = 0;
    for (int i = 0; i < vbgabzcamrzuvhxiisd; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) zbizjkkhkboaozdqqas++; }
    printf("%d %d %d\n", vbgabzcamrzuvhxiisd, zbizjkkhkboaozdqqas, total);
    return 0;
}
