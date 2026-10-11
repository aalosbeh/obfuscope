#include <stdio.h>
int main(void) {
    unsigned char v_ab86de[] = "sensitive payload bytes";
    const unsigned char v_3a6b94[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_ab86de) - 1;
    for (int v_d08a14 = 0; v_d08a14 < 2; v_d08a14++)
        for (int i = 0; i < n; i++) v_ab86de[i] ^= v_3a6b94[i % 4];
    long v_8e351b = 0;
    for (int i = 0; i < n; i++) v_8e351b += v_ab86de[i];
    printf("%s %ld\n", (char *)v_ab86de, v_8e351b);
    return 0;
}
