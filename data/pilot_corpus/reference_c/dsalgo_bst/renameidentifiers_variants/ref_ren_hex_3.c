#include <stdio.h>
#define N 64
static int v_e8eef5[N], left[N], right[N];
static int v_527755 = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { v_e8eef5[v_527755] = v; left[v_527755] = right[v_527755] = -1; return v_527755++; }
    if (v < v_e8eef5[r]) left[r] = insert(left[r], v);
    else if (v > v_e8eef5[r]) right[r] = insert(right[r], v);
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
    printf("%d %d\n", v_527755, depth(root));
    return 0;
}
