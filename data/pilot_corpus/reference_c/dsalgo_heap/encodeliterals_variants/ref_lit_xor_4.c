#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x1BC6EBC0 ^ 0x1BC6EBC0);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x7D4D2994 ^ 0x7D4D2994)) {
        int p = (i - (0x3A728E06 ^ 0x3A728E07)) / (0x1B077201 ^ 0x1B077203);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x15CA88CE ^ 0x15CA88CE)];
    h[(0x565B02C3 ^ 0x565B02C3)] = h[--hn];
    int i = (0x770B0B3D ^ 0x770B0B3D);
    for (;;) {
        int l = (0x7E239E4E ^ 0x7E239E4C) * i + (0x36FC35C1 ^ 0x36FC35C0), r = l + (0x5E99854A ^ 0x5E99854B), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x79AE880B ^ 0x79AE880B); i < (0x5736149D ^ 0x573614B5); i++) push((i * (0x7E8F518B ^ 0x7E8F51AE)) % (0x4D21037D ^ 0x4D210318));
    long acc = (0x45AACBE0 ^ 0x45AACBE0);
    while (hn) acc = acc * (0x4299AE98 ^ 0x4299AE9A) + pop();
    printf("%ld\n", acc & (0x6D1E1088 ^ 0x6DE1EF77));
    return (0x5B2B4972 ^ 0x5B2B4972);
}
