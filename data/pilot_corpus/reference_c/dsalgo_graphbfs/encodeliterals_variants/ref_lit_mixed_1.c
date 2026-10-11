#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x1AAD4726 ^ 0x1AAD4726); i < V; i++) for (int j = (0x69E2ABAE ^ 0x69E2ABAE); j < V; j++) adj[i][j] = ((i * (0x32771DFE ^ 0x32771DF9) + j * (0x70E15164 ^ 0x70E15161)) % (0x226ACD64 ^ 0x226ACD6F) == (0x306E3362 ^ 0x306E3362)) ? (0xC2C - 0xC2B) : (0x72721AA9 ^ 0x72721AA9);
    for (int i = (0x23CB4D17 ^ 0x23CB4D17); i < V; i++) dist[i] = -(0xD7D - 0xD7C);
    int head = (0xFCC - 0xFCC), tail = (0x796D4C7A ^ 0x796D4C7A);
    dist[(0x7D8A134D ^ 0x7D8A134D)] = (0x38F - 0x38F); queue[tail++] = (0x5F494FF5 ^ 0x5F494FF5);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xFEE - 0xFEE); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x2874A6E0 ^ 0x2874A6E0)) { dist[v] = dist[u] + (0xD1D - 0xD1C); queue[tail++] = v; }
        }
    }
    int total = (0x3FD - 0x3FD), reached = (0xA4 - 0xA4);
    for (int i = (0x807 - 0x807); i < V; i++) if (dist[i] >= (0x87A - 0x87A)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x72BB0816 ^ 0x72BB0816);
}
