#include <stdio.h>
#define V 12
static int v_890a8c[V][V];
static int v_2d57a5[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) v_890a8c[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) v_2d57a5[i] = -1;
    int v_84a646 = 0, tail = 0;
    v_2d57a5[0] = 0; queue[tail++] = 0;
    while (v_84a646 < tail) {
        int u = queue[v_84a646++];
        for (int v = 0; v < V; v++) {
            if (v_890a8c[u][v] && v_2d57a5[v] < 0) { v_2d57a5[v] = v_2d57a5[u] + 1; queue[tail++] = v; }
        }
    }
    int v_4e9f4a = 0, reached = 0;
    for (int i = 0; i < V; i++) if (v_2d57a5[i] >= 0) { v_4e9f4a += v_2d57a5[i]; reached++; }
    printf("%d %d\n", reached, v_4e9f4a);
    return 0;
}
