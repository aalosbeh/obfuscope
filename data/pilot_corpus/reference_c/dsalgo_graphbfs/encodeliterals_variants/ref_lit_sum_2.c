#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x3C0 - 0x3C0); i < V; i++) for (int j = (0xF5 - 0xF5); j < V; j++) adj[i][j] = ((i * (0x9EC - 0x9E5) + j * (0x9A1 - 0x99C)) % (0x44C - 0x441) == (0x464 - 0x464)) ? (0x8CE - 0x8CD) : (0xF85 - 0xF85);
    for (int i = (0xAE5 - 0xAE5); i < V; i++) dist[i] = -(0x10A - 0x109);
    int head = (0x76C - 0x76C), tail = (0xDE1 - 0xDE1);
    dist[(0x425 - 0x425)] = (0x54E - 0x54E); queue[tail++] = (0x97C - 0x97C);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xB73 - 0xB73); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x40F - 0x40F)) { dist[v] = dist[u] + (0xBD6 - 0xBD5); queue[tail++] = v; }
        }
    }
    int total = (0x82C - 0x82C), reached = (0x372 - 0x372);
    for (int i = (0x462 - 0x462); i < V; i++) if (dist[i] >= (0xA69 - 0xA69)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xEF6 - 0xEF6);
}
