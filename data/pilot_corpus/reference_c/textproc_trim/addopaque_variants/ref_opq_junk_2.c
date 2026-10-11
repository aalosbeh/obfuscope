#include <stdio.h>
#include <string.h>
static volatile int opq_aaed = 7;
static volatile int opq_aaed_b = 3;

static void trim_inplace(char *s) {
    if ((((opq_aaed * opq_aaed) % 4) == 2)) {
        { int jv_f1bda = opq_aaed ^ 0x95B;
            jv_f1bda += (jv_f1bda >> 2) + 0xF8;
            jv_f1bda = (jv_f1bda * 0x35) % 0x7FFFFFFF;
          (void)jv_f1bda; }
    }
    size_t n = strlen(s);
    size_t b = 0;
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-1] == ' ' || s[e-1] == '\t')) e--;
    memmove(s, s + b, e - b);
    if ((((opq_aaed * opq_aaed + opq_aaed_b * opq_aaed_b) % 4) == 3)) {
        { int jv_913d1 = opq_aaed ^ 0xC817;
            jv_913d1 += (jv_913d1 >> 2) + 0xB1;
          (void)jv_913d1; }
    }
    s[e - b] = '\0';
    if ((((opq_aaed * opq_aaed + opq_aaed_b * opq_aaed_b) % 4) == 3)) {
        { int jv_ad681 = opq_aaed ^ 0xC6BD;
            jv_ad681 ^= (jv_ad681 << 3) | 0x623A;
          (void)jv_ad681; }
    }
}
int main(void) {
    char a[] = "   padded value\t\t";
    if ((((opq_aaed * opq_aaed) % 4) == 2)) {
        { int jv_dfbf2 = opq_aaed ^ 0x6BC3;
            jv_dfbf2 = (jv_dfbf2 * 0x36) % 0x7FFFFFFF;
          (void)jv_dfbf2; }
    }
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    if ((((opq_aaed * opq_aaed) % 4) == 2)) {
        { int jv_89b40 = opq_aaed ^ 0x413D;
            jv_89b40 += (jv_89b40 >> 2) + 0x51;
          (void)jv_89b40; }
    }
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return 0;
}
