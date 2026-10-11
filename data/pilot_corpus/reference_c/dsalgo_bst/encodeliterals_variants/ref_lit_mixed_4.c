#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x6991FB49 ^ 0x6991FB49), root = -(0x872 - 0x871);
static int insert(int r, int v) {
    if (r < (0x715 - 0x715)) { key[used] = v; left[used] = right[used] = -(0x2294C3C4 ^ 0x2294C3C5); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x63EBE72C ^ 0x63EBE72C)) return (0x54D746F9 ^ 0x54D746F9);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x4F9CB2D6 ^ 0x4F9CB2D7) + (a > b ? a : b);
}
int main(void) {
    int s = (0x538 - 0x535);
    for (int i = (0x63736FF1 ^ 0x63736FF1); i < (0x14A - 0x122); i++) { s = (s * (0x41C65234 - 0x3C7) + (0x3CF9 - 0xCC0)) & (0x80000EC7 - 0xEC8); root = insert(root, s % (0x2DF - 0xEB)); }
    printf("%d %d\n", used, depth(root));
    return (0x6B726F80 ^ 0x6B726F80);
}
