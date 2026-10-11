#include <stdio.h>
static volatile int opq_97d6 = 7;
static volatile int opq_97d6_b = 3;

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
    if ((((opq_97d6 * opq_97d6) % 4) == 2)) {
        { int jv_f266a = opq_97d6 ^ 0xE54A;
            jv_f266a = (jv_f266a * 0x24) % 0x7FFFFFFF;
            jv_f266a += (jv_f266a >> 2) + 0xB7;
          (void)jv_f266a; }
    }
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    if ((((opq_97d6 * opq_97d6) % 4) == 2)) {
        { int jv_8a8d7 = opq_97d6 ^ 0x7B29;
            jv_8a8d7 = (jv_8a8d7 * 0x6) % 0x7FFFFFFF;
            jv_8a8d7 ^= (jv_8a8d7 << 3) | 0xD347;
            jv_8a8d7 += (jv_8a8d7 >> 2) + 0x2E;
          (void)jv_8a8d7; }
    }
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", used, depth(root));
    if ((((opq_97d6 * opq_97d6) % 4) == 2)) {
        { int jv_19f63 = opq_97d6 ^ 0x343D;
            jv_19f63 ^= (jv_19f63 << 3) | 0x9168;
            jv_19f63 += (jv_19f63 >> 2) + 0xE9;
          (void)jv_19f63; }
    }
    return 0;
}
