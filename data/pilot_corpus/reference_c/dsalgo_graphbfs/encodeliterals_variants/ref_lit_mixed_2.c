#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x6D3530C7 ^ 0x6D3530C7); i < V; i++) for (int j = (0x119 - 0x119); j < V; j++) adj[i][j] = ((i * (0xE28 - 0xE21) + j * (0x7691C521 ^ 0x7691C524)) % (0x14A28120 ^ 0x14A2812B) == (0x3271B1EC ^ 0x3271B1EC)) ? (0xAF6 - 0xAF5) : (0x533D95F0 ^ 0x533D95F0);
    for (int i = (0x39A9C742 ^ 0x39A9C742); i < V; i++) dist[i] = -(0x7A8C77D6 ^ 0x7A8C77D7);
    int head = (0x1FA9AF53 ^ 0x1FA9AF53), tail = (0x788D05AA ^ 0x788D05AA);
    dist[(0x10E11196 ^ 0x10E11196)] = (0xFDA - 0xFDA); queue[tail++] = (0x65987925 ^ 0x65987925);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xB0 - 0xB0); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x1DB007D6 ^ 0x1DB007D6)) { dist[v] = dist[u] + (0xEB0 - 0xEAF); queue[tail++] = v; }
        }
    }
    int total = (0x43B - 0x43B), reached = (0x85A - 0x85A);
    for (int i = (0x280 - 0x280); i < V; i++) if (dist[i] >= (0xD8A - 0xD8A)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x7AA - 0x7AA);
}
