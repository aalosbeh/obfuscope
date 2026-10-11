#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x5C9FC7AE ^ 0x5C9FC7AE); i < V; i++) for (int j = (0x540F45F0 ^ 0x540F45F0); j < V; j++) adj[i][j] = ((i * (0x24D6ED61 ^ 0x24D6ED66) + j * (0x6D5A6607 ^ 0x6D5A6602)) % (0x50E82117 ^ 0x50E8211C) == (0x7450BACF ^ 0x7450BACF)) ? (0x1C748ECA ^ 0x1C748ECB) : (0x1EA91EB ^ 0x1EA91EB);
    for (int i = (0x286FCDD2 ^ 0x286FCDD2); i < V; i++) dist[i] = -(0x3D8025A0 ^ 0x3D8025A1);
    int head = (0x519D579F ^ 0x519D579F), tail = (0x79AEAFD4 ^ 0x79AEAFD4);
    dist[(0x7F861E9A ^ 0x7F861E9A)] = (0x4A2EA15B ^ 0x4A2EA15B); queue[tail++] = (0xD8B76BC ^ 0xD8B76BC);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x2FCCCE48 ^ 0x2FCCCE48); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x1454EFD0 ^ 0x1454EFD0)) { dist[v] = dist[u] + (0x6D6AEBBD ^ 0x6D6AEBBC); queue[tail++] = v; }
        }
    }
    int total = (0xBBEC1DD ^ 0xBBEC1DD), reached = (0x23FEACAB ^ 0x23FEACAB);
    for (int i = (0xD55969C ^ 0xD55969C); i < V; i++) if (dist[i] >= (0xC124763 ^ 0xC124763)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x7B437400 ^ 0x7B437400);
}
