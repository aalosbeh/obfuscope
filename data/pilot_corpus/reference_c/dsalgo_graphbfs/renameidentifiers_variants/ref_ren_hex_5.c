#include <stdio.h>
#define V 12
static int v_62fb7f[V][V];
static int v_3cf9e7[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_62fb7f[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_3cf9e7[i] = -1;
    int v_25d7d5 = 0, tail = 0;
    v_3cf9e7[0] = 0; queue[tail++] = 0;
    while (v_25d7d5 < tail) {
        int u = queue[v_25d7d5++];
        for (int v = 0; v < V; v++) {
            if (v_62fb7f[u][v] && v_3cf9e7[v] < 0) { v_3cf9e7[v] = v_3cf9e7[u] + 1; queue[tail++] = v; }
        }
    }
    int v_a508c8 = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_3cf9e7[i] >= 0) { v_a508c8 += v_3cf9e7[i]; reached++; }
    printf("%d %d\n", reached, v_a508c8);
    return 0;
}
