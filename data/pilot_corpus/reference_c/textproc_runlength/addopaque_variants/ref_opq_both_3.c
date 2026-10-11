#include <stdio.h>
static volatile int opq_1492 = 7;
static volatile int opq_1492_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_1492 * opq_1492) % 4) == 2)) {
            { int jv_803fb = opq_1492 ^ 0xE803;
                jv_803fb = (jv_803fb * 0x8) % 0x7FFFFFFF;
                jv_803fb ^= (jv_803fb << 3) | 0x35C4;
              (void)jv_803fb; }
        }
        char c = in[i];
        if ((((opq_1492 * opq_1492) % 4) == 2)) {
            { int jv_80410 = opq_1492 ^ 0xC21B;
                jv_80410 += (jv_80410 >> 2) + 0x93;
              (void)jv_80410; }
        }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_1492 * opq_1492) % 4) == 2)) {
        { int jv_fa8b9 = opq_1492 ^ 0xEE08;
            jv_fa8b9 += (jv_fa8b9 >> 2) + 0x94;
            jv_fa8b9 = (jv_fa8b9 * 0x7) % 0x7FFFFFFF;
          (void)jv_fa8b9; }
    }
    return 0;
}
