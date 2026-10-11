#include <stdio.h>
#include <string.h>
static volatile int opq_7c79 = 7;
static volatile int opq_7c79_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_7c79 * opq_7c79) % 4) == 2)) {
        { int jv_aaca2 = opq_7c79 ^ 0x2D28;
            jv_aaca2 += (jv_aaca2 >> 2) + 0x43;
            jv_aaca2 ^= (jv_aaca2 << 3) | 0x368C;
            jv_aaca2 = (jv_aaca2 * 0x20) % 0x7FFFFFFF;
          (void)jv_aaca2; }
    }
    size_t n = strlen(s);
    if ((((opq_7c79 * opq_7c79) % 4) == 2)) {
        { int jv_409a6 = opq_7c79 ^ 0xA090;
            jv_409a6 += (jv_409a6 >> 2) + 0xC1;
          (void)jv_409a6; }
    }
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    if ((((opq_7c79 * opq_7c79 + opq_7c79_b * opq_7c79_b) % 4) == 3)) {
        { int jv_4c817 = opq_7c79 ^ 0x1C86;
            jv_4c817 = (jv_4c817 * 0xE) % 0x7FFFFFFF;
            jv_4c817 += (jv_4c817 >> 2) + 0x9F;
            jv_4c817 ^= (jv_4c817 << 3) | 0xD294;
          (void)jv_4c817; }
    }
    memmove(s, s + b, e - b);
    if ((((opq_7c79 * opq_7c79 + opq_7c79_b * opq_7c79_b) % 4) == 3)) {
        { int jv_81435 = opq_7c79 ^ 0x369A;
            jv_81435 = (jv_81435 * 0x4) % 0x7FFFFFFF;
            jv_81435 ^= (jv_81435 << 3) | 0x20D8;
          (void)jv_81435; }
    }
    s[e - b] = '\0';
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    if ((((opq_7c79 * opq_7c79) % 4) == 2)) {
        { int jv_5559f = opq_7c79 ^ 0x5517;
            jv_5559f ^= (jv_5559f << 3) | 0xF94E;
            jv_5559f = (jv_5559f * 0x10) % 0x7FFFFFFF;
            jv_5559f += (jv_5559f >> 2) + 0x22;
          (void)jv_5559f; }
    }
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
