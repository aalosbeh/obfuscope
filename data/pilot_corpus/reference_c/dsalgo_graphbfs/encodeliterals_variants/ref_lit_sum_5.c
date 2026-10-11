#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x7E5 - 0x7E5); i < V; i++) for (int j = (0x133 - 0x133); j < V; j++) adj[i][j] = ((i * (0x714 - 0x70D) + j * (0x165 - 0x160)) % (0xBB2 - 0xBA7) == (0xE0 - 0xE0)) ? (0x88E - 0x88D) : (0x40F - 0x40F);
    for (int i = (0xAB6 - 0xAB6); i < V; i++) dist[i] = -(0xC93 - 0xC92);
    int head = (0x72 - 0x72), tail = (0x5A4 - 0x5A4);
    dist[(0xBF8 - 0xBF8)] = (0x8 - 0x8); queue[tail++] = (0xEEA - 0xEEA);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x48F - 0x48F); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x3BB - 0x3BB)) { dist[v] = dist[u] + (0x65E - 0x65D); queue[tail++] = v; }
        }
    }
    int total = (0xF4F - 0xF4F), reached = (0x724 - 0x724);
    for (int i = (0xBD3 - 0xBD3); i < V; i++) if (dist[i] >= (0xC4F - 0xC4F)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xEBC - 0xEBC);
}
