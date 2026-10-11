#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_453532[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_8db813 = 0;
    char *start = v_453532;
    for (char *p = v_453532; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_a82614 = (*p == '\0');
            *p = '\0';
            if (v_8db813 < MAXF) fields[v_8db813++] = start;
            start = p + 1;
            if (v_a82614) break;
        }
    }
    int v_a53d00 = 0, total = 0;
    for (int i = 0; i < v_8db813; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_a53d00++; }
    printf("%d %d %d\n", v_8db813, v_a53d00, total);
    return 0;
}
