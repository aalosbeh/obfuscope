#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x31FA5E03 ^ 0x31FA5E03);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0xB003CE2 ^ 0xB003CE2)) {
        int p = (i - (0x79B9A3E0 ^ 0x79B9A3E1)) / (0x6FCAEDD1 ^ 0x6FCAEDD3);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x2926508 ^ 0x2926508)];
    h[(0x2835BFDE ^ 0x2835BFDE)] = h[--hn];
    int i = (0x7661434 ^ 0x7661434);
    for (;;) {
        int l = (0x62E888CB ^ 0x62E888C9) * i + (0x3D51034F ^ 0x3D51034E), r = l + (0x7131F348 ^ 0x7131F349), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0xD64D346 ^ 0xD64D346); i < (0x261EAA62 ^ 0x261EAA4A); i++) push((i * (0x7C2BD390 ^ 0x7C2BD3B5)) % (0x77507A1 ^ 0x77507C4));
    long acc = (0x895DD74 ^ 0x895DD74);
    while (hn) acc = acc * (0x7AEA7083 ^ 0x7AEA7081) + pop();
    printf("%ld\n", acc & (0x309078DA ^ 0x306F8725));
    return (0xCA43FED ^ 0xCA43FED);
}
