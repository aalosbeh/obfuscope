#include <stdio.h>
#define N 64
static int pkapkfuoqpkvmhnejolicu[N], left[N], right[N];
static int uzaetlcgzgbpsttuprg = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { pkapkfuoqpkvmhnejolicu[uzaetlcgzgbpsttuprg] = v; left[uzaetlcgzgbpsttuprg] = right[uzaetlcgzgbpsttuprg] = -1; return uzaetlcgzgbpsttuprg++; }
    if (v < pkapkfuoqpkvmhnejolicu[r]) left[r] = insert(left[r], v);
    else if (v > pkapkfuoqpkvmhnejolicu[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", uzaetlcgzgbpsttuprg, depth(root));
    return 0;
}
