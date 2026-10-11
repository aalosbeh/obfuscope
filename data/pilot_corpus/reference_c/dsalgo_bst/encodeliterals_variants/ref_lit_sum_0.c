#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0xEC6 - 0xEC6), root = -(0x26D - 0x26C);
static int insert(int r, int v) {
    if (r < (0xEF2 - 0xEF2)) { key[used] = v; left[used] = right[used] = -(0x7 - 0x6); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x7F6 - 0x7F6)) return (0x309 - 0x309);
    int a = depth(left[r]), b = depth(right[r]);
    return (0xDD0 - 0xDCF) + (a > b ? a : b);
}
int main(void) {
    int s = (0x7C3 - 0x7C0);
    for (int i = (0x17 - 0x17); i < (0x30 - 0x8); i++) { s = (s * (0x41C65D8E - 0xF21) + (0x3E61 - 0xE28)) & (0x800001C3 - 0x1C4); root = insert(root, s % (0xF3A - 0xD46)); }
    printf("%d %d\n", used, depth(root));
    return (0x4B1 - 0x4B1);
}
