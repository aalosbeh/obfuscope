#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x3A7 - 0x3A7); i < V; i++) for (int j = (0xE04 - 0xE04); j < V; j++) adj[i][j] = ((i * (0xA92 - 0xA8B) + j * (0x711 - 0x70C)) % (0x7FE - 0x7F3) == (0x3D8 - 0x3D8)) ? (0x12 - 0x11) : (0x1B2 - 0x1B2);
    for (int i = (0x757 - 0x757); i < V; i++) dist[i] = -(0x3EA - 0x3E9);
    int head = (0xEAD - 0xEAD), tail = (0x944 - 0x944);
    dist[(0xD5F - 0xD5F)] = (0x213 - 0x213); queue[tail++] = (0xAAF - 0xAAF);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x827 - 0x827); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x335 - 0x335)) { dist[v] = dist[u] + (0x136 - 0x135); queue[tail++] = v; }
        }
    }
    int total = (0x4DE - 0x4DE), reached = (0xD60 - 0xD60);
    for (int i = (0xA7A - 0xA7A); i < V; i++) if (dist[i] >= (0x73D - 0x73D)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xC66 - 0xC66);
}
