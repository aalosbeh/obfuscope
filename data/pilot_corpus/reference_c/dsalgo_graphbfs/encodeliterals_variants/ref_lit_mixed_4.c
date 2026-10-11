#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0xBBE - 0xBBE); i < V; i++) for (int j = (0x66D2CA5F ^ 0x66D2CA5F); j < V; j++) adj[i][j] = ((i * (0xF97 - 0xF90) + j * (0x6AB - 0x6A6)) % (0x2CC - 0x2C1) == (0x3361B768 ^ 0x3361B768)) ? (0x6235D893 ^ 0x6235D892) : (0x27796E1B ^ 0x27796E1B);
    for (int i = (0x909 - 0x909); i < V; i++) dist[i] = -(0x60F6C0E1 ^ 0x60F6C0E0);
    int head = (0x2A66D250 ^ 0x2A66D250), tail = (0xFFF - 0xFFF);
    dist[(0xCF0 - 0xCF0)] = (0xDBF - 0xDBF); queue[tail++] = (0x57662597 ^ 0x57662597);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0xB8B - 0xB8B); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x1A6 - 0x1A6)) { dist[v] = dist[u] + (0x6EB3F2AB ^ 0x6EB3F2AA); queue[tail++] = v; }
        }
    }
    int total = (0x21A42218 ^ 0x21A42218), reached = (0x310 - 0x310);
    for (int i = (0x610BC579 ^ 0x610BC579); i < V; i++) if (dist[i] >= (0x3EEC4694 ^ 0x3EEC4694)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x687 - 0x687);
}
