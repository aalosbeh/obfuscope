#include <stdio.h>
#define V 12
static int v_3d0ee2[V][V];
static int v_ef97c0[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_3d0ee2[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_ef97c0[i] = -1;
    int v_ae03e2 = 0, tail = 0;
    v_ef97c0[0] = 0; queue[tail++] = 0;
    while (v_ae03e2 < tail) {
        int u = queue[v_ae03e2++];
        for (int v = 0; v < V; v++) {
            if (v_3d0ee2[u][v] && v_ef97c0[v] < 0) { v_ef97c0[v] = v_ef97c0[u] + 1; queue[tail++] = v; }
        }
    }
    int v_3e9f2c = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_ef97c0[i] >= 0) { v_3e9f2c += v_ef97c0[i]; reached++; }
    printf("%d %d\n", reached, v_3e9f2c);
    return 0;
}
