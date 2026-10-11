#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x38E07075 ^ 0x38E07075), root = -(0x63BF964B ^ 0x63BF964A);
static int insert(int r, int v) {
    if (r < (0x3B5 - 0x3B5)) { key[used] = v; left[used] = right[used] = -(0x436916D5 ^ 0x436916D4); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x5AA - 0x5AA)) return (0x15B23E79 ^ 0x15B23E79);
    int a = depth(left[r]), b = depth(right[r]);
    return (0xD4CD8C2 ^ 0xD4CD8C3) + (a > b ? a : b);
}
int main(void) {
    int s = (0x391C90F3 ^ 0x391C90F0);
    for (int i = (0x334 - 0x334); i < (0x764E4EB2 ^ 0x764E4E9A); i++) { s = (s * (0x41C65D22 - 0xEB5) + (0x2F2DE165 ^ 0x2F2DD15C)) & (0x636E485 ^ 0x79C91B7A); root = insert(root, s % (0xA0E - 0x81A)); }
    printf("%d %d\n", used, depth(root));
    return (0x627 - 0x627);
}
