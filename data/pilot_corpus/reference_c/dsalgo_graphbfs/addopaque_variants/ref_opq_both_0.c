#include <stdio.h>
static volatile int opq_2e81 = 7;
static volatile int opq_2e81_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_2e81 * (opq_2e81 + 1)) % 2) == 0)) { opq_2e81_b ^= 0; }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    if ((((opq_2e81 * opq_2e81 + opq_2e81_b * opq_2e81_b) % 4) == 3)) {
        { int jv_1477c = opq_2e81 ^ 0xB4D8;
            jv_1477c += (jv_1477c >> 2) + 0x50;
          (void)jv_1477c; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        if ((((opq_2e81 * opq_2e81) % 4) == 2)) {
            { int jv_839eb = opq_2e81 ^ 0x788;
                jv_839eb += (jv_839eb >> 2) + 0x31;
              (void)jv_839eb; }
        }
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    if ((((opq_2e81 * opq_2e81 + opq_2e81) % 2) == 0)) { opq_2e81_b ^= 0; }
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
