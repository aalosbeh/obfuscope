#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xCFF - 0xCFF);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x1EC2B3A5 ^ 0x1EC2B3A5)) {
        int p = (i - (0x388 - 0x387)) / (0x3EEF414B ^ 0x3EEF4149);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x8EB - 0x8EB)];
    h[(0xC2D - 0xC2D)] = h[--hn];
    int i = (0xC2E - 0xC2E);
    for (;;) {
        int l = (0x43E2A625 ^ 0x43E2A627) * i + (0x43593F63 ^ 0x43593F62), r = l + (0x2D0 - 0x2CF), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0xB41 - 0xB41); i < (0x6C5B0068 ^ 0x6C5B0040); i++) push((i * (0x35B - 0x336)) % (0x9B1 - 0x94C));
    long acc = (0x251 - 0x251);
    while (hn) acc = acc * (0x1B4 - 0x1B2) + pop();
    printf("%ld\n", acc & (0x10001C5 - 0x1C6));
    return (0x1F05B020 ^ 0x1F05B020);
}
