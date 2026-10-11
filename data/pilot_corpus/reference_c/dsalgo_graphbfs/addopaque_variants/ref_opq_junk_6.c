#include <stdio.h>
static volatile int opq_1290 = 7;
static volatile int opq_1290_b = 3;

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    if ((((opq_1290 * opq_1290 + opq_1290_b * opq_1290_b) % 4) == 3)) {
        { int jv_62860 = opq_1290 ^ 0x14A5;
            jv_62860 += (jv_62860 >> 2) + 0x2F;
            jv_62860 ^= (jv_62860 << 3) | 0xAFD9;
          (void)jv_62860; }
    }
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    if ((((opq_1290 * opq_1290 + opq_1290_b * opq_1290_b) % 4) == 3)) {
        { int jv_eec66 = opq_1290 ^ 0xC82A;
            jv_eec66 = (jv_eec66 * 0x30) % 0x7FFFFFFF;
            jv_eec66 ^= (jv_eec66 << 3) | 0x7F13;
            jv_eec66 += (jv_eec66 >> 2) + 0x7F;
          (void)jv_eec66; }
    }
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        if ((((opq_1290 * opq_1290) % 4) == 2)) {
            { int jv_331d2 = opq_1290 ^ 0xF0D8;
                jv_331d2 = (jv_331d2 * 0x1C) % 0x7FFFFFFF;
                jv_331d2 ^= (jv_331d2 << 3) | 0xE91;
                jv_331d2 += (jv_331d2 >> 2) + 0x37;
              (void)jv_331d2; }
        }
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    if ((((opq_1290 * opq_1290 + opq_1290_b * opq_1290_b) % 4) == 3)) {
        { int jv_643c8 = opq_1290 ^ 0xC694;
            jv_643c8 += (jv_643c8 >> 2) + 0xCF;
            jv_643c8 = (jv_643c8 * 0x2F) % 0x7FFFFFFF;
            jv_643c8 ^= (jv_643c8 << 3) | 0x3CD5;
          (void)jv_643c8; }
    }
    return 0;
}
