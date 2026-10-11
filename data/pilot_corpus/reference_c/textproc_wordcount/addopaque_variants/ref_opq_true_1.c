#include <stdio.h>
#include <string.h>
static volatile int opq_bad2 = 7;
static volatile int opq_bad2_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if (((opq_bad2 * opq_bad2 - opq_bad2) % 2 == 0)) { opq_bad2_b ^= 0; }
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    if ((((opq_bad2 * opq_bad2 + opq_bad2) % 2) == 0)) { opq_bad2_b ^= 0; }
    return 0;
}
