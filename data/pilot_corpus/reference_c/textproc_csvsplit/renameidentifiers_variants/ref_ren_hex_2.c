#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_e0879a[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_7163fb = 0;
    char *start = v_e0879a;
    for (char *p = v_e0879a; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_fb1931 = (*p == '\0');
            *p = '\0';
            if (v_7163fb < MAXF) fields[v_7163fb++] = start;
            start = p + 1;
            if (v_fb1931) break;
        }
    }
    int v_5b07e4 = 0, total = 0;
    for (int i = 0; i < v_7163fb; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_5b07e4++; }
    printf("%d %d %d\n", v_7163fb, v_5b07e4, total);
    return 0;
}
