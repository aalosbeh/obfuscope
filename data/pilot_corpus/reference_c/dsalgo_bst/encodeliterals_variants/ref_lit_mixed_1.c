#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x2AAEE180 ^ 0x2AAEE180), root = -(0x4FEFD478 ^ 0x4FEFD479);
static int insert(int r, int v) {
    if (r < (0xA1F - 0xA1F)) { key[used] = v; left[used] = right[used] = -(0x9D0 - 0x9CF); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x588 - 0x588)) return (0x7CB98D8F ^ 0x7CB98D8F);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x58EF1124 ^ 0x58EF1125) + (a > b ? a : b);
}
int main(void) {
    int s = (0x22004093 ^ 0x22004090);
    for (int i = (0x55B - 0x55B); i < (0x5B8 - 0x590); i++) { s = (s * (0x3F01CDB5 ^ 0x7EC783D8) + (0x6F965320 ^ 0x6F966319)) & (0x800006B7 - 0x6B8); root = insert(root, s % (0x18DDE75D ^ 0x18DDE6A9)); }
    printf("%d %d\n", used, depth(root));
    return (0x27AB7F28 ^ 0x27AB7F28);
}
