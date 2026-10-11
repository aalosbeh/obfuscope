#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_e392ca[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_310447 = 0;
    char *start = v_e392ca;
    for (char *p = v_e392ca; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_4056e0 = (*p == '\0');
            *p = '\0';
            if (v_310447 < MAXF) fields[v_310447++] = start;
            start = p + 1;
            if (v_4056e0) break;
        }
    }
    int v_22b5a1 = 0, total = 0;
    for (int i = 0; i < v_310447; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_22b5a1++; }
    printf("%d %d %d\n", v_310447, v_22b5a1, total);
    return 0;
}
