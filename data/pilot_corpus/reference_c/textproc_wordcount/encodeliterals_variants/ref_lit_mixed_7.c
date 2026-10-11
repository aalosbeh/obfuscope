#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x6AB - 0x6AB), in_word = (0x6D3352A0 ^ 0x6D3352A0), letters = (0x7EF - 0x7EF);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x3CFC84EC ^ 0x3CFC84EC); }
        else { if (!in_word) { words++; in_word = (0xF9D90EE ^ 0xF9D90EF); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x2D5 - 0x2D5);
}
