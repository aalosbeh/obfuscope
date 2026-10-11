#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x279378B4 ^ 0x279378B4), root = -(0x15C - 0x15B);
static int insert(int r, int v) {
    if (r < (0x79B28136 ^ 0x79B28136)) { key[used] = v; left[used] = right[used] = -(0xBE1 - 0xBE0); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x7B549C4E ^ 0x7B549C4E)) return (0xC58 - 0xC58);
    int a = depth(left[r]), b = depth(right[r]);
    return (0xED2 - 0xED1) + (a > b ? a : b);
}
int main(void) {
    int s = (0x826 - 0x823);
    for (int i = (0xF60 - 0xF60); i < (0x5A818A29 ^ 0x5A818A01); i++) { s = (s * (0x41C65081 - 0x214) + (0x3EFEC2D6 ^ 0x3EFEF2EF)) & (0x164FAF4B ^ 0x69B050B4); root = insert(root, s % (0x1FFD586A ^ 0x1FFD599E)); }
    printf("%d %d\n", used, depth(root));
    return (0x7675A18B ^ 0x7675A18B);
}
