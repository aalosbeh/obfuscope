#include <stdio.h>
#include <string.h>
static volatile int opq_7585 = 7;
static volatile int opq_7585_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_7585 * opq_7585 + opq_7585_b * opq_7585_b) % 4) == 3)) {
        { int jv_e6432 = opq_7585 ^ 0xC1FA;
            jv_e6432 = (jv_e6432 * 0x2C) % 0x7FFFFFFF;
          (void)jv_e6432; }
    }
    memmove(s, s + b, e - b);
    if ((((opq_7585 * opq_7585) % 4) == 2)) {
        { int jv_6866f = opq_7585 ^ 0x962;
            jv_6866f += (jv_6866f >> 2) + 0xB4;
          (void)jv_6866f; }
    }
    s[e - b] = '\0';
    if ((((opq_7585 * opq_7585 + opq_7585_b * opq_7585_b) % 4) == 3)) {
        { int jv_40b7c = opq_7585 ^ 0xD74B;
            jv_40b7c += (jv_40b7c >> 2) + 0xB4;
            jv_40b7c = (jv_40b7c * 0x1F) % 0x7FFFFFFF;
          (void)jv_40b7c; }
    }
}
int main(void) {
    if ((((opq_7585 * opq_7585) % 4) == 2)) {
        { int jv_af33c = opq_7585 ^ 0x257;
            jv_af33c = (jv_af33c * 0x12) % 0x7FFFFFFF;
          (void)jv_af33c; }
    }
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_7585 * opq_7585) % 4) == 2)) {
        { int jv_eef88 = opq_7585 ^ 0x9B60;
            jv_eef88 ^= (jv_eef88 << 3) | 0x6820;
            jv_eef88 += (jv_eef88 >> 2) + 0xB2;
            jv_eef88 = (jv_eef88 * 0x37) % 0x7FFFFFFF;
          (void)jv_eef88; }
    }
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
