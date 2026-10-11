#include <stdio.h>
static volatile int opq_7a8d = 7;
static volatile int opq_7a8d_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if ((((opq_7a8d * opq_7a8d + opq_7a8d_b * opq_7a8d_b) % 4) == 3)) {
        { int jv_29ab2 = opq_7a8d ^ 0xFCFC;
            jv_29ab2 = (jv_29ab2 * 0x1D) % 0x7FFFFFFF;
            jv_29ab2 ^= (jv_29ab2 << 3) | 0x7FE;
            jv_29ab2 += (jv_29ab2 >> 2) + 0x12;
          (void)jv_29ab2; }
    }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    if ((((opq_7a8d * opq_7a8d + opq_7a8d_b * opq_7a8d_b) % 4) == 3)) {
        { int jv_a5126 = opq_7a8d ^ 0xB9C5;
            jv_a5126 ^= (jv_a5126 << 3) | 0xD9E3;
            jv_a5126 = (jv_a5126 * 0x30) % 0x7FFFFFFF;
            jv_a5126 += (jv_a5126 >> 2) + 0x1E;
          (void)jv_a5126; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        if ((((opq_7a8d * opq_7a8d + opq_7a8d_b * opq_7a8d_b) % 4) == 3)) {
            { int jv_712a9 = opq_7a8d ^ 0xEFF4;
                jv_712a9 += (jv_712a9 >> 2) + 0xB2;
                jv_712a9 = (jv_712a9 * 0x3B) % 0x7FFFFFFF;
                jv_712a9 ^= (jv_712a9 << 3) | 0xE691;
              (void)jv_712a9; }
        }
        for (int v = 0; v < V; v++) {
            if ((((opq_7a8d * opq_7a8d + opq_7a8d) % 2) == 0)) { opq_7a8d_b ^= 0; }
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
