#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char qibjbrhtqgiztmzqza[] = "Attack At Dawn, Bring Supplies!";
    long etqrtsugjkcdkd = 0;
    for (int dqyopkvtdhhsoj = 0; dqyopkvtdhhsoj < 2; dqyopkvtdhhsoj++) {
        for (char *p = qibjbrhtqgiztmzqza; *p; p++) { *p = rot(*p); etqrtsugjkcdkd += (unsigned char)*p; }
    }
    printf("%s %ld\n", qibjbrhtqgiztmzqza, etqrtsugjkcdkd);
    return 0;
}
