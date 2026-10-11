#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x5892B9F2 ^ 0x5892B9F2), root = -(0x2EBD6C64 ^ 0x2EBD6C65);
static int insert(int r, int v) {
    if (r < (0x31830FC5 ^ 0x31830FC5)) { key[used] = v; left[used] = right[used] = -(0xBA46FC9 ^ 0xBA46FC8); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x412E5271 ^ 0x412E5271)) return (0xB6D2C15 ^ 0xB6D2C15);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x5C99A739 ^ 0x5C99A738) + (a > b ? a : b);
}
int main(void) {
    int s = (0x2F558A6D ^ 0x2F558A6E);
    for (int i = (0x30F624AD ^ 0x30F624AD); i < (0x25865D6C ^ 0x25865D44); i++) { s = (s * (0xB2D2710 ^ 0x4AEB697D) + (0x4EEF8DEC ^ 0x4EEFBDD5)) & (0x1B02390 ^ 0x7E4FDC6F); root = insert(root, s % (0x27EE1A14 ^ 0x27EE1BE0)); }
    printf("%d %d\n", used, depth(root));
    return (0x33C50A3 ^ 0x33C50A3);
}
