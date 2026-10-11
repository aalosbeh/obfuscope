#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = (0x5FBE1DBC ^ 0x5FBE1DBC), in_word = (0x761AF066 ^ 0x761AF066), letters = (0x3F60F129 ^ 0x3F60F129);
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = (0x78C8A868 ^ 0x78C8A868); }
        else { if (!in_word) { words++; in_word = (0x7736F1C1 ^ 0x7736F1C0); } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return (0x2E621EE8 ^ 0x2E621EE8);
}
