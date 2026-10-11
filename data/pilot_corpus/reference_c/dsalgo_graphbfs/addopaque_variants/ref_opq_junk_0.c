#include <stdio.h>
static volatile int opq_607d = 7;
static volatile int opq_607d_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_607d * opq_607d + opq_607d_b * opq_607d_b) % 4) == 3)) {
        { int jv_7e370 = opq_607d ^ 0x11DD;
            jv_7e370 += (jv_7e370 >> 2) + 0x58;
            jv_7e370 = (jv_7e370 * 0x12) % 0x7FFFFFFF;
            jv_7e370 ^= (jv_7e370 << 3) | 0xF9F9;
          (void)jv_7e370; }
    }
    int head = 0, tail = 0;
    if ((((opq_607d * opq_607d) % 4) == 2)) {
        { int jv_394fc = opq_607d ^ 0xCD71;
            jv_394fc += (jv_394fc >> 2) + 0x7A;
          (void)jv_394fc; }
    }
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    if ((((opq_607d * opq_607d + opq_607d_b * opq_607d_b) % 4) == 3)) {
        { int jv_18649 = opq_607d ^ 0x95F3;
            jv_18649 ^= (jv_18649 << 3) | 0xE208;
            jv_18649 = (jv_18649 * 0x19) % 0x7FFFFFFF;
          (void)jv_18649; }
    }
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if ((((opq_607d * opq_607d + opq_607d_b * opq_607d_b) % 4) == 3)) {
        { int jv_f3bba = opq_607d ^ 0x8D8D;
            jv_f3bba ^= (jv_f3bba << 3) | 0x8605;
            jv_f3bba = (jv_f3bba * 0x18) % 0x7FFFFFFF;
          (void)jv_f3bba; }
    }
    return 0;
}
