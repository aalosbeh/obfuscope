#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x174D08B0 ^ 0x174D08B0); i < V; i++) for (int j = (0x7F593D5C ^ 0x7F593D5C); j < V; j++) adj[i][j] = ((i * (0x4249B9C4 ^ 0x4249B9C3) + j * (0x7F5D8A60 ^ 0x7F5D8A65)) % (0x414B4399 ^ 0x414B4392) == (0x59465056 ^ 0x59465056)) ? (0x21DFF1B0 ^ 0x21DFF1B1) : (0x45DC699E ^ 0x45DC699E);
    for (int i = (0x37A9D775 ^ 0x37A9D775); i < V; i++) dist[i] = -(0x48B7DF51 ^ 0x48B7DF50);
    int head = (0x1F0097E9 ^ 0x1F0097E9), tail = (0x1598A480 ^ 0x1598A480);
    dist[(0x6B2E6BF4 ^ 0x6B2E6BF4)] = (0x38A38CD0 ^ 0x38A38CD0); queue[tail++] = (0x66C1562 ^ 0x66C1562);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x596706D1 ^ 0x596706D1); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x7CB877C7 ^ 0x7CB877C7)) { dist[v] = dist[u] + (0x258B1D84 ^ 0x258B1D85); queue[tail++] = v; }
        }
    }
    int total = (0x6A57F0B2 ^ 0x6A57F0B2), reached = (0x736A2712 ^ 0x736A2712);
    for (int i = (0x7195BEE0 ^ 0x7195BEE0); i < V; i++) if (dist[i] >= (0x574971E9 ^ 0x574971E9)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x4988466 ^ 0x4988466);
}
