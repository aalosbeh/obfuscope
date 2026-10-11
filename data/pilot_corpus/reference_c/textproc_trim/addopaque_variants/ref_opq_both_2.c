#include <stdio.h>
#include <string.h>
static volatile int opq_cc89 = 7;
static volatile int opq_cc89_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_cc89 * opq_cc89) % 4) == 2)) {
        { int jv_fdc8e = opq_cc89 ^ 0x9D9;
            jv_fdc8e = (jv_fdc8e * 0xF) % 0x7FFFFFFF;
          (void)jv_fdc8e; }
    }
    s[e - b] = '\0';
    if ((((opq_cc89 * opq_cc89 + opq_cc89) % 2) == 0)) { opq_cc89_b ^= 0; }
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_cc89 * opq_cc89 + opq_cc89) % 2) == 0)) { opq_cc89_b ^= 0; }
    trim_inplace(a); trim_inplace(b);
    if ((((opq_cc89 * (opq_cc89 + 1)) % 2) == 0)) { opq_cc89_b ^= 0; }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    if ((((opq_cc89 * opq_cc89 + opq_cc89_b * opq_cc89_b) % 4) == 3)) {
        { int jv_2d1ec = opq_cc89 ^ 0x170B;
            jv_2d1ec ^= (jv_2d1ec << 3) | 0x4CAA;
            jv_2d1ec += (jv_2d1ec >> 2) + 0x24;
            jv_2d1ec = (jv_2d1ec * 0x1C) % 0x7FFFFFFF;
          (void)jv_2d1ec; }
    }
    return 0;
}
