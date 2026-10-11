#include <stdio.h>
#include <string.h>
static volatile int opq_206c = 7;
static volatile int opq_206c_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_206c * (opq_206c + 1)) % 2) == 0)) { opq_206c_b ^= 0; }
    size_t n = strlen(s);
    if (((opq_206c * opq_206c - opq_206c) % 2 == 0)) { opq_206c_b ^= 0; }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_206c * opq_206c + opq_206c_b * opq_206c_b) % 4) == 3)) {
        { int jv_fdd1b = opq_206c ^ 0x567;
            jv_fdd1b ^= (jv_fdd1b << 3) | 0xF908;
            jv_fdd1b += (jv_fdd1b >> 2) + 0x61;
            jv_fdd1b = (jv_fdd1b * 0x3) % 0x7FFFFFFF;
          (void)jv_fdd1b; }
    }
    s[e - b] = '\0';
    if ((((opq_206c * opq_206c + opq_206c_b * opq_206c_b) % 4) == 3)) {
        { int jv_9bcaf = opq_206c ^ 0x596E;
            jv_9bcaf = (jv_9bcaf * 0x15) % 0x7FFFFFFF;
            jv_9bcaf += (jv_9bcaf >> 2) + 0xA2;
          (void)jv_9bcaf; }
    }
}
int main(void) {
    char a[] = "   padded value\t\t";
    if ((((opq_206c * opq_206c + opq_206c_b * opq_206c_b) % 4) == 3)) {
        { int jv_8fbcb = opq_206c ^ 0x596;
            jv_8fbcb ^= (jv_8fbcb << 3) | 0xFE45;
            jv_8fbcb = (jv_8fbcb * 0x18) % 0x7FFFFFFF;
            jv_8fbcb += (jv_8fbcb >> 2) + 0x43;
          (void)jv_8fbcb; }
    }
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
