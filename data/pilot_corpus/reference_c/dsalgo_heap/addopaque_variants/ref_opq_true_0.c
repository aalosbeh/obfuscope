#include <stdio.h>
static volatile int opq_4a90 = 7;
static volatile int opq_4a90_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        if (((opq_4a90 * opq_4a90 - opq_4a90) % 2 == 0)) { opq_4a90_b ^= 0; }
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if ((((opq_4a90 * (opq_4a90 + 1)) % 2) == 0)) { opq_4a90_b ^= 0; }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    if (((opq_4a90 * opq_4a90 - opq_4a90) % 2 == 0)) { opq_4a90_b ^= 0; }
    int top = h[0];
    h[0] = h[--hn];
    int i = 0;
    for (;;) {
        int l = 2 * i + 1, r = l + 1, m = i;
        if (((opq_4a90 * opq_4a90 - opq_4a90) % 2 == 0)) { opq_4a90_b ^= 0; }
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_4a90 * (opq_4a90 + 1)) % 2) == 0)) { opq_4a90_b ^= 0; }
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        if (((opq_4a90 * opq_4a90 - opq_4a90) % 2 == 0)) { opq_4a90_b ^= 0; }
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    if ((((opq_4a90 * (opq_4a90 + 1)) % 2) == 0)) { opq_4a90_b ^= 0; }
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if ((((opq_4a90 * opq_4a90 + opq_4a90) % 2) == 0)) { opq_4a90_b ^= 0; }
    printf("%ld\n", acc & 0xffffff);
    if (((opq_4a90 * opq_4a90 - opq_4a90) % 2 == 0)) { opq_4a90_b ^= 0; }
    return 0;
}
