#include <stdio.h>
static volatile int opq_37a8 = 7;
static volatile int opq_37a8_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if ((((opq_37a8 * opq_37a8 + opq_37a8_b * opq_37a8_b) % 4) == 3)) {
        { int jv_1503c = opq_37a8 ^ 0x1A55;
            jv_1503c += (jv_1503c >> 2) + 0x23;
            jv_1503c ^= (jv_1503c << 3) | 0x1448;
          (void)jv_1503c; }
    }
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_37a8 * opq_37a8) % 4) == 2)) {
        { int jv_e4ac0 = opq_37a8 ^ 0xB807;
            jv_e4ac0 = (jv_e4ac0 * 0x3B) % 0x7FFFFFFF;
            jv_e4ac0 ^= (jv_e4ac0 << 3) | 0xECB0;
            jv_e4ac0 += (jv_e4ac0 >> 2) + 0xFC;
          (void)jv_e4ac0; }
    }
    int s = 3;
    if ((((opq_37a8 * opq_37a8) % 4) == 2)) {
        { int jv_39f53 = opq_37a8 ^ 0x9A5F;
            jv_39f53 += (jv_39f53 >> 2) + 0xBB;
          (void)jv_39f53; }
    }
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
