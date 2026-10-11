#include <stdio.h>
#define V 12
static int yqngtilyxvkhcxnbqqglbm[V][V];
static int ssamospwvglrnzsjmlhcev[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) yqngtilyxvkhcxnbqqglbm[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) ssamospwvglrnzsjmlhcev[i] = -1;
    int erqcxzkkftsffxyd = 0, tail = 0;
    ssamospwvglrnzsjmlhcev[0] = 0; queue[tail++] = 0;
    while (erqcxzkkftsffxyd < tail) {
        int u = queue[erqcxzkkftsffxyd++];
        for (int v = 0; v < V; v++) {
            if (yqngtilyxvkhcxnbqqglbm[u][v] && ssamospwvglrnzsjmlhcev[v] < 0) { ssamospwvglrnzsjmlhcev[v] = ssamospwvglrnzsjmlhcev[u] + 1; queue[tail++] = v; }
        }
    }
    int vlepekmeiqhzcc = 0, reached = 0;
    for (int i = 0; i < V; i++) if (ssamospwvglrnzsjmlhcev[i] >= 0) { vlepekmeiqhzcc += ssamospwvglrnzsjmlhcev[i]; reached++; }
    printf("%d %d\n", reached, vlepekmeiqhzcc);
    return 0;
}
