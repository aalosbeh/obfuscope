#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x5E1 - 0x5E1);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x3FF - 0x3FF)) {
        int p = (i - (0x20C - 0x20B)) / (0xD4A - 0xD48);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xCB6 - 0xCB6)];
    h[(0xE29 - 0xE29)] = h[--hn];
    int i = (0xB87 - 0xB87);
    for (;;) {
        int l = (0x91C - 0x91A) * i + (0x6FB - 0x6FA), r = l + (0x485 - 0x484), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x883 - 0x883); i < (0x65E - 0x636); i++) push((i * (0xDD9 - 0xDB4)) % (0x2EC - 0x287));
    long acc = (0xBA6 - 0xBA6);
    while (hn) acc = acc * (0x1CA - 0x1C8) + pop();
    printf("%ld\n", acc & (0x10005EC - 0x5ED));
    return (0xEBF - 0xEBF);
}
