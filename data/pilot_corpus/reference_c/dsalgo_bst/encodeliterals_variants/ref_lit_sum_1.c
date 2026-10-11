#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x77 - 0x77), root = -(0xFDF - 0xFDE);
static int insert(int r, int v) {
    if (r < (0xD80 - 0xD80)) { key[used] = v; left[used] = right[used] = -(0x574 - 0x573); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x8D9 - 0x8D9)) return (0x275 - 0x275);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x14F - 0x14E) + (a > b ? a : b);
}
int main(void) {
    int s = (0xA7F - 0xA7C);
    for (int i = (0x3EE - 0x3EE); i < (0xC4F - 0xC27); i++) { s = (s * (0x41C64EC5 - 0x58) + (0x3898 - 0x85F)) & (0x80000062 - 0x63); root = insert(root, s % (0xC07 - 0xA13)); }
    printf("%d %d\n", used, depth(root));
    return (0x79C - 0x79C);
}
