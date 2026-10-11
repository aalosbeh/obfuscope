#include <stdio.h>
static volatile int opq_fc40 = 7;
static volatile int opq_fc40_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if ((((opq_fc40 * opq_fc40 + opq_fc40_b * opq_fc40_b) % 4) == 3)) {
        { int jv_c0dfe = opq_fc40 ^ 0xE44;
            jv_c0dfe += (jv_c0dfe >> 2) + 0x34;
            jv_c0dfe = (jv_c0dfe * 0x3B) % 0x7FFFFFFF;
          (void)jv_c0dfe; }
    }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_fc40 * opq_fc40) % 4) == 2)) {
        { int jv_cce6b = opq_fc40 ^ 0x1C9C;
            jv_cce6b ^= (jv_cce6b << 3) | 0xE84F;
            jv_cce6b += (jv_cce6b >> 2) + 0x81;
          (void)jv_cce6b; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    if ((((opq_fc40 * opq_fc40) % 4) == 2)) {
        { int jv_ef478 = opq_fc40 ^ 0x3FCD;
            jv_ef478 += (jv_ef478 >> 2) + 0x2C;
            jv_ef478 = (jv_ef478 * 0xE) % 0x7FFFFFFF;
            jv_ef478 ^= (jv_ef478 << 3) | 0xA380;
          (void)jv_ef478; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_fc40 * opq_fc40 + opq_fc40_b * opq_fc40_b) % 4) == 3)) {
            { int jv_2f4eb = opq_fc40 ^ 0x971E;
                jv_2f4eb += (jv_2f4eb >> 2) + 0x19;
                jv_2f4eb ^= (jv_2f4eb << 3) | 0xCD84;
              (void)jv_2f4eb; }
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
