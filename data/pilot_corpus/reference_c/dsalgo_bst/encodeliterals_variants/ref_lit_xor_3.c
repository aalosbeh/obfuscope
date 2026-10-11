#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x794840F7 ^ 0x794840F7), root = -(0x2C869A7D ^ 0x2C869A7C);
static int insert(int r, int v) {
    if (r < (0x25D248E7 ^ 0x25D248E7)) { key[used] = v; left[used] = right[used] = -(0x5805BE0D ^ 0x5805BE0C); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x170EEC44 ^ 0x170EEC44)) return (0x22BEB7B9 ^ 0x22BEB7B9);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x281D510A ^ 0x281D510B) + (a > b ? a : b);
}
int main(void) {
    int s = (0x4C6042FF ^ 0x4C6042FC);
    for (int i = (0x7A323B67 ^ 0x7A323B67); i < (0x70CE62C8 ^ 0x70CE62E0); i++) { s = (s * (0x574C931B ^ 0x168ADD76) + (0x57E26402 ^ 0x57E2543B)) & (0x3052EBED ^ 0x4FAD1412); root = insert(root, s % (0x3A8DFAC4 ^ 0x3A8DFB30)); }
    printf("%d %d\n", used, depth(root));
    return (0x5BFEE1F3 ^ 0x5BFEE1F3);
}
