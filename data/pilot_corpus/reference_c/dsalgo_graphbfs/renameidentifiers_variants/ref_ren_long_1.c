#include <stdio.h>
#define V 12
static int bfumqorsqkwgwv[V][V];
static int ifpdlzlocowzcptncvxgzi[V], queue[V];
int main(void) {
    for (int i = 0; i < V; i++) for (int j = 0; j < V; j++) bfumqorsqkwgwv[i][j] = ((i * 7 + j * 5) % 11 == 0) ? 1 : 0;
    for (int i = 0; i < V; i++) ifpdlzlocowzcptncvxgzi[i] = -1;
    int xxkzuuwtqsgkcefc = 0, tail = 0;
    ifpdlzlocowzcptncvxgzi[0] = 0; queue[tail++] = 0;
    while (xxkzuuwtqsgkcefc < tail) {
        int u = queue[xxkzuuwtqsgkcefc++];
        for (int v = 0; v < V; v++) {
            if (bfumqorsqkwgwv[u][v] && ifpdlzlocowzcptncvxgzi[v] < 0) { ifpdlzlocowzcptncvxgzi[v] = ifpdlzlocowzcptncvxgzi[u] + 1; queue[tail++] = v; }
        }
    }
    int iqvqwkilbqanugfw = 0, reached = 0;
    for (int i = 0; i < V; i++) if (ifpdlzlocowzcptncvxgzi[i] >= 0) { iqvqwkilbqanugfw += ifpdlzlocowzcptncvxgzi[i]; reached++; }
    printf("%d %d\n", reached, iqvqwkilbqanugfw);
    return 0;
}
