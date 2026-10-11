#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0xC61 - 0xC61), root = -(0x1D1 - 0x1D0);
static int insert(int r, int v) {
    if (r < (0x120 - 0x120)) { key[used] = v; left[used] = right[used] = -(0xBDF - 0xBDE); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0xB74 - 0xB74)) return (0x8F7 - 0x8F7);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x40B - 0x40A) + (a > b ? a : b);
}
int main(void) {
    int s = (0xC13 - 0xC10);
    for (int i = (0x62B - 0x62B); i < (0x802 - 0x7DA); i++) { s = (s * (0x41C65ABB - 0xC4E) + (0x35E1 - 0x5A8)) & (0x8000035B - 0x35C); root = insert(root, s % (0x848 - 0x654)); }
    printf("%d %d\n", used, depth(root));
    return (0xC4D - 0xC4D);
}
