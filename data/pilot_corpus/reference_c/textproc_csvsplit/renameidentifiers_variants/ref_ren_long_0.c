#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char crnvpuiaymqocvswcqae[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int gvhykrbkqtpiwdpihfx = 0;
    char *start = crnvpuiaymqocvswcqae;
    for (char *p = crnvpuiaymqocvswcqae; ; p++) {
        if (*p == ',' || *p == '\0') {
            int vtwmjhnkkjmphbdcedftkj = (*p == '\0');
            *p = '\0';
            if (gvhykrbkqtpiwdpihfx < MAXF) fields[gvhykrbkqtpiwdpihfx++] = start;
            start = p + 1;
            if (vtwmjhnkkjmphbdcedftkj) break;
        }
    }
    int ezckmrmsqtxsqfwff = 0, total = 0;
    for (int i = 0; i < gvhykrbkqtpiwdpihfx; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) ezckmrmsqtxsqfwff++; }
    printf("%d %d %d\n", gvhykrbkqtpiwdpihfx, ezckmrmsqtxsqfwff, total);
    return 0;
}
