#include <stdio.h>
#define V 12
static int fwkzygkzaeznvslg[V][V];
static int axxiupwbkbwwtavqtv[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) fwkzygkzaeznvslg[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) axxiupwbkbwwtavqtv[i] = -1;
    int gttvopaeofbgnzfvf = 0, tail = 0;
    axxiupwbkbwwtavqtv[0] = 0; queue[tail++] = 0;
    while (gttvopaeofbgnzfvf < tail) {
        int u = queue[gttvopaeofbgnzfvf++];
        for (int v = 0; v < V; v++) {
            if (fwkzygkzaeznvslg[u][v] && axxiupwbkbwwtavqtv[v] < 0) { axxiupwbkbwwtavqtv[v] = axxiupwbkbwwtavqtv[u] + 1; queue[tail++] = v; }
        }
    }
    int ydpzyxonvxurma = 0, reached = 0;
    for (int i = 0; i < V; i++) if (axxiupwbkbwwtavqtv[i] >= 0) { ydpzyxonvxurma += axxiupwbkbwwtavqtv[i]; reached++; }
    printf("%d %d\n", reached, ydpzyxonvxurma);
    return 0;
}
