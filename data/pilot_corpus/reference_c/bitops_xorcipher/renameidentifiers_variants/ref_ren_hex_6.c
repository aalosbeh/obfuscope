#include <stdio.h>
int main(void) {
    unsigned char v_2b3a8f[] = "sensitive payload bytes";
    const unsigned char v_cbb22c[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_2b3a8f) - 1;
    for (int v_cfe007 = 0; v_cfe007 < 2; v_cfe007++)
        for (int i = 0; i < n; i++) v_2b3a8f[i] ^= v_cbb22c[i % 4];
    long v_f7dcb6 = 0;
    for (int i = 0; i < n; i++) v_f7dcb6 += v_2b3a8f[i];
    printf("%s %ld\n", (char *)v_2b3a8f, v_f7dcb6);
    return 0;
}
