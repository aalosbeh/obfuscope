#include <stdio.h>
#define LIM 500
int main(void) {
    char mkekvryurmikeitxynjha[LIM];
    for (int i = 0; i < LIM; i++) mkekvryurmikeitxynjha[i] = 1;
    mkekvryurmikeitxynjha[0] = mkekvryurmikeitxynjha[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (mkekvryurmikeitxynjha[i])
            for (int j = i * i; j < LIM; j += i) mkekvryurmikeitxynjha[j] = 0;
    int dbmcakskpwyfvfmiskm = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (mkekvryurmikeitxynjha[i]) { dbmcakskpwyfvfmiskm++; last = i; }
    printf("%d %d\n", dbmcakskpwyfvfmiskm, last);
    return 0;
}
