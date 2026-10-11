#include <stdio.h>
#include <string.h>
static volatile int opq_a965 = 7;
static volatile int opq_a965_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_a965 * opq_a965) % 4) == 2)) {
        { int jv_d502f = opq_a965 ^ 0xEDBC;
            jv_d502f += (jv_d502f >> 2) + 0xEB;
            jv_d502f = (jv_d502f * 0x30) % 0x7FFFFFFF;
            jv_d502f ^= (jv_d502f << 3) | 0x4D3;
          (void)jv_d502f; }
    }
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    if ((((opq_a965 * opq_a965 + opq_a965_b * opq_a965_b) % 4) == 3)) {
        { int jv_8c03a = opq_a965 ^ 0xF157;
            jv_8c03a = (jv_8c03a * 0x3D) % 0x7FFFFFFF;
            jv_8c03a += (jv_8c03a >> 2) + 0x1E;
          (void)jv_8c03a; }
    }
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_a965 * opq_a965) % 4) == 2)) {
        { int jv_ffea0 = opq_a965 ^ 0x1527;
            jv_ffea0 = (jv_ffea0 * 0x3E) % 0x7FFFFFFF;
            jv_ffea0 ^= (jv_ffea0 << 3) | 0x32F7;
          (void)jv_ffea0; }
    }
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_a965 * opq_a965 + opq_a965_b * opq_a965_b) % 4) == 3)) {
        { int jv_c58ea = opq_a965 ^ 0xBA21;
            jv_c58ea ^= (jv_c58ea << 3) | 0x2A6C;
          (void)jv_c58ea; }
    }
    trim_inplace(a); trim_inplace(b);
    if ((((opq_a965 * opq_a965) % 4) == 2)) {
        { int jv_8a3af = opq_a965 ^ 0xA14A;
            jv_8a3af = (jv_8a3af * 0x18) % 0x7FFFFFFF;
            jv_8a3af += (jv_8a3af >> 2) + 0xF4;
            jv_8a3af ^= (jv_8a3af << 3) | 0x42B4;
          (void)jv_8a3af; }
    }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
