#include <stdio.h>
#include <string.h>
static volatile int opq_237d = 7;
static volatile int opq_237d_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_237d * opq_237d) % 4) == 2)) {
        { int jv_75435 = opq_237d ^ 0xEF9E;
            jv_75435 = (jv_75435 * 0x3D) % 0x7FFFFFFF;
            jv_75435 += (jv_75435 >> 2) + 0xD1;
          (void)jv_75435; }
    }
    memmove(s, s + b, e - b);
    if ((((opq_237d * opq_237d + opq_237d_b * opq_237d_b) % 4) == 3)) {
        { int jv_ce6c5 = opq_237d ^ 0xA18;
            jv_ce6c5 ^= (jv_ce6c5 << 3) | 0xA4F9;
            jv_ce6c5 += (jv_ce6c5 >> 2) + 0x73;
          (void)jv_ce6c5; }
    }
    s[e - b] = '\0';
    if ((((opq_237d * opq_237d) % 4) == 2)) {
        { int jv_b6836 = opq_237d ^ 0xE2F;
            jv_b6836 = (jv_b6836 * 0x15) % 0x7FFFFFFF;
            jv_b6836 ^= (jv_b6836 << 3) | 0x7FFC;
          (void)jv_b6836; }
    }
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_237d * opq_237d) % 4) == 2)) {
        { int jv_4fd08 = opq_237d ^ 0x39C6;
            jv_4fd08 ^= (jv_4fd08 << 3) | 0x2B5A;
          (void)jv_4fd08; }
    }
    trim_inplace(a); trim_inplace(b);
    if ((((opq_237d * opq_237d) % 4) == 2)) {
        { int jv_92e4f = opq_237d ^ 0xDA2F;
            jv_92e4f += (jv_92e4f >> 2) + 0x95;
            jv_92e4f ^= (jv_92e4f << 3) | 0xB9F5;
          (void)jv_92e4f; }
    }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
