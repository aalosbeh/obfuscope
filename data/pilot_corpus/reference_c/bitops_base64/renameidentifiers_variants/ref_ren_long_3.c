#include <stdio.h>
static const char ubhvcqfnjhfiyilth[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char tsglnuiimexsuuiyrnhxa[] = "Obfuscation provenance";
    char clqjalyebmbtnomedvdm[64];
    int n = (int)sizeof(tsglnuiimexsuuiyrnhxa) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)tsglnuiimexsuuiyrnhxa[i] << 16;
        int feuvkfemtwtmwzv = n - i;
        if (feuvkfemtwtmwzv > 1) v |= (unsigned)tsglnuiimexsuuiyrnhxa[i+1] << 8;
        if (feuvkfemtwtmwzv > 2) v |= tsglnuiimexsuuiyrnhxa[i+2];
        clqjalyebmbtnomedvdm[o++] = ubhvcqfnjhfiyilth[(v >> 18) & 63];
        clqjalyebmbtnomedvdm[o++] = ubhvcqfnjhfiyilth[(v >> 12) & 63];
        clqjalyebmbtnomedvdm[o++] = (feuvkfemtwtmwzv > 1) ? ubhvcqfnjhfiyilth[(v >> 6) & 63] : '=';
        clqjalyebmbtnomedvdm[o++] = (feuvkfemtwtmwzv > 2) ? ubhvcqfnjhfiyilth[v & 63] : '=';
    }
    clqjalyebmbtnomedvdm[o] = '\0';
    printf("%s %d\n", clqjalyebmbtnomedvdm, o);
    return 0;
}
