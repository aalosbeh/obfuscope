#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x15A7BD7F ^ 0x15A7BD7F), root = -(0xABD48DC ^ 0xABD48DD);
static int insert(int r, int v) {
    if (r < (0x3C033F26 ^ 0x3C033F26)) { key[used] = v; left[used] = right[used] = -(0x35D38F14 ^ 0x35D38F15); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x4A5EE2FD ^ 0x4A5EE2FD)) return (0x517DDC54 ^ 0x517DDC54);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x5B04B6F5 ^ 0x5B04B6F4) + (a > b ? a : b);
}
int main(void) {
    int s = (0x26D82708 ^ 0x26D8270B);
    for (int i = (0x538F4F0 ^ 0x538F4F0); i < (0x446417B3 ^ 0x4464179B); i++) { s = (s * (0x4302EFD8 ^ 0x2C4A1B5) + (0x19A0DAF6 ^ 0x19A0EACF)) & (0x6F88DBC6 ^ 0x10772439); root = insert(root, s % (0x4EF07FDB ^ 0x4EF07E2F)); }
    printf("%d %d\n", used, depth(root));
    return (0x3AFD1DE5 ^ 0x3AFD1DE5);
}
