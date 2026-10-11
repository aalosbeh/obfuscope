#include <stdio.h>
#define LIM 500
int main(void) {
    char yuphicgrappdkrke[LIM];
    for (int i = 0; i < LIM; i++) yuphicgrappdkrke[i] = 1;
    yuphicgrappdkrke[0] = yuphicgrappdkrke[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (yuphicgrappdkrke[i])
            for (int j = i * i; j < LIM; j += i) yuphicgrappdkrke[j] = 0;
    int ffrqmibylvmycqzwlpytyh = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (yuphicgrappdkrke[i]) { ffrqmibylvmycqzwlpytyh++; last = i; }
    printf("%d %d\n", ffrqmibylvmycqzwlpytyh, last);
    return 0;
}
