#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0xB31 - 0xB31), root = -(0xF9F - 0xF9E);
static int insert(int r, int v) {
    if (r < (0x81C - 0x81C)) { key[used] = v; left[used] = right[used] = -(0x680 - 0x67F); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x4E7 - 0x4E7)) return (0x329 - 0x329);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x279 - 0x278) + (a > b ? a : b);
}
int main(void) {
    int s = (0x900 - 0x8FD);
    for (int i = (0xBDB - 0xBDB); i < (0x68 - 0x40); i++) { s = (s * (0x41C652D2 - 0x465) + (0x37AD - 0x774)) & (0x80000112 - 0x113); root = insert(root, s % (0x968 - 0x774)); }
    printf("%d %d\n", used, depth(root));
    return (0x5FA - 0x5FA);
}
