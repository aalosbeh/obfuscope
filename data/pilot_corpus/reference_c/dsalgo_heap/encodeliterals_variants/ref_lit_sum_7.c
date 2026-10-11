#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xCCD - 0xCCD);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0xB57 - 0xB57)) {
        int p = (i - (0x2C3 - 0x2C2)) / (0xA01 - 0x9FF);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xA11 - 0xA11)];
    h[(0xD3B - 0xD3B)] = h[--hn];
    int i = (0x86E - 0x86E);
    for (;;) {
        int l = (0xE99 - 0xE97) * i + (0x99A - 0x999), r = l + (0xF14 - 0xF13), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x137 - 0x137); i < (0x975 - 0x94D); i++) push((i * (0xAA1 - 0xA7C)) % (0xB5D - 0xAF8));
    long acc = (0x3DD - 0x3DD);
    while (hn) acc = acc * (0x17A - 0x178) + pop();
    printf("%ld\n", acc & (0x1000DA5 - 0xDA6));
    return (0x1E0 - 0x1E0);
}
