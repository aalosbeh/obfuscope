#include <stdio.h>
static volatile int opq_5d91 = 7;
static volatile int opq_5d91_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_5d91 * opq_5d91) % 4) == 2)) {
        { int jv_32360 = opq_5d91 ^ 0x54BF;
            jv_32360 ^= (jv_32360 << 3) | 0x3A34;
            jv_32360 += (jv_32360 >> 2) + 0x5E;
            jv_32360 = (jv_32360 * 0x39) % 0x7FFFFFFF;
          (void)jv_32360; }
    }
    int head = 0, tail = 0;
    if ((((opq_5d91 * opq_5d91 + opq_5d91_b * opq_5d91_b) % 4) == 3)) {
        { int jv_5119d = opq_5d91 ^ 0xE04B;
            jv_5119d += (jv_5119d >> 2) + 0x50;
            jv_5119d ^= (jv_5119d << 3) | 0x5FAC;
            jv_5119d = (jv_5119d * 0x20) % 0x7FFFFFFF;
          (void)jv_5119d; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_5d91 * opq_5d91) % 4) == 2)) {
            { int jv_b1985 = opq_5d91 ^ 0x4C1F;
                jv_b1985 += (jv_b1985 >> 2) + 0x4;
              (void)jv_b1985; }
        }
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if ((((opq_5d91 * opq_5d91 + opq_5d91_b * opq_5d91_b) % 4) == 3)) {
                { int jv_3e003 = opq_5d91 ^ 0x8BFC;
                    jv_3e003 += (jv_3e003 >> 2) + 0x66;
                  (void)jv_3e003; }
            }
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return 0;
}
