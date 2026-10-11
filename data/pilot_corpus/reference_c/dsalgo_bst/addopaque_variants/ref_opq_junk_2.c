#include <stdio.h>
static volatile int opq_e961 = 7;
static volatile int opq_e961_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_e961 * opq_e961 + opq_e961_b * opq_e961_b) % 4) == 3)) {
        { int jv_167d5 = opq_e961 ^ 0x7C48;
            jv_167d5 += (jv_167d5 >> 2) + 0x25;
            jv_167d5 ^= (jv_167d5 << 3) | 0xC4CE;
            jv_167d5 = (jv_167d5 * 0x3E) % 0x7FFFFFFF;
          (void)jv_167d5; }
    }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    if ((((opq_e961 * opq_e961) % 4) == 2)) {
        { int jv_140a6 = opq_e961 ^ 0x72D2;
            jv_140a6 = (jv_140a6 * 0x1F) % 0x7FFFFFFF;
          (void)jv_140a6; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    if ((((opq_e961 * opq_e961 + opq_e961_b * opq_e961_b) % 4) == 3)) {
        { int jv_2e525 = opq_e961 ^ 0x8B16;
            jv_2e525 ^= (jv_2e525 << 3) | 0x196A;
            jv_2e525 += (jv_2e525 >> 2) + 0xAA;
            jv_2e525 = (jv_2e525 * 0x2D) % 0x7FFFFFFF;
          (void)jv_2e525; }
    }
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
