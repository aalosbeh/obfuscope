#include <stdio.h>
static volatile int opq_c750 = 7;
static volatile int opq_c750_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_c750 * opq_c750) % 4) == 2)) {
        { int jv_65f21 = opq_c750 ^ 0xF87F;
            jv_65f21 += (jv_65f21 >> 2) + 0xB2;
            jv_65f21 ^= (jv_65f21 << 3) | 0xBEA5;
            jv_65f21 = (jv_65f21 * 0x25) % 0x7FFFFFFF;
          (void)jv_65f21; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    if ((((opq_c750 * opq_c750) % 4) == 2)) {
        { int jv_74e45 = opq_c750 ^ 0x91F9;
            jv_74e45 ^= (jv_74e45 << 3) | 0xC194;
          (void)jv_74e45; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_c750 * opq_c750) % 4) == 2)) {
            { int jv_81ffb = opq_c750 ^ 0xE792;
                jv_81ffb = (jv_81ffb * 0x7) % 0x7FFFFFFF;
                jv_81ffb += (jv_81ffb >> 2) + 0x72;
                jv_81ffb ^= (jv_81ffb << 3) | 0x29F7;
              (void)jv_81ffb; }
        }
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    if ((((opq_c750 * opq_c750 + opq_c750_b * opq_c750_b) % 4) == 3)) {
        { int jv_a8630 = opq_c750 ^ 0x90B7;
            jv_a8630 += (jv_a8630 >> 2) + 0xF6;
          (void)jv_a8630; }
    }
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
