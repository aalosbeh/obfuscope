#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_ee226e[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_d4017b = 0;
    char *start = v_ee226e;
    for (char *p = v_ee226e; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_b03bb5 = (*p == '\0');
            *p = '\0';
            if (v_d4017b < MAXF) fields[v_d4017b++] = start;
            start = p + 1;
            if (v_b03bb5) break;
        }
    }
    int v_baf8c4 = 0, total = 0;
    for (int i = 0; i < v_d4017b; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_baf8c4++; }
    printf("%d %d %d\n", v_d4017b, v_baf8c4, total);
    return 0;
}
