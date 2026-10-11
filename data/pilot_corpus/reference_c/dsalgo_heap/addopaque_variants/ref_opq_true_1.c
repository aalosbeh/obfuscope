#include <stdio.h>
static volatile int opq_c3b2 = 7;
static volatile int opq_c3b2_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    if ((((opq_c3b2 * opq_c3b2 + opq_c3b2) % 2) == 0)) { opq_c3b2_b ^= 0; }
    h[i] = v;
    while (i > 0) {
        if ((((opq_c3b2 * opq_c3b2 + opq_c3b2) % 2) == 0)) { opq_c3b2_b ^= 0; }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_c3b2 * opq_c3b2 + opq_c3b2) % 2) == 0)) { opq_c3b2_b ^= 0; }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_c3b2 * (opq_c3b2 + 1)) % 2) == 0)) { opq_c3b2_b ^= 0; }
    h[0] = h[--hn];
    int i = 0;
    if (((opq_c3b2 * opq_c3b2 - opq_c3b2) % 2 == 0)) { opq_c3b2_b ^= 0; }
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if ((((opq_c3b2 * opq_c3b2 + opq_c3b2) % 2) == 0)) { opq_c3b2_b ^= 0; }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    if ((((opq_c3b2 * opq_c3b2 + opq_c3b2) % 2) == 0)) { opq_c3b2_b ^= 0; }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_c3b2 * (opq_c3b2 + 1)) % 2) == 0)) { opq_c3b2_b ^= 0; }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_c3b2 * (opq_c3b2 + 1)) % 2) == 0)) { opq_c3b2_b ^= 0; }
    return 0;
}
