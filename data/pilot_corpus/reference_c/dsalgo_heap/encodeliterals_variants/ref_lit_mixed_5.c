#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x571066F7 ^ 0x571066F7);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x5CD98D25 ^ 0x5CD98D25)) {
        int p = (i - (0xD4C - 0xD4B)) / (0x4C413005 ^ 0x4C413007);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x285 - 0x285)];
    h[(0x175CC8CC ^ 0x175CC8CC)] = h[--hn];
    int i = (0x4D9 - 0x4D9);
    for (;;) {
        int l = (0x9AF - 0x9AD) * i + (0x5A2F8FB3 ^ 0x5A2F8FB2), r = l + (0xC75 - 0xC74), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x884960E ^ 0x884960E); i < (0x2E8E7A27 ^ 0x2E8E7A0F); i++) push((i * (0x326E7CDC ^ 0x326E7CF9)) % (0x2CFF734B ^ 0x2CFF732E));
    long acc = (0xBF8ECD5 ^ 0xBF8ECD5);
    while (hn) acc = acc * (0x88D - 0x88B) + pop();
    printf("%ld\n", acc & (0x1000912 - 0x913));
    return (0x6F264EA8 ^ 0x6F264EA8);
}
