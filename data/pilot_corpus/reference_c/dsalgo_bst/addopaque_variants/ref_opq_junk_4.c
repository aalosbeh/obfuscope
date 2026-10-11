#include <stdio.h>
static volatile int opq_b19d = 7;
static volatile int opq_b19d_b = 3;

#define N 64
static int key[N], left[N], right[N];
static int used = 0, root = -1;
static int insert(int r, int v) {
    if ((((opq_b19d * opq_b19d + opq_b19d_b * opq_b19d_b) % 4) == 3)) {
        { int jv_44c51 = opq_b19d ^ 0xC7BB;
            jv_44c51 = (jv_44c51 * 0x3E) % 0x7FFFFFFF;
            jv_44c51 ^= (jv_44c51 << 3) | 0xBFBA;
            jv_44c51 += (jv_44c51 >> 2) + 0x61;
          (void)jv_44c51; }
    }
    if (r < 0) { key[used] = v; left[used] = right[used] = -1; return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    if ((((opq_b19d * opq_b19d) % 4) == 2)) {
        { int jv_68884 = opq_b19d ^ 0x5E65;
            jv_68884 += (jv_68884 >> 2) + 0xB;
            jv_68884 ^= (jv_68884 << 3) | 0x9728;
          (void)jv_68884; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_b19d * opq_b19d) % 4) == 2)) {
        { int jv_5452e = opq_b19d ^ 0xBAA2;
            jv_5452e ^= (jv_5452e << 3) | 0x65F1;
            jv_5452e = (jv_5452e * 0x2F) % 0x7FFFFFFF;
            jv_5452e += (jv_5452e >> 2) + 0x41;
          (void)jv_5452e; }
    }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    return 0;
}
