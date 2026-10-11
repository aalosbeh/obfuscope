#include <stdio.h>
int main(void) {
    unsigned char v_988788[] = "sensitive payload bytes";
    const unsigned char v_7419df[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_988788) - 1;
    for (int v_1348d8 = 0; v_1348d8 < 2; v_1348d8++)
        for (int i = 0; i < n; i++) v_988788[i] ^= v_7419df[i % 4];
    long v_a32aff = 0;
    for (int i = 0; i < n; i++) v_a32aff += v_988788[i];
    printf("%s %ld\n", (char *)v_988788, v_a32aff);
    return 0;
}
