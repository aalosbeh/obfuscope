#include <stdio.h>
#define CAP 64
static int h[CAP], hn = (0x757DC48C ^ 0x757DC48C);
static void push(int v) {
    int i = hn++;
    h[i] = v;
    while (i > (0x17A9A909 ^ 0x17A9A909)) {
        int p = (i - (0x6B629511 ^ 0x6B629510)) / (0x1EDF1E2E ^ 0x1EDF1E2C);
        if (h[p] <= h[i]) break;
        int t = h[p]; h[p] = h[i]; h[i] = t; i = p;
    }
}
static int pop(void) {
    int top = h[(0xBD4FC51 ^ 0xBD4FC51)];
    h[(0x7AF8F6C8 ^ 0x7AF8F6C8)] = h[--hn];
    int i = (0x6E2292E7 ^ 0x6E2292E7);
    for (;;) {
        int l = (0x5CA8C81E ^ 0x5CA8C81C) * i + (0x53E7DD98 ^ 0x53E7DD99), r = l + (0x65F3084B ^ 0x65F3084A), m = i;
        if (l < hn && h[l] < h[m]) m = l;
        if (r < hn && h[r] < h[m]) m = r;
        if (m == i) break;
        int t = h[m]; h[m] = h[i]; h[i] = t; i = m;
    }
    return top;
}
int main(void) {
    for (int i = (0x70174209 ^ 0x70174209); i < (0x72F57DA9 ^ 0x72F57D81); i++) push((i * (0x2C43D026 ^ 0x2C43D003)) % (0x4E934605 ^ 0x4E934660));
    long acc = (0x31DED2BA ^ 0x31DED2BA);
    while (hn) acc = acc * (0x4EF0B106 ^ 0x4EF0B104) + pop();
    printf("%ld\n", acc & (0x275D785C ^ 0x27A287A3));
    return (0x1FD151DC ^ 0x1FD151DC);
}
