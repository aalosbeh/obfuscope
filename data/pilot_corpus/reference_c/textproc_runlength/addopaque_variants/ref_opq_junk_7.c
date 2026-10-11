#include <stdio.h>
static volatile int opq_5c09 = 7;
static volatile int opq_5c09_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_5c09 * opq_5c09) % 4) == 2)) {
        { int jv_b8ddb = opq_5c09 ^ 0xD1F2;
            jv_b8ddb = (jv_b8ddb * 0x3C) % 0x7FFFFFFF;
            jv_b8ddb += (jv_b8ddb >> 2) + 0x3D;
          (void)jv_b8ddb; }
    }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if ((((opq_5c09 * opq_5c09 + opq_5c09_b * opq_5c09_b) % 4) == 3)) {
            { int jv_41dcc = opq_5c09 ^ 0x6AA9;
                jv_41dcc = (jv_41dcc * 0x23) % 0x7FFFFFFF;
              (void)jv_41dcc; }
        }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_5c09 * opq_5c09 + opq_5c09_b * opq_5c09_b) % 4) == 3)) {
        { int jv_1243a = opq_5c09 ^ 0xF6BA;
            jv_1243a = (jv_1243a * 0x33) % 0x7FFFFFFF;
            jv_1243a += (jv_1243a >> 2) + 0x47;
          (void)jv_1243a; }
    }
    return 0;
}
