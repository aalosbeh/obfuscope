#include <stdio.h>
static volatile int opq_c808 = 7;
static volatile int opq_c808_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_c808 * opq_c808 + opq_c808_b * opq_c808_b) % 4) == 3)) {
        { int jv_31a88 = opq_c808 ^ 0x634D;
            jv_31a88 = (jv_31a88 * 0xA) % 0x7FFFFFFF;
            jv_31a88 ^= (jv_31a88 << 3) | 0x33E9;
          (void)jv_31a88; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_c808 * opq_c808) % 4) == 2)) {
        { int jv_50054 = opq_c808 ^ 0x950A;
            jv_50054 += (jv_50054 >> 2) + 0xD0;
          (void)jv_50054; }
    }
    int head = 0, tail = 0;
    if ((((opq_c808 * opq_c808) % 4) == 2)) {
        { int jv_1c6ba = opq_c808 ^ 0xB70D;
            jv_1c6ba ^= (jv_1c6ba << 3) | 0x76AC;
            jv_1c6ba = (jv_1c6ba * 0x1F) % 0x7FFFFFFF;
            jv_1c6ba += (jv_1c6ba >> 2) + 0x79;
          (void)jv_1c6ba; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    if ((((opq_c808 * opq_c808) % 4) == 2)) {
        { int jv_24ac7 = opq_c808 ^ 0x90B8;
            jv_24ac7 ^= (jv_24ac7 << 3) | 0xEA8D;
            jv_24ac7 += (jv_24ac7 >> 2) + 0x2E;
          (void)jv_24ac7; }
    }
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
