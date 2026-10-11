#include <stdio.h>
static unsigned v_bccafd[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        v_bccafd[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned v_5a76e8 = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) v_5a76e8 = v_bccafd[(v_5a76e8 ^ (unsigned char)*p) & 0xFF] ^ (v_5a76e8 >> 8);
        printf("%08x ", v_5a76e8 ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
