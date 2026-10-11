#include <stdio.h>
#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int jtueavavvxlrvqmajl = h[0];
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return jtueavavvxlrvqmajl;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long ockwvacthmxnquhappach = 0;
    while (hn) ockwvacthmxnquhappach = ockwvacthmxnquhappach * 2 + pop();
    printf("%ld\n", ockwvacthmxnquhappach & 0xffffff);
    return 0;
}
