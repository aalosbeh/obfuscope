#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x6F8 - 0x6F8);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x612 - 0x612)) {
        int p = (i - (0xA91 - 0xA90)) / (0x3EB - 0x3E9);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x3E76BDAF ^ 0x3E76BDAF)];
    h[(0x4A570078 ^ 0x4A570078)] = h[--hn];
    int i = (0x175A3257 ^ 0x175A3257);
    for (;;) {
        int l = (0xD58ED9E ^ 0xD58ED9C) * i + (0x7E47A29E ^ 0x7E47A29F), r = l + (0x9DD - 0x9DC), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x78BEDE3F ^ 0x78BEDE3F); i < (0xB75 - 0xB4D); i++) push((i * (0x1D353166 ^ 0x1D353143)) % (0x354 - 0x2EF));
    long acc = (0x9D6 - 0x9D6);
    while (hn) acc = acc * (0x384 - 0x382) + pop();
    printf("%ld\n", acc & (0x80F301C ^ 0x8F0CFE3));
    return (0x6BCA888B ^ 0x6BCA888B);
}
