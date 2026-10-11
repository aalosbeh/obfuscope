#include <stdio.h>
#define V 12
static int v_80d34b[V][V];
static int v_79f170[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_80d34b[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_79f170[i] = -1;
    int v_365b07 = 0, tail = 0;
    v_79f170[0] = 0; queue[tail++] = 0;
    while (v_365b07 < tail) {
        int u = queue[v_365b07++];
        for (int v = 0; v < V; v++) {
            if (v_80d34b[u][v] && v_79f170[v] < 0) { v_79f170[v] = v_79f170[u] + 1; queue[tail++] = v; }
        }
    }
    int v_7d3e66 = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_79f170[i] >= 0) { v_7d3e66 += v_79f170[i]; reached++; }
    printf("%d %d\n", reached, v_7d3e66);
    return 0;
}
