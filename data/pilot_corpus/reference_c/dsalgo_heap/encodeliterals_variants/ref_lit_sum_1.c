#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xFEF - 0xFEF);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x658 - 0x658)) {
        int p = (i - (0x8DC - 0x8DB)) / (0x85A - 0x858);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x3E1 - 0x3E1)];
    h[(0x648 - 0x648)] = h[--hn];
    int i = (0x5EA - 0x5EA);
    for (;;) {
        int l = (0x942 - 0x940) * i + (0x5D8 - 0x5D7), r = l + (0x905 - 0x904), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x148 - 0x148); i < (0xEC7 - 0xE9F); i++) push((i * (0xC74 - 0xC4F)) % (0x495 - 0x430));
    long acc = (0xF2 - 0xF2);
    while (hn) acc = acc * (0xACE - 0xACC) + pop();
    printf("%ld\n", acc & (0x1000D37 - 0xD38));
    return (0xFBD - 0xFBD);
}
