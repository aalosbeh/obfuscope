#include <stdio.h>

static char dec_d2de_buf[4][256];
static int dec_d2de_slot = 0;
static const char *dec_d2de(const unsigned char *enc, int n, int key) {
    int s = dec_d2de_slot++ % 4;
    char *out = dec_d2de_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) adj[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) dist[i] = -1;
    int head = 0, tail = 0;
    dist[0] = 0; queue[tail++] = 0;
    while (head < tail) {
        int u = queue[head++];
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && dist[v] < 0) { dist[v] = dist[u] + 1; queue[tail++] = v; }
        }
    }
    int total = 0, reached = 0;
    for (int i = 0; i < V; i++) if (dist[i] >= 0) { total += dist[i]; reached++; }
    printf(dec_d2de((const unsigned char[]){0x2E, 0x6D, 0x29, 0x2E, 0x6D, 0x13}, 6, 9), reached, total);
    return 0;
}
