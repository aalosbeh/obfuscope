#include <stdio.h>
static volatile int opq_9249 = 7;
static volatile int opq_9249_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_9249 * opq_9249 + opq_9249_b * opq_9249_b) % 4) == 3)) {
        { int jv_1672d = opq_9249 ^ 0xB129;
            jv_1672d ^= (jv_1672d << 3) | 0x4713;
            jv_1672d += (jv_1672d >> 2) + 0xB0;
            jv_1672d = (jv_1672d * 0x3E) % 0x7FFFFFFF;
          (void)jv_1672d; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    if ((((opq_9249 * opq_9249) % 4) == 2)) {
        { int jv_a52bf = opq_9249 ^ 0x85F9;
            jv_a52bf += (jv_a52bf >> 2) + 0xAA;
          (void)jv_a52bf; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_9249 * opq_9249 + opq_9249) % 2) == 0)) { opq_9249_b ^= 0; }
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if ((((opq_9249 * opq_9249) % 4) == 2)) {
                { int jv_1e1d0 = opq_9249 ^ 0x2595;
                    jv_1e1d0 = (jv_1e1d0 * 0x32) % 0x7FFFFFFF;
                    jv_1e1d0 ^= (jv_1e1d0 << 3) | 0x625D;
                    jv_1e1d0 += (jv_1e1d0 >> 2) + 0x8A;
                  (void)jv_1e1d0; }
            }
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
