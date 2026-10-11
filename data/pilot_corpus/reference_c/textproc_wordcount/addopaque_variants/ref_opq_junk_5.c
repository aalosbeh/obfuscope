#include <stdio.h>
#include <string.h>
static volatile int opq_7c6f = 7;
static volatile int opq_7c6f_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_7c6f * opq_7c6f + opq_7c6f_b * opq_7c6f_b) % 4) == 3)) {
        { int jv_eaeb9 = opq_7c6f ^ 0xEBE5;
            jv_eaeb9 ^= (jv_eaeb9 << 3) | 0x3F51;
            jv_eaeb9 = (jv_eaeb9 * 0x2F) % 0x7FFFFFFF;
          (void)jv_eaeb9; }
    }
    for (const char *p = text; *p; p++) {
        if ((((opq_7c6f * opq_7c6f + opq_7c6f_b * opq_7c6f_b) % 4) == 3)) {
            { int jv_d1ff3 = opq_7c6f ^ 0xEFDC;
                jv_d1ff3 += (jv_d1ff3 >> 2) + 0x53;
                jv_d1ff3 = (jv_d1ff3 * 0x28) % 0x7FFFFFFF;
              (void)jv_d1ff3; }
        }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
