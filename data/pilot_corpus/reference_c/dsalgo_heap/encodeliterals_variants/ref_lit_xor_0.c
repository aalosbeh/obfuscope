#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x660E646F ^ 0x660E646F);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x1D8D84AA ^ 0x1D8D84AA)) {
        int p = (i - (0x6644D85D ^ 0x6644D85C)) / (0x3786D7E2 ^ 0x3786D7E0);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x4E517C0C ^ 0x4E517C0C)];
    h[(0x676260EA ^ 0x676260EA)] = h[--hn];
    int i = (0x4043F107 ^ 0x4043F107);
    for (;;) {
        int l = (0x5E481A96 ^ 0x5E481A94) * i + (0x3343696 ^ 0x3343697), r = l + (0x22026F91 ^ 0x22026F90), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x63E192D2 ^ 0x63E192D2); i < (0x58DECA28 ^ 0x58DECA00); i++) push((i * (0x5026D9F6 ^ 0x5026D9D3)) % (0x5118DF96 ^ 0x5118DFF3));
    long acc = (0x6ADCDE9 ^ 0x6ADCDE9);
    while (hn) acc = acc * (0x78191C0A ^ 0x78191C08) + pop();
    printf("%ld\n", acc & (0x45CE11D0 ^ 0x4531EE2F));
    return (0x598D5C48 ^ 0x598D5C48);
}
