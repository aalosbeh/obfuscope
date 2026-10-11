#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x36D644F1 ^ 0x36D644F1), in_word = (0x524A7BAD ^ 0x524A7BAD), letters = (0xDEEE46F ^ 0xDEEE46F);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x190512D3 ^ 0x190512D3); }
        else { if (!in_word) { words++; in_word = (0x6499A0E3 ^ 0x6499A0E2); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x7BF7EB7C ^ 0x7BF7EB7C);
}
