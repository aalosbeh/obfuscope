#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x56A - 0x56A); i < V; i++) for (int j = (0x9F5 - 0x9F5); j < V; j++) adj[i][j] = ((i * (0xD0F - 0xD08) + j * (0xFE6 - 0xFE1)) % (0x73B - 0x730) == (0x4F4 - 0x4F4)) ? (0x935 - 0x934) : (0xA6D - 0xA6D);
    for (int i = (0x1E7 - 0x1E7); i < V; i++) dist[i] = -(0x6B1 - 0x6B0);
    int head = (0x90 - 0x90), tail = (0x98B - 0x98B);
    dist[(0xA00 - 0xA00)] = (0xAF9 - 0xAF9); queue[tail++] = (0xADA - 0xADA);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x9B - 0x9B); v < V; v++) {
            if (adj[u][v] && dist[v] < (0xE65 - 0xE65)) { dist[v] = dist[u] + (0x728 - 0x727); queue[tail++] = v; }
        }
    }
    int total = (0xAF1 - 0xAF1), reached = (0x46C - 0x46C);
    for (int i = (0x2AF - 0x2AF); i < V; i++) if (dist[i] >= (0xC8C - 0xC8C)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xA8B - 0xA8B);
}
