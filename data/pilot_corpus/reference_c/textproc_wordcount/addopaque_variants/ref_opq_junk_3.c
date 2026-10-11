#include <stdio.h>
#include <string.h>
static volatile int opq_1997 = 7;
static volatile int opq_1997_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    if ((((opq_1997 * opq_1997 + opq_1997_b * opq_1997_b) % 4) == 3)) {
        { int jv_db4e7 = opq_1997 ^ 0x76DD;
            jv_db4e7 += (jv_db4e7 >> 2) + 0x69;
            jv_db4e7 = (jv_db4e7 * 0x37) % 0x7FFFFFFF;
          (void)jv_db4e7; }
    }
    for (const char *p = text; *p; p++) {
        if ((((opq_1997 * opq_1997 + opq_1997_b * opq_1997_b) % 4) == 3)) {
            { int jv_394c4 = opq_1997 ^ 0x82B2;
                jv_394c4 += (jv_394c4 >> 2) + 0xBD;
                jv_394c4 = (jv_394c4 * 0x3D) % 0x7FFFFFFF;
                jv_394c4 ^= (jv_394c4 << 3) | 0xDAC2;
              (void)jv_394c4; }
        }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    return 0;
}
