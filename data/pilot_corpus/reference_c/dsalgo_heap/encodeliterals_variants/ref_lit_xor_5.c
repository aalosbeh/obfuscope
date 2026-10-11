#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x8E7F8AA ^ 0x8E7F8AA);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x4A8086E2 ^ 0x4A8086E2)) {
        int p = (i - (0x4F2C0FCB ^ 0x4F2C0FCA)) / (0x577FD6E1 ^ 0x577FD6E3);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x199DC683 ^ 0x199DC683)];
    h[(0x29A1DC13 ^ 0x29A1DC13)] = h[--hn];
    int i = (0x10100081 ^ 0x10100081);
    for (;;) {
        int l = (0x244B451 ^ 0x244B453) * i + (0x2C12466A ^ 0x2C12466B), r = l + (0x1D5117D8 ^ 0x1D5117D9), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x5C2E3CF7 ^ 0x5C2E3CF7); i < (0x33264324 ^ 0x3326430C); i++) push((i * (0x3ABDE0F8 ^ 0x3ABDE0DD)) % (0x32C24DB1 ^ 0x32C24DD4));
    long acc = (0x46839650 ^ 0x46839650);
    while (hn) acc = acc * (0x12A4433D ^ 0x12A4433F) + pop();
    printf("%ld\n", acc & (0xBC5146C ^ 0xB3AEB93));
    return (0x65F57C5F ^ 0x65F57C5F);
}
