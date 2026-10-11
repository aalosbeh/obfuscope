#include <stdio.h>
#define LIM 500
int main(void) {
    char twpgaqmisadtqwfptuezs[LIM];
    for (int i = 0; i < LIM; i++) twpgaqmisadtqwfptuezs[i] = 1;
    twpgaqmisadtqwfptuezs[0] = twpgaqmisadtqwfptuezs[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (twpgaqmisadtqwfptuezs[i])
            for (int j = i * i; j < LIM; j += i) twpgaqmisadtqwfptuezs[j] = 0;
    int jdpnmkgjwijmmsupf = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (twpgaqmisadtqwfptuezs[i]) { jdpnmkgjwijmmsupf++; last = i; }
    printf("%d %d\n", jdpnmkgjwijmmsupf, last);
    return 0;
}
