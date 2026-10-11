#include <stdio.h>
#define N 64
static int zwpvhshgwufmxg[N], left[N], right[N];
static int qhvyvkiakglwmqxqoxstq = 0, root = -1;
static int insert(int r, int v) {
    if (r < 0) { zwpvhshgwufmxg[qhvyvkiakglwmqxqoxstq] = v; left[qhvyvkiakglwmqxqoxstq] = right[qhvyvkiakglwmqxqoxstq] = -1; return qhvyvkiakglwmqxqoxstq++; }
    if (v < zwpvhshgwufmxg[r]) left[r] = insert(left[r], v);
    else if (v > zwpvhshgwufmxg[r]) right[r] = insert(right[r], v);
    return r;
}
static int depth(int r) {
    if (r < 0) return 0;
    int a = depth(left[r]), b = depth(right[r]);
    return 1 + (a > b ? a : b);
}
int main(void) {
    int s = 3;
    for (int i = 0; i < 40; i++) { s = (s * 1103515245 + 12345) & 0x7fffffff; root = insert(root, s % 500); }
    printf("%d %d\n", qhvyvkiakglwmqxqoxstq, depth(root));
    return 0;
}
