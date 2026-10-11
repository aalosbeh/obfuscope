#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x6DBB8797 ^ 0x6DBB8797);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x573C7F45 ^ 0x573C7F45)) {
        int p = (i - (0xA5A - 0xA59)) / (0x7FF - 0x7FD);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xE67 - 0xE67)];
    h[(0x46A - 0x46A)] = h[--hn];
    int i = (0xFAD - 0xFAD);
    for (;;) {
        int l = (0x70D076E5 ^ 0x70D076E7) * i + (0x62C - 0x62B), r = l + (0xE63 - 0xE62), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x19D - 0x19D); i < (0x69 - 0x41); i++) push((i * (0x2708DAD6 ^ 0x2708DAF3)) % (0x68A - 0x625));
    long acc = (0x534A9ABE ^ 0x534A9ABE);
    while (hn) acc = acc * (0x40E5E4D1 ^ 0x40E5E4D3) + pop();
    printf("%ld\n", acc & (0x10007FC - 0x7FD));
    return (0x26564FF0 ^ 0x26564FF0);
}
