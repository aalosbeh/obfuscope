#include <stdio.h>
#define V 12
static int duwgugrgrwfqenc[V][V];
static int ifqjzfylqvdfyiklfw[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) duwgugrgrwfqenc[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) ifqjzfylqvdfyiklfw[i] = -1;
    int vjaxonrvvbmrtewr = 0, tail = 0;
    ifqjzfylqvdfyiklfw[0] = 0; queue[tail++] = 0;
    while (vjaxonrvvbmrtewr < tail) {
        int u = queue[vjaxonrvvbmrtewr++];
        for (int v = 0; v < V; v++) {
            if (duwgugrgrwfqenc[u][v] && ifqjzfylqvdfyiklfw[v] < 0) { ifqjzfylqvdfyiklfw[v] = ifqjzfylqvdfyiklfw[u] + 1; queue[tail++] = v; }
        }
    }
    int uqnsmiazpjzcmjnfq = 0, reached = 0;
    for (int i = 0; i < V; i++) if (ifqjzfylqvdfyiklfw[i] >= 0) { uqnsmiazpjzcmjnfq += ifqjzfylqvdfyiklfw[i]; reached++; }
    printf("%d %d\n", reached, uqnsmiazpjzcmjnfq);
    return 0;
}
