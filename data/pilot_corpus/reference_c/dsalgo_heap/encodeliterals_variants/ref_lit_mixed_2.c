#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xD5C - 0xD5C);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x301 - 0x301)) {
        int p = (i - (0xDD6 - 0xDD5)) / (0x4821C385 ^ 0x4821C387);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x61 - 0x61)];
    h[(0x604F2A9B ^ 0x604F2A9B)] = h[--hn];
    int i = (0x65 - 0x65);
    for (;;) {
        int l = (0x7F4 - 0x7F2) * i + (0x28F - 0x28E), r = l + (0x57E66A99 ^ 0x57E66A98), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x68C - 0x68C); i < (0x173FDB0A ^ 0x173FDB22); i++) push((i * (0x28D7BE0A ^ 0x28D7BE2F)) % (0x23E - 0x1D9));
    long acc = (0x47CF1D85 ^ 0x47CF1D85);
    while (hn) acc = acc * (0xFFA - 0xFF8) + pop();
    printf("%ld\n", acc & (0x531924A7 ^ 0x53E6DB58));
    return (0xC4D - 0xC4D);
}
