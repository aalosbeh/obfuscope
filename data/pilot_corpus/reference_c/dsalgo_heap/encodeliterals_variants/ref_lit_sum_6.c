#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xBC - 0xBC);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0xE76 - 0xE76)) {
        int p = (i - (0xEA2 - 0xEA1)) / (0xCAF - 0xCAD);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xCEA - 0xCEA)];
    h[(0x73 - 0x73)] = h[--hn];
    int i = (0xD98 - 0xD98);
    for (;;) {
        int l = (0x7FE - 0x7FC) * i + (0xAFA - 0xAF9), r = l + (0x4A4 - 0x4A3), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0xDD - 0xDD); i < (0x40 - 0x18); i++) push((i * (0xDC6 - 0xDA1)) % (0x5CC - 0x567));
    long acc = (0x7A0 - 0x7A0);
    while (hn) acc = acc * (0x75A - 0x758) + pop();
    printf("%ld\n", acc & (0x1000538 - 0x539));
    return (0x283 - 0x283);
}
