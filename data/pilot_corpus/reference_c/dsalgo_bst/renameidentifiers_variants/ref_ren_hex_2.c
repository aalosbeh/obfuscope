#include <stdio.h>
#define N 64
static int v_18f57c[N], left[N], right[N];
static int v_13f4d6 = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { v_18f57c[v_13f4d6] = v; left[v_13f4d6] = right[v_13f4d6] = -1; return v_13f4d6++; }
    if (v < v_18f57c[r]) left[r] = insert(left[r], v);
    else if (v > v_18f57c[r]) right[r] = insert(right[r], v);
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
    printf("%d %d\n", v_13f4d6, depth(root));
    return 0;
}
