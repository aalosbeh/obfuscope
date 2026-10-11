#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0xBEC - 0xBEC), root = -(0x6CB7B40 ^ 0x6CB7B41);
static int insert(int r, int v) {
    if (r < (0x288F55A2 ^ 0x288F55A2)) { key[used] = v; left[used] = right[used] = -(0x9D9 - 0x9D8); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x284AA499 ^ 0x284AA499)) return (0x2456BF7C ^ 0x2456BF7C);
    int a = depth(left[r]), b = depth(right[r]);
    return (0xB35EBE7 ^ 0xB35EBE6) + (a > b ? a : b);
}
int main(void) {
    int s = (0x2DD - 0x2DA);
    for (int i = (0x1DCF4B00 ^ 0x1DCF4B00); i < (0x1A955205 ^ 0x1A95522D); i++) { s = (s * (0x21884DF6 ^ 0x604E039B) + (0x6696E6EE ^ 0x6696D6D7)) & (0x74121FE0 ^ 0xBEDE01F); root = insert(root, s % (0x3A8 - 0x1B4)); }
    printf("%d %d\n", used, depth(root));
    return (0xF05 - 0xF05);
}
