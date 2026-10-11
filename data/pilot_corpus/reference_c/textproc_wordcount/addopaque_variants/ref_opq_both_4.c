#include <stdio.h>
#include <string.h>
static volatile int opq_2aff = 7;
static volatile int opq_2aff_b = 3;

int main(void) {
    if ((((opq_2aff * opq_2aff) % 4) == 2)) {
        { int jv_69b62 = opq_2aff ^ 0x7F0D;
            jv_69b62 += (jv_69b62 >> 2) + 0x56;
          (void)jv_69b62; }
    }
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    for (const char *p = text; *p; p++) {
        if ((((opq_2aff * (opq_2aff + 1)) % 2) == 0)) { opq_2aff_b ^= 0; }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
