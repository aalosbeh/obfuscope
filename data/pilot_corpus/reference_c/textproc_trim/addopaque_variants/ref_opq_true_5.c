#include <stdio.h>
#include <string.h>
static volatile int opq_3839 = 7;
static volatile int opq_3839_b = 3;

static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    if ((((opq_3839 * (opq_3839 + 1)) % 2) == 0)) { opq_3839_b ^= 0; }
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_3839 * opq_3839 + opq_3839) % 2) == 0)) { opq_3839_b ^= 0; }
    memmove(s, s + b, e - b);
    if (((opq_3839 * opq_3839 - opq_3839) % 2 == 0)) { opq_3839_b ^= 0; }
    s[e - b] = '\0';
    if ((((opq_3839 * opq_3839 + opq_3839) % 2) == 0)) { opq_3839_b ^= 0; }
}
int main(void) {
    if ((((opq_3839 * opq_3839 + opq_3839) % 2) == 0)) { opq_3839_b ^= 0; }
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
