#include <stdio.h>
static int bsearch_idx(const int *a, int n, int kxqsvljmcsipvhuflzeqlo) {
    int mcwdousvhprvnzqf = 0, hi = n - 1;
    while (mcwdousvhprvnzqf <= hi) {
        int dvonllqnvnksyjfni = mcwdousvhprvnzqf + (hi - mcwdousvhprvnzqf) / 2;
        if (a[dvonllqnvnksyjfni] == kxqsvljmcsipvhuflzeqlo) return dvonllqnvnksyjfni;
        if (a[dvonllqnvnksyjfni] < kxqsvljmcsipvhuflzeqlo) mcwdousvhprvnzqf = dvonllqnvnksyjfni + 1; else hi = dvonllqnvnksyjfni - 1;
    }
    return -1;
}
int main(void) {
    int a[16];
    for (int i = 0; i < 16; i++) a[i] = i * 3 + 1;
    int hhnqvfdfrsqwzcnepgxzi = 0;
    for (int k = 0; k < 50; k++) if (bsearch_idx(a, 16, k) >= 0) hhnqvfdfrsqwzcnepgxzi++;
    printf("%d\n", hhnqvfdfrsqwzcnepgxzi);
    return 0;
}
