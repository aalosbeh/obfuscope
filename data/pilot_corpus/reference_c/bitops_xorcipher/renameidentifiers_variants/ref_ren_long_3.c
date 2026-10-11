#include <stdio.h>
int main(void) {
    unsigned char onqpwvywrshqtpsjinxj[] = "sensitive payload bytes";
    const unsigned char vfsigbhqsnzxxnitrrqr[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(onqpwvywrshqtpsjinxj) - 1;
    for (int hlovgbjcuxnsokvfbuca = 0; hlovgbjcuxnsokvfbuca < 2; hlovgbjcuxnsokvfbuca++)
        for (int i = 0; i < n; i++) onqpwvywrshqtpsjinxj[i] ^= vfsigbhqsnzxxnitrrqr[i % 4];
    long nnzlmtxwmkfxntdgtsjsg = 0;
    for (int i = 0; i < n; i++) nnzlmtxwmkfxntdgtsjsg += onqpwvywrshqtpsjinxj[i];
    printf("%s %ld\n", (char *)onqpwvywrshqtpsjinxj, nnzlmtxwmkfxntdgtsjsg);
    return 0;
}
