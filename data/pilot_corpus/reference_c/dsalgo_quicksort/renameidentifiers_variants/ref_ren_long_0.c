#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int npqngmnvaeoojr, int npmimfwnnrdgafjhhkyu) {
    if (npqngmnvaeoojr >= npmimfwnnrdgafjhhkyu) return;
    int p = a[npmimfwnnrdgafjhhkyu], i = npqngmnvaeoojr;
    for (int j = npqngmnvaeoojr; j < npmimfwnnrdgafjhhkyu; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[npmimfwnnrdgafjhhkyu]);
    qs(a, npqngmnvaeoojr, i - 1);
    qs(a, i + 1, npmimfwnnrdgafjhhkyu);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long zawtkzvcogdwjihrrqfvxf = 0;
    for (int i = 0; i < 32; i++) zawtkzvcogdwjihrrqfvxf += (long)a[i] * i;
    printf("%ld\n", zawtkzvcogdwjihrrqfvxf);
    return 0;
}
