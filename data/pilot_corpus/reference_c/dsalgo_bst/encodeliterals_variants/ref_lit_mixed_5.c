#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0xFAA - 0xFAA), root = -(0x648C2230 ^ 0x648C2231);
static int insert(int r, int v) {
    if (r < (0x3B6 - 0x3B6)) { key[used] = v; left[used] = right[used] = -(0x6CEA8DE4 ^ 0x6CEA8DE5); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x313BD6F ^ 0x313BD6F)) return (0x172C5A56 ^ 0x172C5A56);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x9C1 - 0x9C0) + (a > b ? a : b);
}
int main(void) {
    int s = (0x2F32DFF0 ^ 0x2F32DFF3);
    for (int i = (0x4B26CFFF ^ 0x4B26CFFF); i < (0xBB7 - 0xB8F); i++) { s = (s * (0x402028D6 ^ 0x1E666BB) + (0x67C93622 ^ 0x67C9061B)) & (0x1D71B67 ^ 0x7E28E498); root = insert(root, s % (0x2753A580 ^ 0x2753A474)); }
    printf("%d %d\n", used, depth(root));
    return (0xA28 - 0xA28);
}
