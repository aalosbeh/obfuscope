#include <stdio.h>
#define V 12
static int v_c5f8f6[V][V];
static int v_d2050d[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_c5f8f6[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_d2050d[i] = -1;
    int v_4ff12f = 0, tail = 0;
    v_d2050d[0] = 0; queue[tail++] = 0;
    while (v_4ff12f < tail) {
        int u = queue[v_4ff12f++];
        for (int v = 0; v < V; v++) {
            if (v_c5f8f6[u][v] && v_d2050d[v] < 0) { v_d2050d[v] = v_d2050d[u] + 1; queue[tail++] = v; }
        }
    }
    int v_8cdd9b = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_d2050d[i] >= 0) { v_8cdd9b += v_d2050d[i]; reached++; }
    printf("%d %d\n", reached, v_8cdd9b);
    return 0;
}
