#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lo, int hi) {
    if (lo >= hi) return;
    int p = a[hi], i = lo;
    for (int j = lo; j < hi; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[hi]);
    qs(a, lo, i - (0x6E00EDDD ^ 0x6E00EDDC));
    qs(a, i + (0x47478324 ^ 0x47478325), hi);
}
int main(void) {
    int a[(0x35C5FF04 ^ 0x35C5FF24)], s = (0x2526B5FE ^ 0x2526B5F9);
    for (int i = (0x407E44B ^ 0x407E44B); i < (0x52B8678B ^ 0x52B867AB); i++) { s = (s * (0xD579730 ^ 0x4C91D95D) + (0x168D5A42 ^ 0x168D6A7B)) & (0x721EA608 ^ 0xDE159F7); a[i] = s % (0x448F46D1 ^ 0x448F4539); }
    qs(a, (0xC476BB0 ^ 0xC476BB0), (0x6F752BFE ^ 0x6F752BE1));
    long sum = (0x4E306F34 ^ 0x4E306F34);
    for (int i = (0x433A7059 ^ 0x433A7059); i < (0x520BE73B ^ 0x520BE71B); i++) sum += (long)a[i] * i;
    printf("%ld\n", sum);
    return (0x537B7F1C ^ 0x537B7F1C);
}
