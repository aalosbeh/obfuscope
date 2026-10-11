#include <stdio.h>
#include <string.h>
int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int njzifppfssnsvhfnk = 0, in_word = 0, letters = 0;
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { njzifppfssnsvhfnk++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", njzifppfssnsvhfnk, letters, strlen(text));
    return 0;
}
