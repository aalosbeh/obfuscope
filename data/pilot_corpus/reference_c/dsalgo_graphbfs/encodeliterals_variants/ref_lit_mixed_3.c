#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x4932D578 ^ 0x4932D578); i < V; i++) for (int j = (0x28BDDDBB ^ 0x28BDDDBB); j < V; j++) adj[i][j] = ((i * (0x256E787A ^ 0x256E787D) + j * (0x574 - 0x56F)) % (0xFC7 - 0xFBC) == (0xBDB - 0xBDB)) ? (0x78E77DB0 ^ 0x78E77DB1) : (0xA31 - 0xA31);
    for (int i = (0x613A70E6 ^ 0x613A70E6); i < V; i++) dist[i] = -(0xFDD - 0xFDC);
    int head = (0x50025245 ^ 0x50025245), tail = (0x4C6AE547 ^ 0x4C6AE547);
    dist[(0x77B71EE1 ^ 0x77B71EE1)] = (0x6B8 - 0x6B8); queue[tail++] = (0x483649D7 ^ 0x483649D7);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xCD6 - 0xCD6); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x7E4 - 0x7E4)) { dist[v] = dist[u] + (0x96E - 0x96D); queue[tail++] = v; }
        }
    }
    int total = (0x2447794 ^ 0x2447794), reached = (0x2C10DAD4 ^ 0x2C10DAD4);
    for (int i = (0x58ABD732 ^ 0x58ABD732); i < V; i++) if (dist[i] >= (0x79405FF1 ^ 0x79405FF1)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xA8A8E6E ^ 0xA8A8E6E);
}
