#include <stdio.h>
static volatile int opq_27b9 = 7;
static volatile int opq_27b9_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_27b9 * opq_27b9 + opq_27b9_b * opq_27b9_b) % 4) == 3)) {
        { int jv_908b6 = opq_27b9 ^ 0x55C;
            jv_908b6 = (jv_908b6 * 0x1C) % 0x7FFFFFFF;
            jv_908b6 += (jv_908b6 >> 2) + 0x65;
          (void)jv_908b6; }
    }
    int head = 0, tail = 0;
    if ((((opq_27b9 * (opq_27b9 + 1)) % 2) == 0)) { opq_27b9_b ^= 0; }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        if ((((opq_27b9 * (opq_27b9 + 1)) % 2) == 0)) { opq_27b9_b ^= 0; }
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if ((((opq_27b9 * (opq_27b9 + 1)) % 2) == 0)) { opq_27b9_b ^= 0; }
    return 0;
}
