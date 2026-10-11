#include <stdio.h>
static unsigned zzrfulhkqvzyojocjzhvq[256];
static void init_table(void) {
    for (unsigned i = 0; i < 256; i++) {
        unsigned c = i;
        for (int k = 0; k < 8; k++) c = (c & 1) ? (0xEDB88320u ^ (c >> 1)) : (c >> 1);
        zzrfulhkqvzyojocjzhvq[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = 0; m < 4; m++) {
        unsigned zcffsbzqvbkxftymlqb = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) zcffsbzqvbkxftymlqb = zzrfulhkqvzyojocjzhvq[(zcffsbzqvbkxftymlqb ^ (unsigned char)*p) & 0xFF] ^ (zcffsbzqvbkxftymlqb >> 8);
        printf("%08x ", zcffsbzqvbkxftymlqb ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return 0;
}
