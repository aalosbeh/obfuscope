#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int lkyzlglcvpsunmutkyx, int mzmonrwdztjmxqbfhpf) {
    if (lkyzlglcvpsunmutkyx >= mzmonrwdztjmxqbfhpf) return;
    int p = a[mzmonrwdztjmxqbfhpf], i = lkyzlglcvpsunmutkyx;
    for (int j = lkyzlglcvpsunmutkyx; j < mzmonrwdztjmxqbfhpf; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[mzmonrwdztjmxqbfhpf]);
    qs(a, lkyzlglcvpsunmutkyx, i - 1);
    qs(a, i + 1, mzmonrwdztjmxqbfhpf);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long vdkoztoyxgepjwavnt = 0;
    for (int i = 0; i < 32; i++) vdkoztoyxgepjwavnt += (long)a[i] * i;
    printf("%ld\n", vdkoztoyxgepjwavnt);
    return 0;
}
