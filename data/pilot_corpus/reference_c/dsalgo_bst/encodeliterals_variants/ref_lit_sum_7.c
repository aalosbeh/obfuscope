#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x92 - 0x92), root = -(0x120 - 0x11F);
static int insert(int r, int v) {
    if (r < (0xA65 - 0xA65)) { key[used] = v; left[used] = right[used] = -(0x680 - 0x67F); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0xCBC - 0xCBC)) return (0x880 - 0x880);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x958 - 0x957) + (a > b ? a : b);
}
int main(void) {
    int s = (0x845 - 0x842);
    for (int i = (0xE49 - 0xE49); i < (0x1CB - 0x1A3); i++) { s = (s * (0x41C6557D - 0x710) + (0x3220 - 0x1E7)) & (0x8000001C - 0x1D); root = insert(root, s % (0x777 - 0x583)); }
    printf("%d %d\n", used, depth(root));
    return (0x142 - 0x142);
}
