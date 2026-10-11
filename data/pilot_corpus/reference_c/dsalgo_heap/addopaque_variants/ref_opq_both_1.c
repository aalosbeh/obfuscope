#include <stdio.h>
static volatile int opq_ed90 = 7;
static volatile int opq_ed90_b = 3;

#define CAP 64
static int h[CAP], hn = 0;
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] <= h[i]) break;
        if (((opq_ed90 * opq_ed90 - opq_ed90) % 2 == 0)) { opq_ed90_b ^= 0; }
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
        if ((((opq_ed90 * opq_ed90 + opq_ed90_b * opq_ed90_b) % 4) == 3)) {
            { int jv_6737a = opq_ed90 ^ 0x2003;
                jv_6737a += (jv_6737a >> 2) + 0x99;
              (void)jv_6737a; }
        }
    }
}
static int pop(void) {
    int top = h[0];
    h[0] = h[--hn];
    if ((((opq_ed90 * opq_ed90) % 4) == 2)) {
        { int jv_87767 = opq_ed90 ^ 0xA320;
            jv_87767 += (jv_87767 >> 2) + 0x93;
          (void)jv_87767; }
    }
    int i = 0;
    if ((((opq_ed90 * opq_ed90 + opq_ed90_b * opq_ed90_b) % 4) == 3)) {
        { int jv_30f3c = opq_ed90 ^ 0xFEEA;
            jv_30f3c = (jv_30f3c * 0x24) % 0x7FFFFFFF;
          (void)jv_30f3c; }
    }
    for (;;) {
        if (((opq_ed90 * opq_ed90 - opq_ed90) % 2 == 0)) { opq_ed90_b ^= 0; }
        int l = 2 * i + 1, r = l + 1, m = i;
        if (((opq_ed90 * opq_ed90 - opq_ed90) % 2 == 0)) { opq_ed90_b ^= 0; }
        if (l < hn && h[l] < h[m]) m = l;
        if ((((opq_ed90 * (opq_ed90 + 1)) % 2) == 0)) { opq_ed90_b ^= 0; }
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = 0; i < 40; i++) push((i * 37) % 101);
    long acc = 0;
    while (hn) acc = acc * 2 + pop();
    if (((opq_ed90 * opq_ed90 - opq_ed90) % 2 == 0)) { opq_ed90_b ^= 0; }
    printf("%ld\n", acc & 0xffffff);
    if ((((opq_ed90 * opq_ed90 + opq_ed90) % 2) == 0)) { opq_ed90_b ^= 0; }
    return 0;
}
