#include <stdio.h>
#include <string.h>
static volatile int opq_e3b1 = 7;
static volatile int opq_e3b1_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_e3b1 * opq_e3b1) % 4) == 2)) {
        { int jv_4bd79 = opq_e3b1 ^ 0x1DD1;
            jv_4bd79 = (jv_4bd79 * 0x39) % 0x7FFFFFFF;
          (void)jv_4bd79; }
    }
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    if ((((opq_e3b1 * opq_e3b1) % 4) == 2)) {
        { int jv_8e7e3 = opq_e3b1 ^ 0xE02B;
            jv_8e7e3 ^= (jv_8e7e3 << 3) | 0x2A54;
          (void)jv_8e7e3; }
    }
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    char a[] = "   padded value\t\t";
    if ((((opq_e3b1 * opq_e3b1 + opq_e3b1_b * opq_e3b1_b) % 4) == 3)) {
        { int jv_ef085 = opq_e3b1 ^ 0x4D1F;
            jv_ef085 += (jv_ef085 >> 2) + 0x34;
            jv_ef085 = (jv_ef085 * 0x28) % 0x7FFFFFFF;
            jv_ef085 ^= (jv_ef085 << 3) | 0x6D16;
          (void)jv_ef085; }
    }
    char b[] = "\t\tanother   ";
    if ((((opq_e3b1 * opq_e3b1) % 4) == 2)) {
        { int jv_f488b = opq_e3b1 ^ 0x5BBE;
            jv_f488b ^= (jv_f488b << 3) | 0x6CD1;
            jv_f488b = (jv_f488b * 0x37) % 0x7FFFFFFF;
            jv_f488b += (jv_f488b >> 2) + 0xBF;
          (void)jv_f488b; }
    }
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    if ((((opq_e3b1 * opq_e3b1) % 4) == 2)) {
        { int jv_4fea4 = opq_e3b1 ^ 0xAD0D;
            jv_4fea4 = (jv_4fea4 * 0x2A) % 0x7FFFFFFF;
            jv_4fea4 += (jv_4fea4 >> 2) + 0xF0;
          (void)jv_4fea4; }
    }
    return 0;
}
