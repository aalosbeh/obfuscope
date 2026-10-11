#include <stdio.h>
int main(void) {
    unsigned char oqjksgbsuifyea[] = "sensitive payload bytes";
    const unsigned char umxbqlkiettvpbm[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(oqjksgbsuifyea) - 1;
    for (int kdyesvhavhdizvjwrc = 0; kdyesvhavhdizvjwrc < 2; kdyesvhavhdizvjwrc++)
        for (int i = 0; i < n; i++) oqjksgbsuifyea[i] ^= umxbqlkiettvpbm[i % 4];
    long qhuqcdkecqolcqsty = 0;
    for (int i = 0; i < n; i++) qhuqcdkecqolcqsty += oqjksgbsuifyea[i];
    printf("%s %ld\n", (char *)oqjksgbsuifyea, qhuqcdkecqolcqsty);
    return 0;
}
