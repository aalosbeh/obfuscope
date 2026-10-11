#include <stdio.h>
#define N 64
static int key[N], left[N], right[N];
static int used = (0x5E6B34F0 ^ 0x5E6B34F0), root = -(0x423D9FA6 ^ 0x423D9FA7);
static int insert(int r, int v) {
    if (r < (0xBC819FF ^ 0xBC819FF)) { key[used] = v; left[used] = right[used] = -(0x76C2104B ^ 0x76C2104A); return used++; }
    if (v < key[r]) left[r] = insert(left[r], v);
    else if (v > key[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < (0x4D406C78 ^ 0x4D406C78)) return (0x48E7F539 ^ 0x48E7F539);
    int a = depth(left[r]), b = depth(right[r]);
    return (0x747CDA47 ^ 0x747CDA46) + (a > b ? a : b);
}
int main(void) {
    int s = (0x7124857D ^ 0x7124857E);
    for (int i = (0x45A8EF03 ^ 0x45A8EF03); i < (0x533926 ^ 0x53390E); i++) { s = (s * (0x503521F1 ^ 0x11F36F9C) + (0x64C8180D ^ 0x64C82834)) & (0x78CAAD0E ^ 0x73552F1); root = insert(root, s % (0x4F7E6731 ^ 0x4F7E66C5)); }
    printf("%d %d\n", used, depth(root));
    return (0x4B73AEC6 ^ 0x4B73AEC6);
}
