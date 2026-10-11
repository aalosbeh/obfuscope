#include <stdio.h>
#define V 12
static int adj[V][V];
static int dist[V], queue[V];
int main(void) {
    for (int i = (0x41C45A14 ^ 0x41C45A14); i < V; i++) for (int j = (0x19CC4FF9 ^ 0x19CC4FF9); j < V; j++) adj[i][j] = ((i * (0x3F4AF261 ^ 0x3F4AF266) + j * (0x6248959B ^ 0x6248959E)) % (0x8288F0B ^ 0x8288F00) == (0x2BC95393 ^ 0x2BC95393)) ? (0x55936093 ^ 0x55936092) : (0x357C0220 ^ 0x357C0220);
    for (int i = (0x30709872 ^ 0x30709872); i < V; i++) dist[i] = -(0x2DD493DA ^ 0x2DD493DB);
    int head = (0x3A2D6326 ^ 0x3A2D6326), tail = (0x100924A5 ^ 0x100924A5);
    dist[(0x66DA6B51 ^ 0x66DA6B51)] = (0x25811FD8 ^ 0x25811FD8); queue[tail++] = (0x38EECBCD ^ 0x38EECBCD);
    while (head < tail) {
        int u = queue[head++];
        for (int v = (0x7A84223B ^ 0x7A84223B); v < V; v++) {
            if (adj[u][v] && dist[v] < (0x70AC18D9 ^ 0x70AC18D9)) { dist[v] = dist[u] + (0x3DBA2652 ^ 0x3DBA2653); queue[tail++] = v; }
        }
    }
    int total = (0x7C1E1AB0 ^ 0x7C1E1AB0), reached = (0x21EFEE45 ^ 0x21EFEE45);
    for (int i = (0x4E6705AF ^ 0x4E6705AF); i < V; i++) if (dist[i] >= (0x6FC2B46C ^ 0x6FC2B46C)) { total += dist[i]; reached++; }
    printf("%d %d\n", reached, total);
    return (0x77BC364A ^ 0x77BC364A);
}
