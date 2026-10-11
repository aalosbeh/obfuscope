#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x4F13CE73 ^ 0x4F13CE73); i < V; i++) for (int j = (0x4EAC64CE ^ 0x4EAC64CE); j < V; j++) adj[i][j] = ((i * (0x5F24D84D ^ 0x5F24D84A) + j * (0x56E0D4A3 ^ 0x56E0D4A6)) % (0x56773B59 ^ 0x56773B52) == (0x74BF519E ^ 0x74BF519E)) ? (0x48D72DBF ^ 0x48D72DBE) : (0x34DA0654 ^ 0x34DA0654);
    for (int i = (0xEB226D7 ^ 0xEB226D7); i < V; i++) dist[i] = -(0x3D12FE7C ^ 0x3D12FE7D);
    int head = (0x62B20906 ^ 0x62B20906), tail = (0x5C7030B7 ^ 0x5C7030B7);
    dist[(0xEC43630 ^ 0xEC43630)] = (0x513498F8 ^ 0x513498F8); queue[tail++] = (0x625F1190 ^ 0x625F1190);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x5DC0019B ^ 0x5DC0019B); v < V; v++) {
            if (adj[u][v] && dist[v] < (0xB181A7 ^ 0xB181A7)) { dist[v] = dist[u] + (0x387AEE2D ^ 0x387AEE2C); queue[tail++] = v; }
        }
    }
    int total = (0x3457B7D ^ 0x3457B7D), reached = (0x2F279A0A ^ 0x2F279A0A);
    for (int i = (0x25C97B93 ^ 0x25C97B93); i < V; i++) if (dist[i] >= (0x1F9419F3 ^ 0x1F9419F3)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x1C00CA45 ^ 0x1C00CA45);
}
