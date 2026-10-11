#include <stdio.h>
static volatile int opq_22ab = 7;
static volatile int opq_22ab_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_22ab * opq_22ab + opq_22ab) % 2) == 0)) { opq_22ab_b ^= 0; }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    if ((((opq_22ab * opq_22ab + opq_22ab_b * opq_22ab_b) % 4) == 3)) {
        { int jv_b2b7b = opq_22ab ^ 0x50F2;
            jv_b2b7b += (jv_b2b7b >> 2) + 0xE4;
          (void)jv_b2b7b; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if (((opq_22ab * opq_22ab - opq_22ab) % 2 == 0)) { opq_22ab_b ^= 0; }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
