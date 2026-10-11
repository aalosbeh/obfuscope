#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0xBC2 - 0xBC2), root = -(0xE58 - 0xE57);
static int insert(int r, int v) {
    if (r < (0x21F - 0x21F)) { key[used] = v; left[used] = right[used] = -(0x8C2 - 0x8C1); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0xFEB - 0xFEB)) return (0xFCA - 0xFCA);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x3E5 - 0x3E4) + (a > b ? a : b);
}
int main(void) {
    int s = (0x868 - 0x865);
    for (int i = (0x766 - 0x766); i < (0x244 - 0x21C); i++) { s = (s * (0x41C65903 - 0xA96) + (0x32F0 - 0x2B7)) & (0x80000120 - 0x121); root = insert(root, s % (0x400 - 0x20C)); }
    printf("%d %d\n", used, depth(root));
    return (0x9DE - 0x9DE);
}
