#include <stdio.h>
#include <string.h>
static volatile int opq_43f1 = 7;
static volatile int opq_43f1_b = 3;

static void trim_inplace(char *s) {
    if (((opq_43f1 * opq_43f1 - opq_43f1) % 2 == 0)) { opq_43f1_b ^= 0; }
    size_t n = strlen(s);
    if ((((opq_43f1 * opq_43f1 + opq_43f1_b * opq_43f1_b) % 4) == 3)) {
        { int jv_bfdd3 = opq_43f1 ^ 0xD246;
            jv_bfdd3 += (jv_bfdd3 >> 2) + 0x4D;
            jv_bfdd3 ^= (jv_bfdd3 << 3) | 0xACA3;
          (void)jv_bfdd3; }
    }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_43f1 * opq_43f1 + opq_43f1) % 2) == 0)) { opq_43f1_b ^= 0; }
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    if ((((opq_43f1 * opq_43f1) % 4) == 2)) {
        { int jv_cadfc = opq_43f1 ^ 0x3916;
            jv_cadfc += (jv_cadfc >> 2) + 0x76;
          (void)jv_cadfc; }
    }
    char a[] = "   padded value\t\t";
    if (((opq_43f1 * opq_43f1 - opq_43f1) % 2 == 0)) { opq_43f1_b ^= 0; }
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
