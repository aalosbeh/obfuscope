#include <stdio.h>
static unsigned table[(0x66CE360 ^ 0x66CE260)];
static void init_table(void) {
    for (unsigned i = (0x639B9427 ^ 0x639B9427); i < (0x154F0215 ^ 0x154F0315); i++) {
        unsigned c = i;
        for (int k = (0x566CB3AA ^ 0x566CB3AA); k < (0x2853F912 ^ 0x2853F91A); k++) c = (c & (0x3DC3FD23 ^ 0x3DC3FD22)) ? (0xEDB88320u ^ (c >> (0x69100927 ^ 0x69100926))) : (c >> (0x768B0B36 ^ 0x768B0B37));
        table[i] = c;
    }
}
int main(void) {
    init_table();
    const char *msgs[] = {"hello", "world", "obfuscation", ""};
    for (int m = (0x73E926BA ^ 0x73E926BA); m < (0x3C063762 ^ 0x3C063766); m++) {
        unsigned crc = 0xFFFFFFFFu;
        for (const char *p = msgs[m]; *p; p++) crc = table[(crc ^ (unsigned char)*p) & (0x2984E61 ^ 0x2984E9E)] ^ (crc >> (0xBE9ECF1 ^ 0xBE9ECF9));
        printf("%08x ", crc ^ 0xFFFFFFFFu);
    }
    printf("\n");
    return (0x49D78E44 ^ 0x49D78E44);
}
