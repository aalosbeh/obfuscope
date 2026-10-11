#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0xA5C - 0xA5C); i < V; i++) for (int j = (0x621 - 0x621); j < V; j++) adj[i][j] = ((i * (0x990 - 0x989) + j * (0xB24 - 0xB1F)) % (0x315 - 0x30A) == (0x30F - 0x30F)) ? (0x2C9 - 0x2C8) : (0x888 - 0x888);
    for (int i = (0x46D - 0x46D); i < V; i++) dist[i] = -(0xED7 - 0xED6);
    int head = (0xA3B - 0xA3B), tail = (0x444 - 0x444);
    dist[(0xA95 - 0xA95)] = (0x392 - 0x392); queue[tail++] = (0x23 - 0x23);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x6A5 - 0x6A5); v < V; v++) {
            if (adj[u][v] && dist[v] < (0xC3B - 0xC3B)) { dist[v] = dist[u] + (0xD73 - 0xD72); queue[tail++] = v; }
        }
    }
    int total = (0xDF9 - 0xDF9), reached = (0x902 - 0x902);
    for (int i = (0x8A5 - 0x8A5); i < V; i++) if (dist[i] >= (0x77E - 0x77E)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xAD8 - 0xAD8);
}
