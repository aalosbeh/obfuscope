#include <stdio.h>
static volatile int opq_b849 = 7;
static volatile int opq_b849_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if (((opq_b849 * opq_b849 - opq_b849) % 2 == 0)) { opq_b849_b ^= 0; }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if (((opq_b849 * opq_b849 - opq_b849) % 2 == 0)) { opq_b849_b ^= 0; }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_b849 * (opq_b849 + 1)) % 2) == 0)) { opq_b849_b ^= 0; }
        int u = queue[head++];
        if (((opq_b849 * opq_b849 - opq_b849) % 2 == 0)) { opq_b849_b ^= 0; }
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
