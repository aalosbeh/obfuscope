#include <stdio.h>
#include <string.h>
static volatile int opq_8dc4 = 7;
static volatile int opq_8dc4_b = 3;

int main(void) {
    if ((((opq_8dc4 * opq_8dc4) % 4) == 2)) {
        { int jv_37921 = opq_8dc4 ^ 0x6F53;
            jv_37921 += (jv_37921 >> 2) + 0x8A;
            jv_37921 ^= (jv_37921 << 3) | 0x8B1;
            jv_37921 = (jv_37921 * 0x3E) % 0x7FFFFFFF;
          (void)jv_37921; }
    }
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_8dc4 * opq_8dc4 + opq_8dc4_b * opq_8dc4_b) % 4) == 3)) {
        { int jv_7d28c = opq_8dc4 ^ 0xE548;
            jv_7d28c += (jv_7d28c >> 2) + 0x14;
            jv_7d28c = (jv_7d28c * 0x3B) % 0x7FFFFFFF;
            jv_7d28c ^= (jv_7d28c << 3) | 0x912;
          (void)jv_7d28c; }
    }
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
