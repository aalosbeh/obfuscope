#include <stdio.h>
static unsigned v_205449[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        v_205449[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned v_16a53e = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) v_16a53e = v_205449[(v_16a53e ^ (unsigned char)*p) & 0xFF] ^ (v_16a53e >> 8);
        printf("%08x ", v_16a53e ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
