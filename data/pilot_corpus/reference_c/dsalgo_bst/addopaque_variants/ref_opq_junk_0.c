#include <stdio.h>
static volatile int opq_de13 = 7;
static volatile int opq_de13_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_de13 * opq_de13) % 4) == 2)) {
        { int jv_8acd0 = opq_de13 ^ 0x98AF;
            jv_8acd0 = (jv_8acd0 * 0x2A) % 0x7FFFFFFF;
          (void)jv_8acd0; }
    }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    if ((((opq_de13 * opq_de13 + opq_de13_b * opq_de13_b) % 4) == 3)) {
        { int jv_16d67 = opq_de13 ^ 0xE653;
            jv_16d67 += (jv_16d67 >> 2) + 0xCE;
          (void)jv_16d67; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    if ((((opq_de13 * opq_de13 + opq_de13_b * opq_de13_b) % 4) == 3)) {
        { int jv_e176e = opq_de13 ^ 0xB1F7;
            jv_e176e ^= (jv_e176e << 3) | 0x13E7;
          (void)jv_e176e; }
    }
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
