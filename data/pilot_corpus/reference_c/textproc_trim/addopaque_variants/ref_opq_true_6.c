#include <stdio.h>
#include <string.h>
static volatile int opq_cae8 = 7;
static volatile int opq_cae8_b = 3;

static void trim_inplace(char *s) {
    if (((opq_cae8 * opq_cae8 - opq_cae8) % 2 == 0)) { opq_cae8_b ^= 0; }
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_cae8 * opq_cae8 + opq_cae8) % 2) == 0)) { opq_cae8_b ^= 0; }
    s[e - b] = '\0';
    if ((((opq_cae8 * opq_cae8 + opq_cae8) % 2) == 0)) { opq_cae8_b ^= 0; }
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_cae8 * opq_cae8 + opq_cae8) % 2) == 0)) { opq_cae8_b ^= 0; }
    trim_inplace(a); trim_inplace(b);
    if (((opq_cae8 * opq_cae8 - opq_cae8) % 2 == 0)) { opq_cae8_b ^= 0; }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
