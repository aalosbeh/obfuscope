#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x1D2 - 0x1D2);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0xCE6 - 0xCE6)) {
        int p = (i - (0x772 - 0x771)) / (0xE9A - 0xE98);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xF9 - 0xF9)];
    h[(0x291 - 0x291)] = h[--hn];
    int i = (0xFAB - 0xFAB);
    for (;;) {
        int l = (0xB76 - 0xB74) * i + (0x210 - 0x20F), r = l + (0x7BF - 0x7BE), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x439 - 0x439); i < (0x6A9 - 0x681); i++) push((i * (0x591 - 0x56C)) % (0xD63 - 0xCFE));
    long acc = (0x59C - 0x59C);
    while (hn) acc = acc * (0x4E6 - 0x4E4) + pop();
    printf("%ld\n", acc & (0x10002EB - 0x2EC));
    return (0xBBC - 0xBBC);
}
