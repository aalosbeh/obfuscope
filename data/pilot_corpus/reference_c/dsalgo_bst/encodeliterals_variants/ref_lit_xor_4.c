#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x676962CF ^ 0x676962CF), root = -(0x7B153689 ^ 0x7B153688);
static int insert(int r, int v) {
    if (r < (0x5A577D29 ^ 0x5A577D29)) { key[used] = v; left[used] = right[used] = -(0x67ADD168 ^ 0x67ADD169); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x3C025C6F ^ 0x3C025C6F)) return (0x6E692B3E ^ 0x6E692B3E);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x5E4D2CD1 ^ 0x5E4D2CD0) + (a > b ? a : b);
}
int main(void) {
    int s = (0x6561743F ^ 0x6561743C);
    for (int i = (0x3B82193A ^ 0x3B82193A); i < (0x5B1C29C3 ^ 0x5B1C29EB); i++) { s = (s * (0x5D7226A5 ^ 0x1CB468C8) + (0x4FBDFA1 ^ 0x4FBEF98)) & (0x723A12F5 ^ 0xDC5ED0A); root = insert(root, s % (0x142708DE ^ 0x1427092A)); }
    printf("%d %d\n", used, depth(root));
    return (0x1028F654 ^ 0x1028F654);
}
