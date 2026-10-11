#include <stdio.h>
static unsigned qeahluxyvixdofhvixbypi[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        qeahluxyvixdofhvixbypi[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned noevdagcmigqwt = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) noevdagcmigqwt = qeahluxyvixdofhvixbypi[(noevdagcmigqwt ^ (unsigned char)*p) & 0xFF] ^ (noevdagcmigqwt >> 8);
        printf("%08x ", noevdagcmigqwt ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
