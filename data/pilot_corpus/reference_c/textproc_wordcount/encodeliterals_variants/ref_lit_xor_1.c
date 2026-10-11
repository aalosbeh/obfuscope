#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x581167D1 ^ 0x581167D1), in_word = (0x49F116FF ^ 0x49F116FF), letters = (0x35647EFE ^ 0x35647EFE);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x49E94F92 ^ 0x49E94F92); }
        else { if (!in_word) { words++; in_word = (0x4C63094 ^ 0x4C63095); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x1B3ECEBC ^ 0x1B3ECEBC);
}
