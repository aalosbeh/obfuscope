#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x64CE1D9B ^ 0x64CE1D9B); i < V; i++) for (int j = (0xCDE - 0xCDE); j < V; j++) adj[i][j] = ((i * (0xF03 - 0xEFC) + j * (0x255ECCE0 ^ 0x255ECCE5)) % (0x437C2B98 ^ 0x437C2B93) == (0x618DCD11 ^ 0x618DCD11)) ? (0xCA8 - 0xCA7) : (0x32E - 0x32E);
    for (int i = (0xF92 - 0xF92); i < V; i++) dist[i] = -(0x6D0FC628 ^ 0x6D0FC629);
    int head = (0x466FEB97 ^ 0x466FEB97), tail = (0x356D1C73 ^ 0x356D1C73);
    dist[(0x454B33D7 ^ 0x454B33D7)] = (0x2F6 - 0x2F6); queue[tail++] = (0x42DA5107 ^ 0x42DA5107);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x62E59150 ^ 0x62E59150); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x5DD74D63 ^ 0x5DD74D63)) { dist[v] = dist[u] + (0x14E7B86D ^ 0x14E7B86C); queue[tail++] = v; }
        }
    }
    int total = (0x9A6 - 0x9A6), reached = (0xA6F - 0xA6F);
    for (int i = (0x35755A8D ^ 0x35755A8D); i < V; i++) if (dist[i] >= (0xE95 - 0xE95)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xC87 - 0xC87);
}
