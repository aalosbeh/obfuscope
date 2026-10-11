#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x3E3D1499 ^ 0x3E3D1499);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x3AC1F4C6 ^ 0x3AC1F4C6)) {
        int p = (i - (0xE29 - 0xE28)) / (0xAB9 - 0xAB7);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x35 - 0x35)];
    h[(0x477D97D ^ 0x477D97D)] = h[--hn];
    int i = (0x3FF7E067 ^ 0x3FF7E067);
    for (;;) {
        int l = (0x485D4762 ^ 0x485D4760) * i + (0xF39 - 0xF38), r = l + (0x937E090 ^ 0x937E091), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x660 - 0x660); i < (0xF39 - 0xF11); i++) push((i * (0x4ECC2495 ^ 0x4ECC24B0)) % (0x7C016B21 ^ 0x7C016B44));
    long acc = (0x700B28C9 ^ 0x700B28C9);
    while (hn) acc = acc * (0xD49 - 0xD47) + pop();
    printf("%ld\n", acc & (0x357F3081 ^ 0x3580CF7E));
    return (0x58CD1D40 ^ 0x58CD1D40);
}
