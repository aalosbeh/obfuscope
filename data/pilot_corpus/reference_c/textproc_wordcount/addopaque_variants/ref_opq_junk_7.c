#include <stdio.h>
#include <string.h>
static volatile int opq_e50a = 7;
static volatile int opq_e50a_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_e50a * opq_e50a + opq_e50a_b * opq_e50a_b) % 4) == 3)) {
        { int jv_68ffd = opq_e50a ^ 0xE549;
            jv_68ffd += (jv_68ffd >> 2) + 0x8D;
            jv_68ffd ^= (jv_68ffd << 3) | 0x7739;
          (void)jv_68ffd; }
    }
    for (const char *p = text; *p; p++) {
        if ((((opq_e50a * opq_e50a + opq_e50a_b * opq_e50a_b) % 4) == 3)) {
            { int jv_11831 = opq_e50a ^ 0xEE93;
                jv_11831 += (jv_11831 >> 2) + 0xB;
                jv_11831 = (jv_11831 * 0x1E) % 0x7FFFFFFF;
                jv_11831 ^= (jv_11831 << 3) | 0xBCA0;
              (void)jv_11831; }
        }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
