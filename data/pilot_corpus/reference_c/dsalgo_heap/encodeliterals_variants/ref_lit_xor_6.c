#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x2CE65F49 ^ 0x2CE65F49);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x2098C409 ^ 0x2098C409)) {
        int p = (i - (0xF645D92 ^ 0xF645D93)) / (0x9B57A9E ^ 0x9B57A9C);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x3B7CC8FE ^ 0x3B7CC8FE)];
    h[(0xF0C2891 ^ 0xF0C2891)] = h[--hn];
    int i = (0x7B663E6A ^ 0x7B663E6A);
    for (;;) {
        int l = (0x70C61AC2 ^ 0x70C61AC0) * i + (0x1993D307 ^ 0x1993D306), r = l + (0x5F45B76 ^ 0x5F45B77), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x45CA26C9 ^ 0x45CA26C9); i < (0x36CBC452 ^ 0x36CBC47A); i++) push((i * (0x696307F6 ^ 0x696307D3)) % (0x1E0DF0AB ^ 0x1E0DF0CE));
    long acc = (0x683268E7 ^ 0x683268E7);
    while (hn) acc = acc * (0x2A2413E5 ^ 0x2A2413E7) + pop();
    printf("%ld\n", acc & (0x75EE8A4B ^ 0x751175B4));
    return (0x3B2F85D0 ^ 0x3B2F85D0);
}
