#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char ihvbudzuuyayflbrudwgym[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int ryvdwgygeoagshgsazqn = 0;
    char *start = ihvbudzuuyayflbrudwgym;
    for (char *p = ihvbudzuuyayflbrudwgym; ; p++) {
        if (*p == ',' || *p == '\0') {
            int wgsgqqgrkkyhrsah = (*p == '\0');
            *p = '\0';
            if (ryvdwgygeoagshgsazqn < MAXF) fields[ryvdwgygeoagshgsazqn++] = start;
            start = p + 1;
            if (wgsgqqgrkkyhrsah) break;
        }
    }
    int zjgmihatmjsxritdhs = 0, total = 0;
    for (int i = 0; i < ryvdwgygeoagshgsazqn; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) zjgmihatmjsxritdhs++; }
    printf("%d %d %d\n", ryvdwgygeoagshgsazqn, zjgmihatmjsxritdhs, total);
    return 0;
}
