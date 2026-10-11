#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x46BEFB7B ^ 0x46BEFB7B), in_word = (0x632 - 0x632), letters = (0x42F - 0x42F);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x71B - 0x71B); }
        else { if (!in_word) { words++; in_word = (0xDCA - 0xDC9); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0xD1B - 0xD1B);
}
