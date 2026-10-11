#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x45669FD6 ^ 0x45669FD6), in_word = (0x1F165B6C ^ 0x1F165B6C), letters = (0x10D8DFB3 ^ 0x10D8DFB3);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x1ADC355 ^ 0x1ADC355); }
        else { if (!in_word) { words++; in_word = (0x2094E382 ^ 0x2094E383); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x3D7E558A ^ 0x3D7E558A);
}
