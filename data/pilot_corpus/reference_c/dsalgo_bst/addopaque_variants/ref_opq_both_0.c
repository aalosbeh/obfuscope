#include <stdio.h>
static volatile int opq_d122 = 7;
static volatile int opq_d122_b = 3;

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
    if ((((opq_d122 * opq_d122 + opq_d122_b * opq_d122_b) % 4) == 3)) {
        { int jv_a915b = opq_d122 ^ 0x67C8;
            jv_a915b = (jv_a915b * 0x36) % 0x7FFFFFFF;
            jv_a915b ^= (jv_a915b << 3) | 0x21C9;
            jv_a915b += (jv_a915b >> 2) + 0x1E;
          (void)jv_a915b; }
    }
    if (r < 0) return 0;
    if ((((opq_d122 * opq_d122) % 4) == 2)) {
        { int jv_9f947 = opq_d122 ^ 0x550F;
            jv_9f947 += (jv_9f947 >> 2) + 0x1E;
          (void)jv_9f947; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    if (((opq_d122 * opq_d122 - opq_d122) % 2 == 0)) { opq_d122_b ^= 0; }
    return 0;
}
