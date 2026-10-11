#include <stdio.h>
#define N 64
static int xzzmmkxlqfydlocwojji[N], left[N], right[N];
static int bylgecjbbwkzjdmykhr = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { xzzmmkxlqfydlocwojji[bylgecjbbwkzjdmykhr] = v; left[bylgecjbbwkzjdmykhr] = right[bylgecjbbwkzjdmykhr] = -1; return bylgecjbbwkzjdmykhr++; }
    if (v < xzzmmkxlqfydlocwojji[r]) left[r] = insert(left[r], v);
    else if (v > xzzmmkxlqfydlocwojji[r]) right[r] = insert(right[r], v);
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
    printf("%d %d\n", bylgecjbbwkzjdmykhr, depth(root));
    return 0;
}
