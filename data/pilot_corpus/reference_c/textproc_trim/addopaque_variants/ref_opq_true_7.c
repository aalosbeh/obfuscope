#include <stdio.h>
#include <string.h>
static volatile int opq_f1b9 = 7;
static volatile int opq_f1b9_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    if ((((opq_f1b9 * opq_f1b9 + opq_f1b9) % 2) == 0)) { opq_f1b9_b ^= 0; }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_f1b9 * opq_f1b9 + opq_f1b9) % 2) == 0)) { opq_f1b9_b ^= 0; }
    s[e - b] = '\0';
    if (((opq_f1b9 * opq_f1b9 - opq_f1b9) % 2 == 0)) { opq_f1b9_b ^= 0; }
}
int main(void) {
    char a[] = "   padded value\t\t";
    if ((((opq_f1b9 * opq_f1b9 + opq_f1b9) % 2) == 0)) { opq_f1b9_b ^= 0; }
    char b[] = "\t\tanother   ";
    if ((((opq_f1b9 * (opq_f1b9 + 1)) % 2) == 0)) { opq_f1b9_b ^= 0; }
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
