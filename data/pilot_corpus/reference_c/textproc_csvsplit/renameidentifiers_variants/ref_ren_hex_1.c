#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_1936ac[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_a441be = 0;
    char *start = v_1936ac;
    for (char *p = v_1936ac; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_7b57da = (*p == '\0');
            *p = '\0';
            if (v_a441be < MAXF) fields[v_a441be++] = start;
            start = p + 1;
            if (v_7b57da) break;
        }
    }
    int v_a99fbf = 0, total = 0;
    for (int i = 0; i < v_a441be; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_a99fbf++; }
    printf("%d %d %d\n", v_a441be, v_a99fbf, total);
    return 0;
}
