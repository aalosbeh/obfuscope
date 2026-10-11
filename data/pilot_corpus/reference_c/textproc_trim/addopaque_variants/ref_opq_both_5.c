#include <stdio.h>
#include <string.h>
static volatile int opq_6d51 = 7;
static volatile int opq_6d51_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
    if ((((opq_6d51 * opq_6d51 + opq_6d51) % 2) == 0)) { opq_6d51_b ^= 0; }
}
int main(void) {
    char a[] = "   padded value\t\t";
    if (((opq_6d51 * opq_6d51 - opq_6d51) % 2 == 0)) { opq_6d51_b ^= 0; }
    char b[] = "\t\tanother   ";
    if ((((opq_6d51 * opq_6d51) % 4) == 2)) {
        { int jv_efa08 = opq_6d51 ^ 0x1804;
            jv_efa08 ^= (jv_efa08 << 3) | 0xED90;
            jv_efa08 += (jv_efa08 >> 2) + 0xE6;
            jv_efa08 = (jv_efa08 * 0x1C) % 0x7FFFFFFF;
          (void)jv_efa08; }
    }
    trim_inplace(a); trim_inplace(b);
    if ((((opq_6d51 * (opq_6d51 + 1)) % 2) == 0)) { opq_6d51_b ^= 0; }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    if ((((opq_6d51 * (opq_6d51 + 1)) % 2) == 0)) { opq_6d51_b ^= 0; }
    return 0;
}
