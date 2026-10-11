#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x2CC154C6 ^ 0x2CC154C6), in_word = (0x198E50E7 ^ 0x198E50E7), letters = (0x13B44CDC ^ 0x13B44CDC);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x68769203 ^ 0x68769203); }
        else { if (!in_word) { words++; in_word = (0x27F26F0C ^ 0x27F26F0D); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x6076AC99 ^ 0x6076AC99);
}
