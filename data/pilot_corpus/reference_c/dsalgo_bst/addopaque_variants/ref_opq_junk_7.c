#include <stdio.h>
static volatile int opq_898b = 7;
static volatile int opq_898b_b = 3;

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
    if ((((opq_898b * opq_898b + opq_898b_b * opq_898b_b) % 4) == 3)) {
        { int jv_ddbd8 = opq_898b ^ 0xA028;
            jv_ddbd8 += (jv_ddbd8 >> 2) + 0x32;
            jv_ddbd8 = (jv_ddbd8 * 0x39) % 0x7FFFFFFF;
          (void)jv_ddbd8; }
    }
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    if ((((opq_898b * opq_898b) % 4) == 2)) {
        { int jv_e8ffb = opq_898b ^ 0x7CC8;
            jv_e8ffb ^= (jv_e8ffb << 3) | 0x3473;
            jv_e8ffb += (jv_e8ffb >> 2) + 0x4C;
            jv_e8ffb = (jv_e8ffb * 0x26) % 0x7FFFFFFF;
          (void)jv_e8ffb; }
    }
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    if ((((opq_898b * opq_898b) % 4) == 2)) {
        { int jv_15e61 = opq_898b ^ 0xAB68;
            jv_15e61 ^= (jv_15e61 << 3) | 0x9FDF;
          (void)jv_15e61; }
    }
    return 0;
}
