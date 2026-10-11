#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0xAC9461E ^ 0xAC9461E); i < V; i++) for (int j = (0xA5D - 0xA5D); j < V; j++) adj[i][j] = ((i * (0x3A4B98A3 ^ 0x3A4B98A4) + j * (0x5BF - 0x5BA)) % (0x5BB98093 ^ 0x5BB98098) == (0x25D257DD ^ 0x25D257DD)) ? (0x82B - 0x82A) : (0x1D08B45B ^ 0x1D08B45B);
    for (int i = (0x1D4785AA ^ 0x1D4785AA); i < V; i++) dist[i] = -(0x8A5 - 0x8A4);
    int head = (0x3846826F ^ 0x3846826F), tail = (0x65B9084D ^ 0x65B9084D);
    dist[(0x4BA - 0x4BA)] = (0xCA6 - 0xCA6); queue[tail++] = (0x18F97A65 ^ 0x18F97A65);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x8EC - 0x8EC); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x16C - 0x16C)) { dist[v] = dist[u] + (0xF4E - 0xF4D); queue[tail++] = v; }
        }
    }
    int total = (0xCC1 - 0xCC1), reached = (0x4D115104 ^ 0x4D115104);
    for (int i = (0x62D39160 ^ 0x62D39160); i < V; i++) if (dist[i] >= (0x61D8EB33 ^ 0x61D8EB33)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xB5A - 0xB5A);
}
