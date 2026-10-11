#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x59C817B8 ^ 0x59C817B8), in_word = (0x654824DA ^ 0x654824DA), letters = (0x2BA57985 ^ 0x2BA57985);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x52F03D4F ^ 0x52F03D4F); }
        else { if (!in_word) { words++; in_word = (0x1FB50682 ^ 0x1FB50683); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x23B1946B ^ 0x23B1946B);
}
