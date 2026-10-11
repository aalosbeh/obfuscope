#include <stdio.h>
int main(void) {
    unsigned char v_d5b7e4[] = "sensitive payload bytes";
    const unsigned char v_d941d8[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_d5b7e4) - 1;
    for (int v_12ee34 = 0; v_12ee34 < 2; v_12ee34++)
        for (int i = 0; i < n; i++) v_d5b7e4[i] ^= v_d941d8[i % 4];
    long v_46d7b7 = 0;
    for (int i = 0; i < n; i++) v_46d7b7 += v_d5b7e4[i];
    printf("%s %ld\n", (char *)v_d5b7e4, v_46d7b7);
    return 0;
}
