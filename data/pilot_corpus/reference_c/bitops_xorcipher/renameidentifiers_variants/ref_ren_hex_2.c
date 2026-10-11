#include <stdio.h>
int main(void) {
    unsigned char v_91c288[] = "sensitive payload bytes";
    const unsigned char v_779015[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_91c288) - 1;
    for (int v_6d8bfd = 0; v_6d8bfd < 2; v_6d8bfd++)
        for (int i = 0; i < n; i++) v_91c288[i] ^= v_779015[i % 4];
    long v_db0287 = 0;
    for (int i = 0; i < n; i++) v_db0287 += v_91c288[i];
    printf("%s %ld\n", (char *)v_91c288, v_db0287);
    return 0;
}
