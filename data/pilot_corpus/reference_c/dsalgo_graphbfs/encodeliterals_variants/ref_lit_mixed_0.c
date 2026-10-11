#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x91A - 0x91A); i < V; i++) for (int j = (0x3873BB11 ^ 0x3873BB11); j < V; j++) adj[i][j] = ((i * (0x18DBE85D ^ 0x18DBE85A) + j * (0x3E0B3D33 ^ 0x3E0B3D36)) % (0x5867C3E5 ^ 0x5867C3EE) == (0x47135662 ^ 0x47135662)) ? (0xC9A - 0xC99) : (0x59C - 0x59C);
    for (int i = (0x70C - 0x70C); i < V; i++) dist[i] = -(0x646 - 0x645);
    int head = (0x70D2A8D2 ^ 0x70D2A8D2), tail = (0xEA6 - 0xEA6);
    dist[(0x4EABE32C ^ 0x4EABE32C)] = (0x66D60C06 ^ 0x66D60C06); queue[tail++] = (0x46AA63D1 ^ 0x46AA63D1);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x12CAFAAD ^ 0x12CAFAAD); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x59162125 ^ 0x59162125)) { dist[v] = dist[u] + (0x7259A665 ^ 0x7259A664); queue[tail++] = v; }
        }
    }
    int total = (0x1A6 - 0x1A6), reached = (0x6741875F ^ 0x6741875F);
    for (int i = (0x245 - 0x245); i < V; i++) if (dist[i] >= (0x2E6 - 0x2E6)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xEB8 - 0xEB8);
}
