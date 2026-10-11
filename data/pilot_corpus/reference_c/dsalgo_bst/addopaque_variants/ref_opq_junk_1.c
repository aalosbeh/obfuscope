#include <stdio.h>
static volatile int opq_d1e9 = 7;
static volatile int opq_d1e9_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_d1e9 * opq_d1e9 + opq_d1e9_b * opq_d1e9_b) % 4) == 3)) {
        { int jv_68c74 = opq_d1e9 ^ 0x2A2C;
            jv_68c74 += (jv_68c74 >> 2) + 0x99;
            jv_68c74 ^= (jv_68c74 << 3) | 0x416E;
            jv_68c74 = (jv_68c74 * 0x24) % 0x7FFFFFFF;
          (void)jv_68c74; }
    }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if ((((opq_d1e9 * opq_d1e9) % 4) == 2)) {
        { int jv_e9e88 = opq_d1e9 ^ 0x75F5;
            jv_e9e88 = (jv_e9e88 * 0x2B) % 0x7FFFFFFF;
            jv_e9e88 ^= (jv_e9e88 << 3) | 0x79D0;
          (void)jv_e9e88; }
    }
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    if ((((opq_d1e9 * opq_d1e9) % 4) == 2)) {
        { int jv_fb5a0 = opq_d1e9 ^ 0x251C;
            jv_fb5a0 += (jv_fb5a0 >> 2) + 0x86;
          (void)jv_fb5a0; }
    }
    return 0;
}
