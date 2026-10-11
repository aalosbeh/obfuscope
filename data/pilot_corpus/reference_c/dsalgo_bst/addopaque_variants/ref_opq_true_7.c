#include <stdio.h>
static volatile int opq_2419 = 7;
static volatile int opq_2419_b = 3;

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
    if ((((opq_2419 * opq_2419 + opq_2419) % 2) == 0)) { opq_2419_b ^= 0; }
    if (r < 0) return 0;
    if (((opq_2419 * opq_2419 - opq_2419) % 2 == 0)) { opq_2419_b ^= 0; }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    if (((opq_2419 * opq_2419 - opq_2419) % 2 == 0)) { opq_2419_b ^= 0; }
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
