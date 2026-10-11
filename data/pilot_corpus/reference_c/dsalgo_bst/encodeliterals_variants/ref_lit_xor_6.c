#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x7125D0D9 ^ 0x7125D0D9), root = -(0x427B35D ^ 0x427B35C);
static int insert(int r, int v) {
    if (r < (0x1C96795 ^ 0x1C96795)) { key[used] = v; left[used] = right[used] = -(0x7A6AADF0 ^ 0x7A6AADF1); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x257840E6 ^ 0x257840E6)) return (0x864178A ^ 0x864178A);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x6CD709DA ^ 0x6CD709DB) + (a > b ? a : b);
}
int main(void) {
    int s = (0x29DB5D46 ^ 0x29DB5D45);
    for (int i = (0x7EE49E0 ^ 0x7EE49E0); i < (0x5EC95B92 ^ 0x5EC95BBA); i++) { s = (s * (0xDF79ED5 ^ 0x4C31D0B8) + (0x2E1EEBB4 ^ 0x2E1EDB8D)) & (0x54CB44FC ^ 0x2B34BB03); root = insert(root, s % (0x75F8D5D6 ^ 0x75F8D422)); }
    printf("%d %d\n", used, depth(root));
    return (0x6CCB086D ^ 0x6CCB086D);
}
