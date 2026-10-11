#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x655F5F2F ^ 0x655F5F2F);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x4DDF8DA ^ 0x4DDF8DA)) {
        int p = (i - (0x853 - 0x852)) / (0xAD9 - 0xAD7);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x6854D60A ^ 0x6854D60A)];
    h[(0x22FC4E27 ^ 0x22FC4E27)] = h[--hn];
    int i = (0x83A - 0x83A);
    for (;;) {
        int l = (0x357D5FD2 ^ 0x357D5FD0) * i + (0x907 - 0x906), r = l + (0x145 - 0x144), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x86 - 0x86); i < (0xFB2 - 0xF8A); i++) push((i * (0xED72B3F ^ 0xED72B1A)) % (0x667 - 0x602));
    long acc = (0x708CBF3 ^ 0x708CBF3);
    while (hn) acc = acc * (0x91C - 0x91A) + pop();
    printf("%ld\n", acc & (0x1000CDB - 0xCDC));
    return (0xD1A - 0xD1A);
}
