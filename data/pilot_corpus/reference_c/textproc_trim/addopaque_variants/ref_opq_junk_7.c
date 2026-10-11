#include <stdio.h>
#include <string.h>
static volatile int opq_1452 = 7;
static volatile int opq_1452_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    if ((((opq_1452 * opq_1452) % 4) == 2)) {
        { int jv_95912 = opq_1452 ^ 0x9415;
            jv_95912 ^= (jv_95912 << 3) | 0x1321;
            jv_95912 += (jv_95912 >> 2) + 0xC1;
          (void)jv_95912; }
    }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_1452 * opq_1452) % 4) == 2)) {
        { int jv_fd586 = opq_1452 ^ 0xFAB;
            jv_fd586 = (jv_fd586 * 0x39) % 0x7FFFFFFF;
            jv_fd586 += (jv_fd586 >> 2) + 0x79;
            jv_fd586 ^= (jv_fd586 << 3) | 0xDA0B;
          (void)jv_fd586; }
    }
    s[e - b] = '\0';
    if ((((opq_1452 * opq_1452) % 4) == 2)) {
        { int jv_78411 = opq_1452 ^ 0x7767;
            jv_78411 += (jv_78411 >> 2) + 0x12;
            jv_78411 ^= (jv_78411 << 3) | 0x12D0;
            jv_78411 = (jv_78411 * 0x21) % 0x7FFFFFFF;
          (void)jv_78411; }
    }
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_1452 * opq_1452) % 4) == 2)) {
        { int jv_dd7c9 = opq_1452 ^ 0x3CC;
            jv_dd7c9 = (jv_dd7c9 * 0x2F) % 0x7FFFFFFF;
          (void)jv_dd7c9; }
    }
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    if ((((opq_1452 * opq_1452) % 4) == 2)) {
        { int jv_ce2d8 = opq_1452 ^ 0x3AA3;
            jv_ce2d8 ^= (jv_ce2d8 << 3) | 0x9936;
            jv_ce2d8 += (jv_ce2d8 >> 2) + 0x31;
          (void)jv_ce2d8; }
    }
    return 0;
}
