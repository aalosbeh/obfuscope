#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x382 - 0x382); i < V; i++) for (int j = (0x495E7BCE ^ 0x495E7BCE); j < V; j++) adj[i][j] = ((i * (0x2D1CCAB6 ^ 0x2D1CCAB1) + j * (0x1F6 - 0x1F1)) % (0x808 - 0x7FD) == (0x1099165 ^ 0x1099165)) ? (0x224F8C93 ^ 0x224F8C92) : (0x2549C805 ^ 0x2549C805);
    for (int i = (0x956 - 0x956); i < V; i++) dist[i] = -(0xC43 - 0xC42);
    int head = (0x612 - 0x612), tail = (0xE6D - 0xE6D);
    dist[(0xBCA - 0xBCA)] = (0x8DC - 0x8DC); queue[tail++] = (0x576 - 0x576);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xCF1 - 0xCF1); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x9F4 - 0x9F4)) { dist[v] = dist[u] + (0x34689C5E ^ 0x34689C5F); queue[tail++] = v; }
        }
    }
    int total = (0x885 - 0x885), reached = (0x70BCFB95 ^ 0x70BCFB95);
    for (int i = (0x132 - 0x132); i < V; i++) if (dist[i] >= (0x454D10C7 ^ 0x454D10C7)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x4CE - 0x4CE);
}
