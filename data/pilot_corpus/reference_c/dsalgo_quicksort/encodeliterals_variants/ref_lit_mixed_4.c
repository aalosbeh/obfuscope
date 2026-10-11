#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0xE4 - 0xE3));
    qs(a, i + (0x7AC - 0x7AB), hi);
}
int main(void) {
    int a[(0x729 - 0x709)], s = (0x848CD6B ^ 0x848CD6C);
    for (int i = (0xD0F - 0xD0F); i < (0x78D - 0x76D); i++) { s = (s * (0x143B93E2 ^ 0x55FDDD8F) + (0x30820394 ^ 0x308233AD)) & (0x3A222F49 ^ 0x45DDD0B6); a[i] = s % (0x636301C8 ^ 0x63630220); }
    qs(a, (0xBA9E60C ^ 0xBA9E60C), (0x8AF - 0x890));
    long sum = (0x1C635FA6 ^ 0x1C635FA6);
    for (int i = (0xA04 - 0xA04); i < (0x4666EED9 ^ 0x4666EEF9); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x4ABF7CC4 ^ 0x4ABF7CC4);
}
