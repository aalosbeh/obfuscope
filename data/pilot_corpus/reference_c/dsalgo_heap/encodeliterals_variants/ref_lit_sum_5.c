#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x3 - 0x3);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x872 - 0x872)) {
        int p = (i - (0x466 - 0x465)) / (0x492 - 0x490);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0x674 - 0x674)];
    h[(0x9A3 - 0x9A3)] = h[--hn];
    int i = (0xB97 - 0xB97);
    for (;;) {
        int l = (0x721 - 0x71F) * i + (0xD79 - 0xD78), r = l + (0x605 - 0x604), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0xE6F - 0xE6F); i < (0x44A - 0x422); i++) push((i * (0x100A - 0xFE5)) % (0xF0 - 0x8B));
    long acc = (0x574 - 0x574);
    while (hn) acc = acc * (0xC17 - 0xC15) + pop();
    printf("%ld\n", acc & (0x1000CD8 - 0xCD9));
    return (0x9E1 - 0x9E1);
}
