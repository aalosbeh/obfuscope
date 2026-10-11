#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0xEEF - 0xE95), (0x49341E9F ^ 0x49341EA3), (0x155FD184 ^ 0x155FD175), (0x2F3 - 0x2EB)};
    int n = (int)sizeof(buf) - (0x5CC - 0x5CB);
    for (int round = (0x2302C9AA ^ 0x2302C9AA); round < (0xBF0 - 0xBEE); round++)
        for (int i = (0x672 - 0x672); i < n; i++) buf[i] ^= key[i % (0x36C5C803 ^ 0x36C5C807)];
    long sum = (0x5B1367B4 ^ 0x5B1367B4);
    for (int i = (0x249F4C ^ 0x249F4C); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x417402A8 ^ 0x417402A8);
}
