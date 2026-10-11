#include <stdio.h>
#include <string.h>
static volatile int opq_f566 = 7;
static volatile int opq_f566_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    if ((((opq_f566 * opq_f566 + opq_f566_b * opq_f566_b) % 4) == 3)) {
        { int jv_464ce = opq_f566 ^ 0xA3C9;
            jv_464ce = (jv_464ce * 0x1B) % 0x7FFFFFFF;
            jv_464ce += (jv_464ce >> 2) + 0x8A;
            jv_464ce ^= (jv_464ce << 3) | 0x7164;
          (void)jv_464ce; }
    }
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_f566 * opq_f566) % 4) == 2)) {
        { int jv_1935e = opq_f566 ^ 0x4F31;
            jv_1935e ^= (jv_1935e << 3) | 0x84E9;
            jv_1935e = (jv_1935e * 0x2C) % 0x7FFFFFFF;
          (void)jv_1935e; }
    }
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
