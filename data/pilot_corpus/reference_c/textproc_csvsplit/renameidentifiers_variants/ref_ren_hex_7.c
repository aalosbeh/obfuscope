#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_78a013[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_6271d2 = 0;
    char *start = v_78a013;
    for (char *p = v_78a013; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_95eb33 = (*p == '\0');
            *p = '\0';
            if (v_6271d2 < MAXF) fields[v_6271d2++] = start;
            start = p + 1;
            if (v_95eb33) break;
        }
    }
    int v_d1aeb6 = 0, total = 0;
    for (int i = 0; i < v_6271d2; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_d1aeb6++; }
    printf("%d %d %d\n", v_6271d2, v_d1aeb6, total);
    return 0;
}
