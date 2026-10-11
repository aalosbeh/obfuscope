#include <stdio.h>
static volatile int opq_2025 = 7;
static volatile int opq_2025_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if (((opq_2025 * opq_2025 - opq_2025) % 2 == 0)) { opq_2025_b ^= 0; }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if (((opq_2025 * opq_2025 - opq_2025) % 2 == 0)) { opq_2025_b ^= 0; }
    printf("%s %d\n", out, o);
    if (((opq_2025 * opq_2025 - opq_2025) % 2 == 0)) { opq_2025_b ^= 0; }
    return 0;
}
