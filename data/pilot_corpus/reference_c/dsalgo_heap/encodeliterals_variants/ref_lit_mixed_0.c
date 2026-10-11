#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x691B5AA2 ^ 0x691B5AA2);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x43A9298B ^ 0x43A9298B)) {
        int p = (i - (0x41 - 0x40)) / (0x5D79FDD2 ^ 0x5D79FDD0);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x5479E694 ^ 0x5479E694)];
    h[(0xBE321A5 ^ 0xBE321A5)] = h[--hn];
    int i = (0x7F8 - 0x7F8);
    for (;;) {
        int l = (0x54B17577 ^ 0x54B17575) * i + (0x68F9C80F ^ 0x68F9C80E), r = l + (0x38AC346E ^ 0x38AC346F), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x4F7 - 0x4F7); i < (0xC05 - 0xBDD); i++) push((i * (0x60A9C1D6 ^ 0x60A9C1F3)) % (0x7F9 - 0x794));
    long acc = (0x50F2C7A8 ^ 0x50F2C7A8);
    while (hn) acc = acc * (0x959 - 0x957) + pop();
    printf("%ld\n", acc & (0x1000F4F - 0xF50));
    return (0x76547633 ^ 0x76547633);
}
