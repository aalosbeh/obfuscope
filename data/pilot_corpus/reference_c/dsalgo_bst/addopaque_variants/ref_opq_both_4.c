#include <stdio.h>
static volatile int opq_22d1 = 7;
static volatile int opq_22d1_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_22d1 * opq_22d1 + opq_22d1_b * opq_22d1_b) % 4) == 3)) {
        { int jv_477cb = opq_22d1 ^ 0x83B1;
            jv_477cb += (jv_477cb >> 2) + 0x5F;
          (void)jv_477cb; }
    }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_22d1 * opq_22d1 + opq_22d1_b * opq_22d1_b) % 4) == 3)) {
        { int jv_ea140 = opq_22d1 ^ 0x18A0;
            jv_ea140 ^= (jv_ea140 << 3) | 0x286E;
          (void)jv_ea140; }
    }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    if ((((opq_22d1 * opq_22d1) % 4) == 2)) {
        { int jv_908bb = opq_22d1 ^ 0xDD53;
            jv_908bb = (jv_908bb * 0x18) % 0x7FFFFFFF;
            jv_908bb += (jv_908bb >> 2) + 0x6D;
          (void)jv_908bb; }
    }
    return 0;
}
