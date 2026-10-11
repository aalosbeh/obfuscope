#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x2A792509 ^ 0x2A792509);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x1E8499F ^ 0x1E8499F)) {
        int p = (i - (0x63BCDB8E ^ 0x63BCDB8F)) / (0x2BD44F70 ^ 0x2BD44F72);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x3274287E ^ 0x3274287E)];
    h[(0x19D7059A ^ 0x19D7059A)] = h[--hn];
    int i = (0x4F2563C4 ^ 0x4F2563C4);
    for (;;) {
        int l = (0x4F8F3DFF ^ 0x4F8F3DFD) * i + (0x78CD7CC3 ^ 0x78CD7CC2), r = l + (0x76D603CC ^ 0x76D603CD), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x356725D0 ^ 0x356725D0); i < (0x36B7355B ^ 0x36B73573); i++) push((i * (0x40EC1D6D ^ 0x40EC1D48)) % (0x18167093 ^ 0x181670F6));
    long acc = (0x7D52E2CE ^ 0x7D52E2CE);
    while (hn) acc = acc * (0x52D45DB7 ^ 0x52D45DB5) + pop();
    printf("%ld\n", acc & (0x50188D27 ^ 0x50E772D8));
    return (0x2606C738 ^ 0x2606C738);
}
