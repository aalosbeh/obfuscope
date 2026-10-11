#include <stdio.h>
int main(void) {
    unsigned char buf[] = "sensitive payload bytes";
    const unsigned char key[] = {(0x55A2A3FB ^ 0x55A2A3A1), (0x5BBF765A ^ 0x5BBF7666), (0x7B88EB64 ^ 0x7B88EB95), (0x68DF0CBF ^ 0x68DF0CB7)};
    int n = (int)sizeof(buf) - (0x7522973D ^ 0x7522973C);
    for (int round = (0x55AE8565 ^ 0x55AE8565); round < (0x93CE2A1 ^ 0x93CE2A3); round++)
        for (int i = (0x13ABA091 ^ 0x13ABA091); i < n; i++) buf[i] ^= key[i % (0x41D201FE ^ 0x41D201FA)];
    long sum = (0x3644186 ^ 0x3644186);
    for (int i = (0x16C2F8BF ^ 0x16C2F8BF); i < n; i++) sum += buf[i];
    printf("%s %ld\n", (char *)buf, sum);
    return (0x3E96269 ^ 0x3E96269);
}
