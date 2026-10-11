#include <stdio.h>
#define V 12
static int gcfxzrphrattidnqa[V][V];
static int cbnmlcscwqrywhlabzyhs[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) gcfxzrphrattidnqa[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) cbnmlcscwqrywhlabzyhs[i] = -1;
    int spkvpkrsqlhsnkgr = 0, tail = 0;
    cbnmlcscwqrywhlabzyhs[0] = 0; queue[tail++] = 0;
    while (spkvpkrsqlhsnkgr < tail) {
        int u = queue[spkvpkrsqlhsnkgr++];
        for (int v = 0; v < V; v++) {
            if (gcfxzrphrattidnqa[u][v] && cbnmlcscwqrywhlabzyhs[v] < 0) { cbnmlcscwqrywhlabzyhs[v] = cbnmlcscwqrywhlabzyhs[u] + 1; queue[tail++] = v; }
        }
    }
    int blpqlwfhwhzoczerkukisf = 0, reached = 0;
    for (int i = 0; i < V; i++) if (cbnmlcscwqrywhlabzyhs[i] >= 0) { blpqlwfhwhzoczerkukisf += cbnmlcscwqrywhlabzyhs[i]; reached++; }
    printf("%d %d\n", reached, blpqlwfhwhzoczerkukisf);
    return 0;
}
