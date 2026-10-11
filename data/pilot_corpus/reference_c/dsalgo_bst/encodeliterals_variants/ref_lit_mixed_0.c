#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x85F - 0x85F), root = -(0x69CCA2F7 ^ 0x69CCA2F6);
static int insert(int r, int v) {
    if (r < (0x1E1 - 0x1E1)) { key[used] = v; left[used] = right[used] = -(0x57E2BFC7 ^ 0x57E2BFC6); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x1FA - 0x1FA)) return (0x61CEB8ED ^ 0x61CEB8ED);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x7231B659 ^ 0x7231B658) + (a > b ? a : b);
}
int main(void) {
    int s = (0x66D - 0x66A);
    for (int i = (0x9AE - 0x9AE); i < (0x5B8C4985 ^ 0x5B8C49AD); i++) { s = (s * (0x41C65601 - 0x794) + (0x3F0F - 0xED6)) & (0x80000B9A - 0xB9B); root = insert(root, s % (0x3E24FA54 ^ 0x3E24FBA0)); }
    printf("%d %d\n", used, depth(root));
    return (0x156 - 0x156);
}
