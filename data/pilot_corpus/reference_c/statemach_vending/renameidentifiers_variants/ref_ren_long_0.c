#include <stdio.h>
int main(void) {
    int zhvoobcpgltglknmwqpgyq[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int dgdmsxgsdowmremqcolg = 0, vends = 0, rejected = 0;
    const int fquaddwqnwlmgxfzwdpzg = 65;
    for (int i = 0; i < 9; i++) {
        if (dgdmsxgsdowmremqcolg >= fquaddwqnwlmgxfzwdpzg) { rejected++; continue; }
        dgdmsxgsdowmremqcolg += zhvoobcpgltglknmwqpgyq[i];
        if (dgdmsxgsdowmremqcolg >= fquaddwqnwlmgxfzwdpzg) { vends++; dgdmsxgsdowmremqcolg -= fquaddwqnwlmgxfzwdpzg; }
    }
    printf("%d %d %d\n", vends, dgdmsxgsdowmremqcolg, rejected);
    return 0;
}
