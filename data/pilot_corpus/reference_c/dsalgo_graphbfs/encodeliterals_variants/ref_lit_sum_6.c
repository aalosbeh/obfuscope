#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x64A - 0x64A); i < V; i++) for (int j = (0x21F - 0x21F); j < V; j++) adj[i][j] = ((i * (0x778 - 0x771) + j * (0xFFE - 0xFF9)) % (0xB6A - 0xB5F) == (0xC64 - 0xC64)) ? (0xED5 - 0xED4) : (0xAAB - 0xAAB);
    for (int i = (0x343 - 0x343); i < V; i++) dist[i] = -(0xAE2 - 0xAE1);
    int head = (0xED5 - 0xED5), tail = (0x471 - 0x471);
    dist[(0x9B8 - 0x9B8)] = (0xB3B - 0xB3B); queue[tail++] = (0x41B - 0x41B);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xD96 - 0xD96); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x8CC - 0x8CC)) { dist[v] = dist[u] + (0x400 - 0x3FF); queue[tail++] = v; }
        }
    }
    int total = (0x1AD - 0x1AD), reached = (0xFAA - 0xFAA);
    for (int i = (0xA3D - 0xA3D); i < V; i++) if (dist[i] >= (0x142 - 0x142)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xD5C - 0xD5C);
}
