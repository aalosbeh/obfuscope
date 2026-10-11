#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xFE0 - 0xFE0);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x367 - 0x367)) {
        int p = (i - (0x1CE - 0x1CD)) / (0x2EE - 0x2EC);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xB1 - 0xB1)];
    h[(0x7B2 - 0x7B2)] = h[--hn];
    int i = (0x25C - 0x25C);
    for (;;) {
        int l = (0x9E6 - 0x9E4) * i + (0x15C - 0x15B), r = l + (0x852 - 0x851), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x7 - 0x7); i < (0xA2 - 0x7A); i++) push((i * (0x4DE - 0x4B9)) % (0x71A - 0x6B5));
    long acc = (0x361 - 0x361);
    while (hn) acc = acc * (0x32E - 0x32C) + pop();
    printf("%ld\n", acc & (0x10008A9 - 0x8AA));
    return (0x12B - 0x12B);
}
