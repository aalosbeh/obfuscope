#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x3940B2C0 ^ 0x3940B2C0); i < V; i++) for (int j = (0x3EBC7624 ^ 0x3EBC7624); j < V; j++) adj[i][j] = ((i * (0x1F6291F7 ^ 0x1F6291F0) + j * (0x7FD670B7 ^ 0x7FD670B2)) % (0x75E33982 ^ 0x75E33989) == (0xFED5157 ^ 0xFED5157)) ? (0x4F98567A ^ 0x4F98567B) : (0x730C6264 ^ 0x730C6264);
    for (int i = (0xAF83D34 ^ 0xAF83D34); i < V; i++) dist[i] = -(0x62792B2C ^ 0x62792B2D);
    int head = (0x251D71A5 ^ 0x251D71A5), tail = (0xA0D0813 ^ 0xA0D0813);
    dist[(0x2A6D00DC ^ 0x2A6D00DC)] = (0x73B4AD6B ^ 0x73B4AD6B); queue[tail++] = (0x74C17172 ^ 0x74C17172);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x2F98BD6D ^ 0x2F98BD6D); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x7C67D33A ^ 0x7C67D33A)) { dist[v] = dist[u] + (0x27810989 ^ 0x27810988); queue[tail++] = v; }
        }
    }
    int total = (0x64E5FBA3 ^ 0x64E5FBA3), reached = (0x19A14240 ^ 0x19A14240);
    for (int i = (0x4FFB7FC4 ^ 0x4FFB7FC4); i < V; i++) if (dist[i] >= (0x1676A376 ^ 0x1676A376)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x595213F0 ^ 0x595213F0);
}
