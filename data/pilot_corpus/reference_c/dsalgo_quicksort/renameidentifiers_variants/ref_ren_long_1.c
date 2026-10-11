#include <stdio.h>
static void swap(int *x, int *y) { int t = *x; *x = *y; *y = t; }
static void qs(int *a, int ywiwuddepmnaxaunsh, int cbneshwmtbckylmmnlbq) {
    if (ywiwuddepmnaxaunsh >= cbneshwmtbckylmmnlbq) return;
    int p = a[cbneshwmtbckylmmnlbq], i = ywiwuddepmnaxaunsh;
    for (int j = ywiwuddepmnaxaunsh; j < cbneshwmtbckylmmnlbq; j++) if (a[j] < p) swap(&a[i++], &a[j]);
    swap(&a[i], &a[cbneshwmtbckylmmnlbq]);
    qs(a, ywiwuddepmnaxaunsh, i - 1);
    qs(a, i + 1, cbneshwmtbckylmmnlbq);
}
int main(void) {
    int a[32], s = 7;
    for (int i = 0; i < 32; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; a[i] = s % 1000; }
    qs(a, 0, 31);
    long ahotfomcupjonbcyxwko = 0;
    for (int i = 0; i < 32; i++) ahotfomcupjonbcyxwko += (long)a[i] * i;
    printf("%ld\n", ahotfomcupjonbcyxwko);
    return 0;
}
