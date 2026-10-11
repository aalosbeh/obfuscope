#include <stdio.h>
static volatile int opq_82c0 = 7;
static volatile int opq_82c0_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if ((((opq_82c0 * opq_82c0 + opq_82c0) % 2) == 0)) { opq_82c0_b ^= 0; }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_82c0 * opq_82c0) % 4) == 2)) {
        { int jv_7f80e = opq_82c0 ^ 0xBA99;
            jv_7f80e += (jv_7f80e >> 2) + 0x3F;
            jv_7f80e = (jv_7f80e * 0x14) % 0x7FFFFFFF;
            jv_7f80e ^= (jv_7f80e << 3) | 0x5679;
          (void)jv_7f80e; }
    }
    int head = 0, tail = 0;
    if (((opq_82c0 * opq_82c0 - opq_82c0) % 2 == 0)) { opq_82c0_b ^= 0; }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_82c0 * opq_82c0 + opq_82c0_b * opq_82c0_b) % 4) == 3)) {
            { int jv_a8ec9 = opq_82c0 ^ 0x41FE;
                jv_a8ec9 = (jv_a8ec9 * 0x1B) % 0x7FFFFFFF;
                jv_a8ec9 ^= (jv_a8ec9 << 3) | 0x324F;
                jv_a8ec9 += (jv_a8ec9 >> 2) + 0x88;
              (void)jv_a8ec9; }
        }
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
