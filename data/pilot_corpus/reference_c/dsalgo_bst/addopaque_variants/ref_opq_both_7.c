#include <stdio.h>
static volatile int opq_f756 = 7;
static volatile int opq_f756_b = 3;

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
    if (((opq_f756 * opq_f756 - opq_f756) % 2 == 0)) { opq_f756_b ^= 0; }
    if (r < 0) return 0;
    if ((((opq_f756 * opq_f756 + opq_f756_b * opq_f756_b) % 4) == 3)) {
        { int jv_a078a = opq_f756 ^ 0x27D0;
            jv_a078a = (jv_a078a * 0x2E) % 0x7FFFFFFF;
            jv_a078a ^= (jv_a078a << 3) | 0xE77A;
          (void)jv_a078a; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_f756 * opq_f756 + opq_f756_b * opq_f756_b) % 4) == 3)) {
        { int jv_927f5 = opq_f756 ^ 0x4996;
            jv_927f5 += (jv_927f5 >> 2) + 0x89;
            jv_927f5 ^= (jv_927f5 << 3) | 0xA182;
          (void)jv_927f5; }
    }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
