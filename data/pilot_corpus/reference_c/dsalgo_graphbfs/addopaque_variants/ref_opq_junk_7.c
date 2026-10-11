#include <stdio.h>
static volatile int opq_133e = 7;
static volatile int opq_133e_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    if ((((opq_133e * opq_133e) % 4) == 2)) {
        { int jv_31885 = opq_133e ^ 0x3643;
            jv_31885 = (jv_31885 * 0x12) % 0x7FFFFFFF;
            jv_31885 ^= (jv_31885 << 3) | 0xBAEC;
            jv_31885 += (jv_31885 >> 2) + 0x74;
          (void)jv_31885; }
    }
    int head = 0, tail = 0;
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        if ((((opq_133e * opq_133e + opq_133e_b * opq_133e_b) % 4) == 3)) {
            { int jv_aca86 = opq_133e ^ 0x4B11;
                jv_aca86 = (jv_aca86 * 0x5) % 0x7FFFFFFF;
              (void)jv_aca86; }
        }
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    if ((((opq_133e * opq_133e) % 4) == 2)) {
        { int jv_a6b0a = opq_133e ^ 0xFC26;
            jv_a6b0a ^= (jv_a6b0a << 3) | 0xC8BC;
            jv_a6b0a += (jv_a6b0a >> 2) + 0xC7;
          (void)jv_a6b0a; }
    }
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if ((((opq_133e * opq_133e) % 4) == 2)) {
        { int jv_e7c96 = opq_133e ^ 0xD0EB;
            jv_e7c96 ^= (jv_e7c96 << 3) | 0xAEB0;
            jv_e7c96 = (jv_e7c96 * 0x37) % 0x7FFFFFFF;
          (void)jv_e7c96; }
    }
    return 0;
}
