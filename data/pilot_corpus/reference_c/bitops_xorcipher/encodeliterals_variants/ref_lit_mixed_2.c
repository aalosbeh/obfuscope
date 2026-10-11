#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xD4F - 0xCF5), (0x1FD95018 ^ 0x1FD95024), (0x744 - 0x653), (0x6F5BA254 ^ 0x6F5BA25C)};
    int n = (int)sizeof(buf) - (0x4DBE6CFE ^ 0x4DBE6CFF);
    for (int round = (0xB9E - 0xB9E); round < (0x7772F801 ^ 0x7772F803); round++)
        for (int i = (0x2F5 - 0x2F5); i < n; i++) buf[i] ^= key[i % (0x54BCA165 ^ 0x54BCA161)];
    long sum = (0x69BFB6E7 ^ 0x69BFB6E7);
    for (int i = (0x9A5 - 0x9A5); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x928 - 0x928);
}
