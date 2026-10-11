#include <stdio.h>
#include <string.h>
static volatile int opq_a5c6 = 7;
static volatile int opq_a5c6_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_a5c6 * opq_a5c6 + opq_a5c6_b * opq_a5c6_b) % 4) == 3)) {
        { int jv_8896a = opq_a5c6 ^ 0xD64A;
            jv_8896a += (jv_8896a >> 2) + 0x7A;
          (void)jv_8896a; }
    }
    memmove(s, s + b, e - b);
    if ((((opq_a5c6 * opq_a5c6 + opq_a5c6_b * opq_a5c6_b) % 4) == 3)) {
        { int jv_ede8c = opq_a5c6 ^ 0x916A;
            jv_ede8c = (jv_ede8c * 0x2E) % 0x7FFFFFFF;
            jv_ede8c += (jv_ede8c >> 2) + 0xE3;
          (void)jv_ede8c; }
    }
    s[e - b] = '\0';
}
int main(void) {
    if ((((opq_a5c6 * opq_a5c6 + opq_a5c6_b * opq_a5c6_b) % 4) == 3)) {
        { int jv_c48a3 = opq_a5c6 ^ 0xDA76;
            jv_c48a3 ^= (jv_c48a3 << 3) | 0x8375;
            jv_c48a3 = (jv_c48a3 * 0x17) % 0x7FFFFFFF;
            jv_c48a3 += (jv_c48a3 >> 2) + 0x32;
          (void)jv_c48a3; }
    }
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_a5c6 * opq_a5c6) % 4) == 2)) {
        { int jv_4792c = opq_a5c6 ^ 0x48A2;
            jv_4792c += (jv_4792c >> 2) + 0xB8;
          (void)jv_4792c; }
    }
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    if ((((opq_a5c6 * opq_a5c6 + opq_a5c6_b * opq_a5c6_b) % 4) == 3)) {
        { int jv_cbd58 = opq_a5c6 ^ 0x187B;
            jv_cbd58 += (jv_cbd58 >> 2) + 0x8;
            jv_cbd58 = (jv_cbd58 * 0x3D) % 0x7FFFFFFF;
          (void)jv_cbd58; }
    }
    return 0;
}
