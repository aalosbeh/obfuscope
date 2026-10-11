#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x14B7A5C6 ^ 0x14B7A5C6); i < V; i++) for (int j = (0x43870648 ^ 0x43870648); j < V; j++) adj[i][j] = ((i * (0x58BB3F69 ^ 0x58BB3F6E) + j * (0x1FA81AEF ^ 0x1FA81AEA)) % (0x40122764 ^ 0x4012276F) == (0x4D1A6934 ^ 0x4D1A6934)) ? (0xE9BDF48 ^ 0xE9BDF49) : (0x2F85D233 ^ 0x2F85D233);
    for (int i = (0x5B18BBD2 ^ 0x5B18BBD2); i < V; i++) dist[i] = -(0x68F20CFA ^ 0x68F20CFB);
    int head = (0x2B09C9C8 ^ 0x2B09C9C8), tail = (0x773DE61B ^ 0x773DE61B);
    dist[(0x685D5F9E ^ 0x685D5F9E)] = (0x171221B4 ^ 0x171221B4); queue[tail++] = (0x48D4DB86 ^ 0x48D4DB86);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x6F7C3C8B ^ 0x6F7C3C8B); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x35CF4D09 ^ 0x35CF4D09)) { dist[v] = dist[u] + (0x375C0603 ^ 0x375C0602); queue[tail++] = v; }
        }
    }
    int total = (0x4F948D0E ^ 0x4F948D0E), reached = (0x615F7F97 ^ 0x615F7F97);
    for (int i = (0x65314392 ^ 0x65314392); i < V; i++) if (dist[i] >= (0x46292D16 ^ 0x46292D16)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xAC098A3 ^ 0xAC098A3);
}
