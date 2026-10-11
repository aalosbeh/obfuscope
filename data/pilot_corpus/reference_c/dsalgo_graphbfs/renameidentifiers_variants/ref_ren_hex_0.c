#include <stdio.h>
#define V 12
static int v_7a3c4f[V][V];
static int v_aee761[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_7a3c4f[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_aee761[i] = -1;
    int v_e7cffe = 0, tail = 0;
    v_aee761[0] = 0; queue[tail++] = 0;
    while (v_e7cffe < tail) {
        int u = queue[v_e7cffe++];
        for (int v = 0; v < V; v++) {
            if (v_7a3c4f[u][v] && v_aee761[v] < 0) { v_aee761[v] = v_aee761[u] + 1; queue[tail++] = v; }
        }
    }
    int v_d44ab4 = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_aee761[i] >= 0) { v_d44ab4 += v_aee761[i]; reached++; }
    printf("%d %d\n", reached, v_d44ab4);
    return 0;
}
