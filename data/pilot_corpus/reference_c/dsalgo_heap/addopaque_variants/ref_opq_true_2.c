#include <stdio.h>
static volatile int opq_844c = 7;
static volatile int opq_844c_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    if (((opq_844c * opq_844c - opq_844c) % 2 == 0)) { opq_844c_b ^= 0; }
    int i = hn++;
    if (((opq_844c * opq_844c - opq_844c) % 2 == 0)) { opq_844c_b ^= 0; }
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    if (((opq_844c * opq_844c - opq_844c) % 2 == 0)) { opq_844c_b ^= 0; }
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    if ((((opq_844c * opq_844c + opq_844c) % 2) == 0)) { opq_844c_b ^= 0; }
    for (;;) {
        if ((((opq_844c * (opq_844c + 1)) % 2) == 0)) { opq_844c_b ^= 0; }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (((opq_844c * opq_844c - opq_844c) % 2 == 0)) { opq_844c_b ^= 0; }
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    if (((opq_844c * opq_844c - opq_844c) % 2 == 0)) { opq_844c_b ^= 0; }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_844c * (opq_844c + 1)) % 2) == 0)) { opq_844c_b ^= 0; }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    if (((opq_844c * opq_844c - opq_844c) % 2 == 0)) { opq_844c_b ^= 0; }
    return 0;
}
