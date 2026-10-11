#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x48C6AB11 ^ 0x48C6AB11), root = -(0x690100B7 ^ 0x690100B6);
static int insert(int r, int v) {
    if (r < (0x764 - 0x764)) { key[used] = v; left[used] = right[used] = -(0x2E28C5E8 ^ 0x2E28C5E9); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0xC2E - 0xC2E)) return (0x5EE - 0x5EE);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x30843A94 ^ 0x30843A95) + (a > b ? a : b);
}
int main(void) {
    int s = (0x7866DC64 ^ 0x7866DC67);
    for (int i = (0x559 - 0x559); i < (0x714E5302 ^ 0x714E532A); i++) { s = (s * (0x1D9025E5 ^ 0x5C566B88) + (0x3F0A072E ^ 0x3F0A3717)) & (0x7EBFF842 ^ 0x14007BD); root = insert(root, s % (0xA05088 ^ 0xA0517C)); }
    printf("%d %d\n", used, depth(root));
    return (0x9A2 - 0x9A2);
}
