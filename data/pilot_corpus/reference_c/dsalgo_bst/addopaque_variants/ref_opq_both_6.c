#include <stdio.h>
static volatile int opq_def1 = 7;
static volatile int opq_def1_b = 3;

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
    if ((((opq_def1 * opq_def1) % 4) == 2)) {
        { int jv_49b5a = opq_def1 ^ 0x97E3;
            jv_49b5a ^= (jv_49b5a << 3) | 0x2727;
            jv_49b5a = (jv_49b5a * 0x2B) % 0x7FFFFFFF;
            jv_49b5a += (jv_49b5a >> 2) + 0x50;
          (void)jv_49b5a; }
    }
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    if ((((opq_def1 * opq_def1) % 4) == 2)) {
        { int jv_c2270 = opq_def1 ^ 0xFD38;
            jv_c2270 = (jv_c2270 * 0x35) % 0x7FFFFFFF;
          (void)jv_c2270; }
    }
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_def1 * opq_def1 + opq_def1_b * opq_def1_b) % 4) == 3)) {
        { int jv_4300f = opq_def1 ^ 0xEF2D;
            jv_4300f += (jv_4300f >> 2) + 0x20;
            jv_4300f = (jv_4300f * 0x2B) % 0x7FFFFFFF;
          (void)jv_4300f; }
    }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
