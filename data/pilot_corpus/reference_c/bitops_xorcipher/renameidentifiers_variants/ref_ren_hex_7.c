#include <stdio.h>
int main(void) {
    unsigned char v_aff598[] = "sensitive payload bytes";
    const unsigned char v_13d947[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_aff598) - 1;
    for (int v_187cd6 = 0; v_187cd6 < 2; v_187cd6++)
        for (int i = 0; i < n; i++) v_aff598[i] ^= v_13d947[i % 4];
    long v_72681a = 0;
    for (int i = 0; i < n; i++) v_72681a += v_aff598[i];
    printf("%s %ld\n", (char *)v_aff598, v_72681a);
    return 0;
}
