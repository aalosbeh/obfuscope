#include <stdio.h>
static volatile int opq_819e = 7;
static volatile int opq_819e_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_819e * opq_819e + opq_819e_b * opq_819e_b) % 4) == 3)) {
        { int jv_5ea8c = opq_819e ^ 0xF062;
            jv_5ea8c = (jv_5ea8c * 0x10) % 0x7FFFFFFF;
            jv_5ea8c ^= (jv_5ea8c << 3) | 0xB382;
          (void)jv_5ea8c; }
    }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    if ((((opq_819e * opq_819e) % 4) == 2)) {
        { int jv_29d80 = opq_819e ^ 0xE2AD;
            jv_29d80 = (jv_29d80 * 0x25) % 0x7FFFFFFF;
          (void)jv_29d80; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_819e * opq_819e) % 4) == 2)) {
        { int jv_b5950 = opq_819e ^ 0x976E;
            jv_b5950 += (jv_b5950 >> 2) + 0x85;
            jv_b5950 ^= (jv_b5950 << 3) | 0xBBEB;
          (void)jv_b5950; }
    }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
