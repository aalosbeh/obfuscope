#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x14E53884 ^ 0x14E538DE), (0x52C991EA ^ 0x52C991D6), (0x5BCFF118 ^ 0x5BCFF1E9), (0x17DEE4A8 ^ 0x17DEE4A0)};
    int n = (int)sizeof(buf) - (0x7948D602 ^ 0x7948D603);
    for (int round = (0x123D630D ^ 0x123D630D); round < (0x754C5CD7 ^ 0x754C5CD5); round++)
        for (int i = (0x728D4B69 ^ 0x728D4B69); i < n; i++) buf[i] ^= key[i % (0x3AE169C5 ^ 0x3AE169C1)];
    long sum = (0x7263B5A0 ^ 0x7263B5A0);
    for (int i = (0x4ACEFE6B ^ 0x4ACEFE6B); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x6F15207B ^ 0x6F15207B);
}
