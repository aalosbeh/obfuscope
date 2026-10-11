#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_a4c005[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_43f866 = 0;
    char *start = v_a4c005;
    for (char *p = v_a4c005; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_b67196 = (*p == '\0');
            *p = '\0';
            if (v_43f866 < MAXF) fields[v_43f866++] = start;
            start = p + 1;
            if (v_b67196) break;
        }
    }
    int v_645937 = 0, total = 0;
    for (int i = 0; i < v_43f866; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_645937++; }
    printf("%d %d %d\n", v_43f866, v_645937, total);
    return 0;
}
