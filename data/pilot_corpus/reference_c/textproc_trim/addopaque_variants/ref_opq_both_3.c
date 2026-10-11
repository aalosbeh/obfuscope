#include <stdio.h>
#include <string.h>
static volatile int opq_bfe3 = 7;
static volatile int opq_bfe3_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_bfe3 * opq_bfe3) % 4) == 2)) {
        { int jv_f3b15 = opq_bfe3 ^ 0x3323;
            jv_f3b15 ^= (jv_f3b15 << 3) | 0x8F9C;
            jv_f3b15 += (jv_f3b15 >> 2) + 0x8F;
            jv_f3b15 = (jv_f3b15 * 0x3E) % 0x7FFFFFFF;
          (void)jv_f3b15; }
    }
    size_t n = strlen(s);
    if ((((opq_bfe3 * opq_bfe3 + opq_bfe3_b * opq_bfe3_b) % 4) == 3)) {
        { int jv_74242 = opq_bfe3 ^ 0x3358;
            jv_74242 = (jv_74242 * 0x33) % 0x7FFFFFFF;
            jv_74242 += (jv_74242 >> 2) + 0xA3;
            jv_74242 ^= (jv_74242 << 3) | 0xB7AB;
          (void)jv_74242; }
    }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if (((opq_bfe3 * opq_bfe3 - opq_bfe3) % 2 == 0)) { opq_bfe3_b ^= 0; }
    memmove(s, s + b, e - b);
    if ((((opq_bfe3 * opq_bfe3) % 4) == 2)) {
        { int jv_cfb34 = opq_bfe3 ^ 0x59EA;
            jv_cfb34 = (jv_cfb34 * 0x13) % 0x7FFFFFFF;
          (void)jv_cfb34; }
    }
    s[e - b] = '\0';
    if ((((opq_bfe3 * opq_bfe3) % 4) == 2)) {
        { int jv_2f654 = opq_bfe3 ^ 0x653A;
            jv_2f654 ^= (jv_2f654 << 3) | 0x5C24;
            jv_2f654 += (jv_2f654 >> 2) + 0x8B;
            jv_2f654 = (jv_2f654 * 0x2B) % 0x7FFFFFFF;
          (void)jv_2f654; }
    }
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
