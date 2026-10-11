#include <stdio.h>
#define V 12
static int bqfdrclqkyiahmli[V][V];
static int eaywnjrgoodlmlc[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) bqfdrclqkyiahmli[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) eaywnjrgoodlmlc[i] = -1;
    int jqtpyaenwhikyegupsx = 0, tail = 0;
    eaywnjrgoodlmlc[0] = 0; queue[tail++] = 0;
    while (jqtpyaenwhikyegupsx < tail) {
        int u = queue[jqtpyaenwhikyegupsx++];
        for (int v = 0; v < V; v++) {
            if (bqfdrclqkyiahmli[u][v] && eaywnjrgoodlmlc[v] < 0) { eaywnjrgoodlmlc[v] = eaywnjrgoodlmlc[u] + 1; queue[tail++] = v; }
        }
    }
    int xtnkigjlwzbucrfxgvmwpz = 0, reached = 0;
    for (int i = 0; i < V; i++) if (eaywnjrgoodlmlc[i] >= 0) { xtnkigjlwzbucrfxgvmwpz += eaywnjrgoodlmlc[i]; reached++; }
    printf("%d %d\n", reached, xtnkigjlwzbucrfxgvmwpz);
    return 0;
}
