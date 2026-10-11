#include <stdio.h>
#include <string.h>
static volatile int opq_6d86 = 7;
static volatile int opq_6d86_b = 3;

int main(void) {
    if ((((opq_6d86 * opq_6d86) % 4) == 2)) {
        { int jv_b1690 = opq_6d86 ^ 0xD7A0;
            jv_b1690 += (jv_b1690 >> 2) + 0x58;
            jv_b1690 ^= (jv_b1690 << 3) | 0xFF10;
            jv_b1690 = (jv_b1690 * 0x24) % 0x7FFFFFFF;
          (void)jv_b1690; }
    }
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    if ((((opq_6d86 * opq_6d86 + opq_6d86_b * opq_6d86_b) % 4) == 3)) {
        { int jv_259b1 = opq_6d86 ^ 0x355C;
            jv_259b1 = (jv_259b1 * 0x3) % 0x7FFFFFFF;
            jv_259b1 += (jv_259b1 >> 2) + 0x9;
          (void)jv_259b1; }
    }
    return 0;
}
