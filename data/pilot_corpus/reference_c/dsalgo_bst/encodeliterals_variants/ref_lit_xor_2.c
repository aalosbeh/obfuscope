#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x76919D79 ^ 0x76919D79), root = -(0x7999C65A ^ 0x7999C65B);
static int insert(int r, int v) {
    if (r < (0x7C058EEB ^ 0x7C058EEB)) { key[used] = v; left[used] = right[used] = -(0x5C26C884 ^ 0x5C26C885); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x613DCB03 ^ 0x613DCB03)) return (0x569DE778 ^ 0x569DE778);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x364AC17 ^ 0x364AC16) + (a > b ? a : b);
}
int main(void) {
    int s = (0x5B0106F9 ^ 0x5B0106FA);
    for (int i = (0x7981116D ^ 0x7981116D); i < (0x229F7754 ^ 0x229F777C); i++) { s = (s * (0x3F7B6ECB ^ 0x7EBD20A6) + (0x686814F5 ^ 0x686824CC)) & (0x28F89270 ^ 0x57076D8F); root = insert(root, s % (0x32C1B2DF ^ 0x32C1B32B)); }
    printf("%d %d\n", used, depth(root));
    return (0x1F8C4125 ^ 0x1F8C4125);
}
