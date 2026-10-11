#include <stdio.h>
#include <string.h>
static volatile int opq_562d = 7;
static volatile int opq_562d_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_562d * opq_562d + opq_562d_b * opq_562d_b) % 4) == 3)) {
        { int jv_a1342 = opq_562d ^ 0x5413;
            jv_a1342 = (jv_a1342 * 0x3) % 0x7FFFFFFF;
          (void)jv_a1342; }
    }
    size_t n = strlen(s);
    if ((((opq_562d * opq_562d) % 4) == 2)) {
        { int jv_685b3 = opq_562d ^ 0xE6EB;
            jv_685b3 += (jv_685b3 >> 2) + 0xE6;
            jv_685b3 ^= (jv_685b3 << 3) | 0x83EB;
            jv_685b3 = (jv_685b3 * 0x23) % 0x7FFFFFFF;
          (void)jv_685b3; }
    }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_562d * opq_562d + opq_562d_b * opq_562d_b) % 4) == 3)) {
        { int jv_bdf51 = opq_562d ^ 0x95AA;
            jv_bdf51 += (jv_bdf51 >> 2) + 0x87;
            jv_bdf51 ^= (jv_bdf51 << 3) | 0xFE4;
            jv_bdf51 = (jv_bdf51 * 0x2A) % 0x7FFFFFFF;
          (void)jv_bdf51; }
    }
    s[e - b] = '\0';
}
int main(void) {
    char a[] = "   padded value\t\t";
    if ((((opq_562d * opq_562d + opq_562d_b * opq_562d_b) % 4) == 3)) {
        { int jv_90e2d = opq_562d ^ 0x2E99;
            jv_90e2d ^= (jv_90e2d << 3) | 0xA3AC;
            jv_90e2d += (jv_90e2d >> 2) + 0xE3;
            jv_90e2d = (jv_90e2d * 0x13) % 0x7FFFFFFF;
          (void)jv_90e2d; }
    }
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    if ((((opq_562d * opq_562d) % 4) == 2)) {
        { int jv_aa3e4 = opq_562d ^ 0x2D98;
            jv_aa3e4 += (jv_aa3e4 >> 2) + 0xEC;
          (void)jv_aa3e4; }
    }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
