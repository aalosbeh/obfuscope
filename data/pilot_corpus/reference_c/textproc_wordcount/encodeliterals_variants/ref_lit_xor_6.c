#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x5D19E2CC ^ 0x5D19E2CC), in_word = (0x14F63702 ^ 0x14F63702), letters = (0x12F3BD22 ^ 0x12F3BD22);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x63D0A692 ^ 0x63D0A692); }
        else { if (!in_word) { words++; in_word = (0x36DAB26 ^ 0x36DAB27); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x4B7EB3A8 ^ 0x4B7EB3A8);
}
