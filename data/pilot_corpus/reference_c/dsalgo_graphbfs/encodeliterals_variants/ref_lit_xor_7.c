#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x1E8CADF8 ^ 0x1E8CADF8); i < V; i++) for (int j = (0xBCAE48F ^ 0xBCAE48F); j < V; j++) adj[i][j] = ((i * (0x3C93BB11 ^ 0x3C93BB16) + j * (0x64D1F48 ^ 0x64D1F4D)) % (0x12344951 ^ 0x1234495A) == (0x13A54183 ^ 0x13A54183)) ? (0x76AF4C73 ^ 0x76AF4C72) : (0x548AFC77 ^ 0x548AFC77);
    for (int i = (0x428DD604 ^ 0x428DD604); i < V; i++) dist[i] = -(0x5C9BC1CB ^ 0x5C9BC1CA);
    int head = (0x5012EABB ^ 0x5012EABB), tail = (0x53EAEAB1 ^ 0x53EAEAB1);
    dist[(0x74945435 ^ 0x74945435)] = (0x54E351B9 ^ 0x54E351B9); queue[tail++] = (0x3E81E9DB ^ 0x3E81E9DB);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x14ED5599 ^ 0x14ED5599); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x74E4F831 ^ 0x74E4F831)) { dist[v] = dist[u] + (0x53E25478 ^ 0x53E25479); queue[tail++] = v; }
        }
    }
    int total = (0x6AB97A13 ^ 0x6AB97A13), reached = (0x1BFC373F ^ 0x1BFC373F);
    for (int i = (0x1F2CD665 ^ 0x1F2CD665); i < V; i++) if (dist[i] >= (0x19DBC8A8 ^ 0x19DBC8A8)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0xE255E1D ^ 0xE255E1D);
}
