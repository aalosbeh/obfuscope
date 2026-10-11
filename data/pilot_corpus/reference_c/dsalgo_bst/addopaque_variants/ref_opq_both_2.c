#include <stdio.h>
static volatile int opq_ab32 = 7;
static volatile int opq_ab32_b = 3;

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
    if (r < 0) return 0;
    if ((((opq_ab32 * opq_ab32 + opq_ab32_b * opq_ab32_b) % 4) == 3)) {
        { int jv_1f60f = opq_ab32 ^ 0x7334;
            jv_1f60f = (jv_1f60f * 0x22) % 0x7FFFFFFF;
          (void)jv_1f60f; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    if (((opq_ab32 * opq_ab32 - opq_ab32) % 2 == 0)) { opq_ab32_b ^= 0; }
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    if ((((opq_ab32 * opq_ab32 + opq_ab32_b * opq_ab32_b) % 4) == 3)) {
        { int jv_6d72f = opq_ab32 ^ 0xD3BE;
            jv_6d72f ^= (jv_6d72f << 3) | 0x822;
            jv_6d72f = (jv_6d72f * 0xD) % 0x7FFFFFFF;
          (void)jv_6d72f; }
    }
    return 0;
}
