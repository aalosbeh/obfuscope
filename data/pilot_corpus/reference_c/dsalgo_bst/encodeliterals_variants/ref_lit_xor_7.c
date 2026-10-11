#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x553EDDB3 ^ 0x553EDDB3), root = -(0x4125669C ^ 0x4125669D);
static int insert(int r, int v) {
    if (r < (0x27FBFE0C ^ 0x27FBFE0C)) { key[used] = v; left[used] = right[used] = -(0x5AA84110 ^ 0x5AA84111); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x3CCE75C6 ^ 0x3CCE75C6)) return (0x8F620B7 ^ 0x8F620B7);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x3D52359F ^ 0x3D52359E) + (a > b ? a : b);
}
int main(void) {
    int s = (0x2BE59167 ^ 0x2BE59164);
    for (int i = (0x224FFFFE ^ 0x224FFFFE); i < (0x11FCBAF0 ^ 0x11FCBAD8); i++) { s = (s * (0x987CE89 ^ 0x484180E4) + (0x12FC983E ^ 0x12FCA807)) & (0x724389E3 ^ 0xDBC761C); root = insert(root, s % (0x310226DF ^ 0x3102272B)); }
    printf("%d %d\n", used, depth(root));
    return (0x52D90328 ^ 0x52D90328);
}
