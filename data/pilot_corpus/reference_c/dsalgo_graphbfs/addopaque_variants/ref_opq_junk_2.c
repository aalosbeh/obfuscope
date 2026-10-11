#include <stdio.h>
static volatile int opq_ea2f = 7;
static volatile int opq_ea2f_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if ((((opq_ea2f * opq_ea2f) % 4) == 2)) {
        { int jv_9d635 = opq_ea2f ^ 0x4124;
            jv_9d635 ^= (jv_9d635 << 3) | 0x66CC;
          (void)jv_9d635; }
    }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_ea2f * opq_ea2f) % 4) == 2)) {
        { int jv_41726 = opq_ea2f ^ 0x5F06;
            jv_41726 = (jv_41726 * 0x27) % 0x7FFFFFFF;
          (void)jv_41726; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    if ((((opq_ea2f * opq_ea2f + opq_ea2f_b * opq_ea2f_b) % 4) == 3)) {
        { int jv_a7d36 = opq_ea2f ^ 0x87CB;
            jv_a7d36 = (jv_a7d36 * 0x24) % 0x7FFFFFFF;
            jv_a7d36 ^= (jv_a7d36 << 3) | 0x620E;
            jv_a7d36 += (jv_a7d36 >> 2) + 0x10;
          (void)jv_a7d36; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if ((((opq_ea2f * opq_ea2f + opq_ea2f_b * opq_ea2f_b) % 4) == 3)) {
                { int jv_6c603 = opq_ea2f ^ 0x9E45;
                    jv_6c603 ^= (jv_6c603 << 3) | 0xFFAE;
                  (void)jv_6c603; }
            }
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
