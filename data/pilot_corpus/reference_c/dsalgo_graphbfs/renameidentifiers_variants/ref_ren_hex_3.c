#include <stdio.h>
#define V 12
static int v_f7cd1a[V][V];
static int v_d93b1e[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_f7cd1a[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_d93b1e[i] = -1;
    int v_ddbaee = 0, tail = 0;
    v_d93b1e[0] = 0; queue[tail++] = 0;
    while (v_ddbaee < tail) {
        int u = queue[v_ddbaee++];
        for (int v = 0; v < V; v++) {
            if (v_f7cd1a[u][v] && v_d93b1e[v] < 0) { v_d93b1e[v] = v_d93b1e[u] + 1; queue[tail++] = v; }
        }
    }
    int v_f0fe07 = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_d93b1e[i] >= 0) { v_f0fe07 += v_d93b1e[i]; reached++; }
    printf("%d %d\n", reached, v_f0fe07);
    return 0;
}
