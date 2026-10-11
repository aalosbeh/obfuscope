#include <stdio.h>
#include <string.h>
static volatile int opq_5971 = 7;
static volatile int opq_5971_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    if ((((opq_5971 * (opq_5971 + 1)) % 2) == 0)) { opq_5971_b ^= 0; }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_5971 * opq_5971 + opq_5971_b * opq_5971_b) % 4) == 3)) {
        { int jv_c2b97 = opq_5971 ^ 0xE4D6;
            jv_c2b97 = (jv_c2b97 * 0x21) % 0x7FFFFFFF;
          (void)jv_c2b97; }
    }
    memmove(s, s + b, e - b);
    if ((((opq_5971 * opq_5971 + opq_5971_b * opq_5971_b) % 4) == 3)) {
        { int jv_f294b = opq_5971 ^ 0xF71;
            jv_f294b = (jv_f294b * 0x22) % 0x7FFFFFFF;
            jv_f294b ^= (jv_f294b << 3) | 0xCD4C;
          (void)jv_f294b; }
    }
    s[e - b] = '\0';
}
int main(void) {
    if ((((opq_5971 * opq_5971 + opq_5971) % 2) == 0)) { opq_5971_b ^= 0; }
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    if ((((opq_5971 * opq_5971) % 4) == 2)) {
        { int jv_7b676 = opq_5971 ^ 0x5C21;
            jv_7b676 = (jv_7b676 * 0xC) % 0x7FFFFFFF;
            jv_7b676 += (jv_7b676 >> 2) + 0x93;
          (void)jv_7b676; }
    }
    return 0;
}
