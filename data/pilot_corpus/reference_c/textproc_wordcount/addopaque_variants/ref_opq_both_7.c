#include <stdio.h>
#include <string.h>
static volatile int opq_a424 = 7;
static volatile int opq_a424_b = 3;

int main(void) {
    const char *text = "the quick brown fox jumps over the lazy dog and the dog sleeps";
    int words = 0, in_word = 0, letters = 0;
    for (const char *p = text; *p; p++) {
        if ((((opq_a424 * opq_a424) % 4) == 2)) {
            { int jv_902ca = opq_a424 ^ 0xAF3F;
                jv_902ca += (jv_902ca >> 2) + 0xB4;
                jv_902ca ^= (jv_902ca << 3) | 0x238;
              (void)jv_902ca; }
        }
        if (*p == ' ') { in_word = 0; }
        else { if (!in_word) { words++; in_word = 1; } letters++; }
    }
    printf("%d %d %zu\n", words, letters, strlen(text));
    if ((((opq_a424 * opq_a424 + opq_a424) % 2) == 0)) { opq_a424_b ^= 0; }
    return 0;
}
