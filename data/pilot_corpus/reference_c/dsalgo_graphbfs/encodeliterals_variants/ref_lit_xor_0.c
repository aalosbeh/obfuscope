#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x55FA4D6E ^ 0x55FA4D6E); i < V; i++) for (int j = (0x3652708D ^ 0x3652708D); j < V; j++) adj[i][j] = ((i * (0x6515BE6E ^ 0x6515BE69) + j * (0x7BE1DBE5 ^ 0x7BE1DBE0)) % (0x472B77F7 ^ 0x472B77FC) == (0x143B710E ^ 0x143B710E)) ? (0x12498EF5 ^ 0x12498EF4) : (0x433207A4 ^ 0x433207A4);
    for (int i = (0x70C14934 ^ 0x70C14934); i < V; i++) dist[i] = -(0x723E5B2 ^ 0x723E5B3);
    int head = (0x74D69AF9 ^ 0x74D69AF9), tail = (0x49218894 ^ 0x49218894);
    dist[(0x6B2257D7 ^ 0x6B2257D7)] = (0x74B9BE96 ^ 0x74B9BE96); queue[tail++] = (0x4FD0E6BE ^ 0x4FD0E6BE);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x6F4A236C ^ 0x6F4A236C); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x23884A4D ^ 0x23884A4D)) { dist[v] = dist[u] + (0x188FD113 ^ 0x188FD112); queue[tail++] = v; }
        }
    }
    int total = (0x6A499FF0 ^ 0x6A499FF0), reached = (0x340D696 ^ 0x340D696);
    for (int i = (0x1E231DC2 ^ 0x1E231DC2); i < V; i++) if (dist[i] >= (0x597000BA ^ 0x597000BA)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x4B5477A1 ^ 0x4B5477A1);
}
