#include <stdio.h>
#define V 12
static int v_afc4a9[V][V];
static int v_e51eb3[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_afc4a9[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_e51eb3[i] = -1;
    int v_d7a4c4 = 0, tail = 0;
    v_e51eb3[0] = 0; queue[tail++] = 0;
    while (v_d7a4c4 < tail) {
        int u = queue[v_d7a4c4++];
        for (int v = 0; v < V; v++) {
            if (v_afc4a9[u][v] && v_e51eb3[v] < 0) { v_e51eb3[v] = v_e51eb3[u] + 1; queue[tail++] = v; }
        }
    }
    int v_78f309 = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_e51eb3[i] >= 0) { v_78f309 += v_e51eb3[i]; reached++; }
    printf("%d %d\n", reached, v_78f309);
    return 0;
}
