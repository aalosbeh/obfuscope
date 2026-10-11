#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char v_f8f4ad[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int v_ceaea7 = 0;
    char *start = v_f8f4ad;
    for (char *p = v_f8f4ad; ; p++) {
        if (*p == ',' || *p == '\0') {
            int v_8701c7 = (*p == '\0');
            *p = '\0';
            if (v_ceaea7 < MAXF) fields[v_ceaea7++] = start;
            start = p + 1;
            if (v_8701c7) break;
        }
    }
    int v_a7dfae = 0, total = 0;
    for (int i = 0; i < v_ceaea7; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) v_a7dfae++; }
    printf("%d %d %d\n", v_ceaea7, v_a7dfae, total);
    return 0;
}
