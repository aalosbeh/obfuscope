#include <stdio.h>
#include <string.h>
static volatile int opq_17a2 = 7;
static volatile int opq_17a2_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    if ((((opq_17a2 * opq_17a2 + opq_17a2_b * opq_17a2_b) % 4) == 3)) {
        { int jv_1815c = opq_17a2 ^ 0x4314;
            jv_1815c = (jv_1815c * 0x12) % 0x7FFFFFFF;
          (void)jv_1815c; }
    }
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_17a2 * opq_17a2 + opq_17a2) % 2) == 0)) { opq_17a2_b ^= 0; }
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    if ((((opq_17a2 * opq_17a2 + opq_17a2_b * opq_17a2_b) % 4) == 3)) {
        { int jv_e7d07 = opq_17a2 ^ 0x2723;
            jv_e7d07 ^= (jv_e7d07 << 3) | 0xED8A;
            jv_e7d07 += (jv_e7d07 >> 2) + 0x9A;
          (void)jv_e7d07; }
    }
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_17a2 * opq_17a2 + opq_17a2_b * opq_17a2_b) % 4) == 3)) {
        { int jv_96d62 = opq_17a2 ^ 0xA6C2;
            jv_96d62 = (jv_96d62 * 0xE) % 0x7FFFFFFF;
          (void)jv_96d62; }
    }
    trim_inplace(a); trim_inplace(b);
    if ((((opq_17a2 * opq_17a2 + opq_17a2) % 2) == 0)) { opq_17a2_b ^= 0; }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
