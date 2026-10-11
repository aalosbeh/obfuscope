#include <stdio.h>
int main(void) {
    unsigned char v_ff0166[] = "sensitive payload bytes";
    const unsigned char v_39f55e[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(v_ff0166) - 1;
    for (int v_5dbe17 = 0; v_5dbe17 < 2; v_5dbe17++)
        for (int i = 0; i < n; i++) v_ff0166[i] ^= v_39f55e[i % 4];
    long v_e72030 = 0;
    for (int i = 0; i < n; i++) v_e72030 += v_ff0166[i];
    printf("%s %ld\n", (char *)v_ff0166, v_e72030);
    return 0;
}
