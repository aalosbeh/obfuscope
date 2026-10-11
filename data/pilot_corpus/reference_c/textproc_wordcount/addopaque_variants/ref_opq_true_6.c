#include <stdio.h>
#include <string.h>
static volatile int opq_3260 = 7;
static volatile int opq_3260_b = 3;

int main(void) {
    if ((((opq_3260 * (opq_3260 + 1)) % 2) == 0)) { opq_3260_b ^= 0; }
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    for (const char *p = text; *p; p++) {
        if (((opq_3260 * opq_3260 - opq_3260) % 2 == 0)) { opq_3260_b ^= 0; }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
