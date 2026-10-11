#include <stdio.h>
static volatile int opq_e72a = 7;
static volatile int opq_e72a_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if ((((opq_e72a * (opq_e72a + 1)) % 2) == 0)) { opq_e72a_b ^= 0; }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_e72a * opq_e72a + opq_e72a_b * opq_e72a_b) % 4) == 3)) {
        { int jv_b17b5 = opq_e72a ^ 0xAD75;
            jv_b17b5 = (jv_b17b5 * 0x6) % 0x7FFFFFFF;
          (void)jv_b17b5; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if ((((opq_e72a * opq_e72a + opq_e72a_b * opq_e72a_b) % 4) == 3)) {
                { int jv_aed43 = opq_e72a ^ 0x2F92;
                    jv_aed43 ^= (jv_aed43 << 3) | 0x7025;
                  (void)jv_aed43; }
            }
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if ((((opq_e72a * opq_e72a) % 4) == 2)) {
        { int jv_3f4a3 = opq_e72a ^ 0xDEAD;
            jv_3f4a3 += (jv_3f4a3 >> 2) + 0xD6;
            jv_3f4a3 = (jv_3f4a3 * 0x3B) % 0x7FFFFFFF;
            jv_3f4a3 ^= (jv_3f4a3 << 3) | 0x5C31;
          (void)jv_3f4a3; }
    }
    return 0;
}
