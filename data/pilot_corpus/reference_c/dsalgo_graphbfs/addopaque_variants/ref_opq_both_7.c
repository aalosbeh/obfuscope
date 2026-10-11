#include <stdio.h>
static volatile int opq_5bf4 = 7;
static volatile int opq_5bf4_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_5bf4 * opq_5bf4 + opq_5bf4_b * opq_5bf4_b) % 4) == 3)) {
        { int jv_4e6c1 = opq_5bf4 ^ 0xC9E;
            jv_4e6c1 += (jv_4e6c1 >> 2) + 0xCF;
            jv_4e6c1 ^= (jv_4e6c1 << 3) | 0xA4E3;
          (void)jv_4e6c1; }
    }
    int head = 0, tail = 0;
    if ((((opq_5bf4 * (opq_5bf4 + 1)) % 2) == 0)) { opq_5bf4_b ^= 0; }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if ((((opq_5bf4 * opq_5bf4 + opq_5bf4_b * opq_5bf4_b) % 4) == 3)) {
                { int jv_59aea = opq_5bf4 ^ 0x1F22;
                    jv_59aea = (jv_59aea * 0x31) % 0x7FFFFFFF;
                    jv_59aea ^= (jv_59aea << 3) | 0x1D1A;
                  (void)jv_59aea; }
            }
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if ((((opq_5bf4 * opq_5bf4) % 4) == 2)) {
        { int jv_14ec5 = opq_5bf4 ^ 0x85C3;
            jv_14ec5 = (jv_14ec5 * 0x1D) % 0x7FFFFFFF;
            jv_14ec5 += (jv_14ec5 >> 2) + 0x3A;
          (void)jv_14ec5; }
    }
    return 0;
}
