#include <stdio.h>
int main(void) {
    unsigned char whoswzaazvurtkb[] = "sensitive payload bytes";
    const unsigned char atbukeonauajyrfqjwtwn[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(whoswzaazvurtkb) - 1;
    for (int cexougprnnqbpmvvpq = 0; cexougprnnqbpmvvpq < 2; cexougprnnqbpmvvpq++)
        for (int i = 0; i < n; i++) whoswzaazvurtkb[i] ^= atbukeonauajyrfqjwtwn[i % 4];
    long rualghezqryhzzxwxtnl = 0;
    for (int i = 0; i < n; i++) rualghezqryhzzxwxtnl += whoswzaazvurtkb[i];
    printf("%s %ld\n", (char *)whoswzaazvurtkb, rualghezqryhzzxwxtnl);
    return 0;
}
