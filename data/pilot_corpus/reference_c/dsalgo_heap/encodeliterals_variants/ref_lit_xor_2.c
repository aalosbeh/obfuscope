#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x1DDD9D43 ^ 0x1DDD9D43);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x3892EEBF ^ 0x3892EEBF)) {
        int p = (i - (0x37F20F27 ^ 0x37F20F26)) / (0x415CC67F ^ 0x415CC67D);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x67928DBD ^ 0x67928DBD)];
    h[(0x3707EA65 ^ 0x3707EA65)] = h[--hn];
    int i = (0x3381FCAB ^ 0x3381FCAB);
    for (;;) {
        int l = (0x79D40FE2 ^ 0x79D40FE0) * i + (0x26BCF2E2 ^ 0x26BCF2E3), r = l + (0x6199E9A9 ^ 0x6199E9A8), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x7DDE981A ^ 0x7DDE981A); i < (0x5F1342B0 ^ 0x5F134298); i++) push((i * (0x647B2178 ^ 0x647B215D)) % (0x4D4E30C7 ^ 0x4D4E30A2));
    long acc = (0x5E6561EB ^ 0x5E6561EB);
    while (hn) acc = acc * (0x2AFCECC7 ^ 0x2AFCECC5) + pop();
    printf("%ld\n", acc & (0x2CCE749B ^ 0x2C318B64));
    return (0x71974351 ^ 0x71974351);
}
