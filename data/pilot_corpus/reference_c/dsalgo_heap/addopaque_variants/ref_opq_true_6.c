#include <stdio.h>
static volatile int opq_152d = 7;
static volatile int opq_152d_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if ((((opq_152d * (opq_152d + 1)) % 2) == 0)) { opq_152d_b ^= 0; }
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_152d * (opq_152d + 1)) % 2) == 0)) { opq_152d_b ^= 0; }
    }
}
static int pop(void) {
    int top = h[0];
    if ((((opq_152d * (opq_152d + 1)) % 2) == 0)) { opq_152d_b ^= 0; }
    h[0] = h[--hn];
    if (((opq_152d * opq_152d - opq_152d) % 2 == 0)) { opq_152d_b ^= 0; }
    int i = 0;
    if (((opq_152d * opq_152d - opq_152d) % 2 == 0)) { opq_152d_b ^= 0; }
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (((opq_152d * opq_152d - opq_152d) % 2 == 0)) { opq_152d_b ^= 0; }
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    if ((((opq_152d * (opq_152d + 1)) % 2) == 0)) { opq_152d_b ^= 0; }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    if ((((opq_152d * (opq_152d + 1)) % 2) == 0)) { opq_152d_b ^= 0; }
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_152d * (opq_152d + 1)) % 2) == 0)) { opq_152d_b ^= 0; }
    printf("%ld\n", acc & 0xffffff);
    return 0;
}
