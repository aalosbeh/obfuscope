#include <stdio.h>
#include <string.h>
static volatile int opq_866a = 7;
static volatile int opq_866a_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    if ((((opq_866a * (opq_866a + 1)) % 2) == 0)) { opq_866a_b ^= 0; }
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_866a * (opq_866a + 1)) % 2) == 0)) { opq_866a_b ^= 0; }
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
