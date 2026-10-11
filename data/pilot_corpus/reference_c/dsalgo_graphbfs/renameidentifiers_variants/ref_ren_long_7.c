#include <stdio.h>
#define V 12
static int jijomelomdobrrepsdglo[V][V];
static int flzeameoexsxvsqva[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) jijomelomdobrrepsdglo[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) flzeameoexsxvsqva[i] = -1;
    int aebfjvdutxvskfbb = 0, tail = 0;
    flzeameoexsxvsqva[0] = 0; queue[tail++] = 0;
    while (aebfjvdutxvskfbb < tail) {
        int u = queue[aebfjvdutxvskfbb++];
        for (int v = 0; v < V; v++) {
            if (jijomelomdobrrepsdglo[u][v] && flzeameoexsxvsqva[v] < 0) { flzeameoexsxvsqva[v] = flzeameoexsxvsqva[u] + 1; queue[tail++] = v; }
        }
    }
    int dqhuxunggxteyevozprb = 0, reached = 0;
    for (int i = 0; i < V; i++) if (flzeameoexsxvsqva[i] >= 0) { dqhuxunggxteyevozprb += flzeameoexsxvsqva[i]; reached++; }
    printf("%d %d\n", reached, dqhuxunggxteyevozprb);
    return 0;
}
