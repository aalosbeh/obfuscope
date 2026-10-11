#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char zkvqbozmnkwdgwph[] = "Attack At Dawn, Bring Supplies!";
    long htvtxmrpazfdzequhog = 0;
    for (int vrefzgywcsbxjzkole = 0; vrefzgywcsbxjzkole < 2; vrefzgywcsbxjzkole++) {
        for (char *p = zkvqbozmnkwdgwph; *p; p++) { *p = rot(*p); htvtxmrpazfdzequhog += (unsigned char)*p; }
    }
    printf("%s %ld\n", zkvqbozmnkwdgwph, htvtxmrpazfdzequhog);
    return 0;
}
