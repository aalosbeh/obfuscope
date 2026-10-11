#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char oxduaxopneccinsvof[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int nofzpaforkbnyzxy = 0;
    char *start = oxduaxopneccinsvof;
    for (char *p = oxduaxopneccinsvof; ; p++) {
        if (*p == ',' || *p == '\0') {
            int mmfxxoakzqcrrybrfy = (*p == '\0');
            *p = '\0';
            if (nofzpaforkbnyzxy < MAXF) fields[nofzpaforkbnyzxy++] = start;
            start = p + 1;
            if (mmfxxoakzqcrrybrfy) break;
        }
    }
    int eshsjsnylxxeaorlkjossy = 0, total = 0;
    for (int i = 0; i < nofzpaforkbnyzxy; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) eshsjsnylxxeaorlkjossy++; }
    printf("%d %d %d\n", nofzpaforkbnyzxy, eshsjsnylxxeaorlkjossy, total);
    return 0;
}
