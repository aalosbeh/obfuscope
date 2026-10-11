#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x2F1 - 0x2F1), root = -(0x7D7 - 0x7D6);
static int insert(int r, int v) {
    if (r < (0x693 - 0x693)) { key[used] = v; left[used] = right[used] = -(0xCDE - 0xCDD); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0xBB8 - 0xBB8)) return (0xFCF - 0xFCF);
    int a = depth(left[r]), b = depth(right[r]);
    return (0xF60 - 0xF5F) + (a > b ? a : b);
}
int main(void) {
    int s = (0x832 - 0x82F);
    for (int i = (0x45A - 0x45A); i < (0x7BB - 0x793); i++) { s = (s * (0x41C651D3 - 0x366) + (0x3497 - 0x45E)) & (0x800000AE - 0xAF); root = insert(root, s % (0xE9A - 0xCA6)); }
    printf("%d %d\n", used, depth(root));
    return (0x650 - 0x650);
}
