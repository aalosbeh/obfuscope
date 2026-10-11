#include <stdio.h>
#include <string.h>
static volatile int opq_15f7 = 7;
static volatile int opq_15f7_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_15f7 * opq_15f7) % 4) == 2)) {
        { int jv_9abc9 = opq_15f7 ^ 0x3E47;
            jv_9abc9 += (jv_9abc9 >> 2) + 0xFB;
            jv_9abc9 ^= (jv_9abc9 << 3) | 0xB6A7;
          (void)jv_9abc9; }
    }
    for (const char *p = text; *p; p++) {
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    if ((((opq_15f7 * opq_15f7) % 4) == 2)) {
        { int jv_38131 = opq_15f7 ^ 0x39C1;
            jv_38131 += (jv_38131 >> 2) + 0xD2;
            jv_38131 = (jv_38131 * 0x39) % 0x7FFFFFFF;
            jv_38131 ^= (jv_38131 << 3) | 0x37CD;
          (void)jv_38131; }
    }
    return 0;
}
