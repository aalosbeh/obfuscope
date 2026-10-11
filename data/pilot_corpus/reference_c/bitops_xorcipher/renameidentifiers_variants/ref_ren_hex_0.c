#include <stdio.h>
int main(void) {
    unsigned char v_55ab6a[] = "sensitive payload bytes";
    const unsigned char v_4ce864[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_55ab6a) - 1;
    for (int v_f7aa28 = 0; v_f7aa28 < 2; v_f7aa28++)
        for (int i = 0; i < n; i++) v_55ab6a[i] ^= v_4ce864[i % 4];
    long v_c0a855 = 0;
    for (int i = 0; i < n; i++) v_c0a855 += v_55ab6a[i];
    printf("%s %ld\n", (char *)v_55ab6a, v_c0a855);
    return 0;
}
