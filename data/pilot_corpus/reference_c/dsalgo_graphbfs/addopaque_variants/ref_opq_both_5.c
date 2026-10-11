#include <stdio.h>
static volatile int opq_d8a5 = 7;
static volatile int opq_d8a5_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_d8a5 * (opq_d8a5 + 1)) % 2) == 0)) { opq_d8a5_b ^= 0; }
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_d8a5 * opq_d8a5) % 4) == 2)) {
        { int jv_a45d9 = opq_d8a5 ^ 0xE8BA;
            jv_a45d9 += (jv_a45d9 >> 2) + 0xD2;
          (void)jv_a45d9; }
    }
    int head = 0, tail = 0;
    if ((((opq_d8a5 * opq_d8a5 + opq_d8a5_b * opq_d8a5_b) % 4) == 3)) {
        { int jv_49586 = opq_d8a5 ^ 0x5D5C;
            jv_49586 = (jv_49586 * 0x9) % 0x7FFFFFFF;
            jv_49586 += (jv_49586 >> 2) + 0x4C;
            jv_49586 ^= (jv_49586 << 3) | 0x7774;
          (void)jv_49586; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if (((opq_d8a5 * opq_d8a5 - opq_d8a5) % 2 == 0)) { opq_d8a5_b ^= 0; }
    return 0;
}
