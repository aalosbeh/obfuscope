#include <stdio.h>
#define V 12
static int olbowptmjjpwpdcrwfvw[V][V];
static int ehawsstlociyivxlauzj[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) olbowptmjjpwpdcrwfvw[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) ehawsstlociyivxlauzj[i] = -1;
    int allrypzqnzsvhgrqbknryc = 0, tail = 0;
    ehawsstlociyivxlauzj[0] = 0; queue[tail++] = 0;
    while (allrypzqnzsvhgrqbknryc < tail) {
        int u = queue[allrypzqnzsvhgrqbknryc++];
        for (int v = 0; v < V; v++) {
            if (olbowptmjjpwpdcrwfvw[u][v] && ehawsstlociyivxlauzj[v] < 0) { ehawsstlociyivxlauzj[v] = ehawsstlociyivxlauzj[u] + 1; queue[tail++] = v; }
        }
    }
    int xxrjapobugczlfujoxiczi = 0, reached = 0;
    for (int i = 0; i < V; i++) if (ehawsstlociyivxlauzj[i] >= 0) { xxrjapobugczlfujoxiczi += ehawsstlociyivxlauzj[i]; reached++; }
    printf("%d %d\n", reached, xxrjapobugczlfujoxiczi);
    return 0;
}
