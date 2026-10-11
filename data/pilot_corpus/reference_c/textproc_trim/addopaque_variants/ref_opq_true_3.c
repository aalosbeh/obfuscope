#include <stdio.h>
#include <string.h>
static volatile int opq_4e5a = 7;
static volatile int opq_4e5a_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_4e5a * (opq_4e5a + 1)) % 2) == 0)) { opq_4e5a_b ^= 0; }
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if (((opq_4e5a * opq_4e5a - opq_4e5a) % 2 == 0)) { opq_4e5a_b ^= 0; }
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    if ((((opq_4e5a * (opq_4e5a + 1)) % 2) == 0)) { opq_4e5a_b ^= 0; }
    char a[] = "   padded value\t\t";
    if ((((opq_4e5a * opq_4e5a + opq_4e5a) % 2) == 0)) { opq_4e5a_b ^= 0; }
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    if (((opq_4e5a * opq_4e5a - opq_4e5a) % 2 == 0)) { opq_4e5a_b ^= 0; }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
