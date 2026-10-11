#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char rvwkefbewbpcmknehunnkn[] = "Attack At Dawn, Bring Supplies!";
    long zdwsacplgqktuvsqyatj = 0;
    for (int uywhzyedwopgfzvoaixwlk = 0; uywhzyedwopgfzvoaixwlk < 2; uywhzyedwopgfzvoaixwlk++) {
        for (char *p = rvwkefbewbpcmknehunnkn; *p; p++) { *p = rot(*p); zdwsacplgqktuvsqyatj += (unsigned char)*p; }
    }
    printf("%s %ld\n", rvwkefbewbpcmknehunnkn, zdwsacplgqktuvsqyatj);
    return 0;
}
