#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x519085E1 ^ 0x519085E1), in_word = (0x156BCB1E ^ 0x156BCB1E), letters = (0x79AADAF ^ 0x79AADAF);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x3C5A3149 ^ 0x3C5A3149); }
        else { if (!in_word) { words++; in_word = (0x53D69BC6 ^ 0x53D69BC7); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x6D847672 ^ 0x6D847672);
}
