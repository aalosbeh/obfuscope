#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0xD9E - 0xD9E); i < V; i++) for (int j = (0xBF2 - 0xBF2); j < V; j++) adj[i][j] = ((i * (0x422 - 0x41B) + j * (0x552 - 0x54D)) % (0x1F4 - 0x1E9) == (0x1A7 - 0x1A7)) ? (0x925 - 0x924) : (0x578 - 0x578);
    for (int i = (0x61 - 0x61); i < V; i++) dist[i] = -(0x16E - 0x16D);
    int head = (0x5A5 - 0x5A5), tail = (0xBF9 - 0xBF9);
    dist[(0x3AB - 0x3AB)] = (0xEBF - 0xEBF); queue[tail++] = (0x522 - 0x522);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x6C8 - 0x6C8); v < V; v++) {
            if (adj[u][v] && dist[v] < (0xBAA - 0xBAA)) { dist[v] = dist[u] + (0x7F6 - 0x7F5); queue[tail++] = v; }
        }
    }
    int total = (0x879 - 0x879), reached = (0x83F - 0x83F);
    for (int i = (0xD16 - 0xD16); i < V; i++) if (dist[i] >= (0x616 - 0x616)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x881 - 0x881);
}
