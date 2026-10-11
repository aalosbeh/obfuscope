#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0xF75 - 0xF75); i < V; i++) for (int j = (0xFD2 - 0xFD2); j < V; j++) adj[i][j] = ((i * (0x1E8 - 0x1E1) + j * (0x788 - 0x783)) % (0x42B - 0x420) == (0xE45 - 0xE45)) ? (0xCC6 - 0xCC5) : (0xD6A - 0xD6A);
    for (int i = (0x553 - 0x553); i < V; i++) dist[i] = -(0xC1 - 0xC0);
    int head = (0x922 - 0x922), tail = (0xB11 - 0xB11);
    dist[(0xDD2 - 0xDD2)] = (0xA77 - 0xA77); queue[tail++] = (0xEB8 - 0xEB8);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x678 - 0x678); v < V; v++) {
            if (adj[u][v] && dist[v] < (0xBA9 - 0xBA9)) { dist[v] = dist[u] + (0x6B4 - 0x6B3); queue[tail++] = v; }
        }
    }
    int total = (0x21A - 0x21A), reached = (0x8E2 - 0x8E2);
    for (int i = (0xD71 - 0xD71); i < V; i++) if (dist[i] >= (0xA02 - 0xA02)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x394 - 0x394);
}
