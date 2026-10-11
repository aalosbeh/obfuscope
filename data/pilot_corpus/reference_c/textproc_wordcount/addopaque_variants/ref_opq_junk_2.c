#include <stdio.h>
#include <string.h>
static volatile int opq_361e = 7;
static volatile int opq_361e_b = 3;

int main(void) {
    if ((((opq_361e * opq_361e + opq_361e_b * opq_361e_b) % 4) == 3)) {
        { int jv_7f372 = opq_361e ^ 0x352D;
            jv_7f372 = (jv_7f372 * 0x3A) % 0x7FFFFFFF;
            jv_7f372 ^= (jv_7f372 << 3) | 0xC3D7;
          (void)jv_7f372; }
    }
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    for (const char *p = text; *p; p++) {
        if ((((opq_361e * opq_361e + opq_361e_b * opq_361e_b) % 4) == 3)) {
            { int jv_833ac = opq_361e ^ 0xAF17;
                jv_833ac ^= (jv_833ac << 3) | 0xF02C;
                jv_833ac = (jv_833ac * 0x16) % 0x7FFFFFFF;
                jv_833ac += (jv_833ac >> 2) + 0xA;
              (void)jv_833ac; }
        }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
