#include <stdio.h>
#include <string.h>
static volatile int opq_fb5c = 7;
static volatile int opq_fb5c_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_fb5c * opq_fb5c) % 4) == 2)) {
        { int jv_ba5ab = opq_fb5c ^ 0xC9C1;
            jv_ba5ab += (jv_ba5ab >> 2) + 0x1E;
            jv_ba5ab = (jv_ba5ab * 0xE) % 0x7FFFFFFF;
            jv_ba5ab ^= (jv_ba5ab << 3) | 0xC415;
          (void)jv_ba5ab; }
    }
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    if ((((opq_fb5c * opq_fb5c + opq_fb5c) % 2) == 0)) { opq_fb5c_b ^= 0; }
    return 0;
}
