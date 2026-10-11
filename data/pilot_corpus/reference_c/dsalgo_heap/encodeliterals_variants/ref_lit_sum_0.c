#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0xA7A - 0xA7A);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0xE5B - 0xE5B)) {
        int p = (i - (0x75C - 0x75B)) / (0x718 - 0x716);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x3AA - 0x3AA)];
    h[(0x256 - 0x256)] = h[--hn];
    int i = (0xD1 - 0xD1);
    for (;;) {
        int l = (0xB68 - 0xB66) * i + (0x2D1 - 0x2D0), r = l + (0xCE0 - 0xCDF), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x3ED - 0x3ED); i < (0xF21 - 0xEF9); i++) push((i * (0x14D - 0x128)) % (0x4D1 - 0x46C));
    long acc = (0x4EB - 0x4EB);
    while (hn) acc = acc * (0x25A - 0x258) + pop();
    printf("%ld\n", acc & (0x100000B - 0xC));
    return (0xF90 - 0xF90);
}
