#include <stdio.h>
int main(void) {
    unsigned char tayugfzutunzzvb[] = "sensitive payload bytes";
    const unsigned char qupbmbtvapfhzo[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(tayugfzutunzzvb) - 1;
    for (int ncnlhukcbgvcpuyvwsa = 0; ncnlhukcbgvcpuyvwsa < 2; ncnlhukcbgvcpuyvwsa++)
        for (int i = 0; i < n; i++) tayugfzutunzzvb[i] ^= qupbmbtvapfhzo[i % 4];
    long qrwngeahyiiklltbz = 0;
    for (int i = 0; i < n; i++) qrwngeahyiiklltbz += tayugfzutunzzvb[i];
    printf("%s %ld\n", (char *)tayugfzutunzzvb, qrwngeahyiiklltbz);
    return 0;
}
