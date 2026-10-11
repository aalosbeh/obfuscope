#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x47E - 0x47E), root = -(0xF0E - 0xF0D);
static int insert(int r, int v) {
    if (r < (0x368 - 0x368)) { key[used] = v; left[used] = right[used] = -(0x284 - 0x283); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x58A - 0x58A)) return (0x373 - 0x373);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x4B4 - 0x4B3) + (a > b ? a : b);
}
int main(void) {
    int s = (0x406 - 0x403);
    for (int i = (0xB90 - 0xB90); i < (0xD2B - 0xD03); i++) { s = (s * (0x41C64F66 - 0xF9) + (0x3102 - 0xC9)) & (0x800002C5 - 0x2C6); root = insert(root, s % (0xB58 - 0x964)); }
    printf("%d %d\n", used, depth(root));
    return (0x898 - 0x898);
}
