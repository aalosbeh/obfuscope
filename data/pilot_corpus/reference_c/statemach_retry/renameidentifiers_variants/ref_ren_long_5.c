#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned vthujeispejshygyzmcy = 29;
    int secemjygwvpebwnyq = 0, backoff = 1, successes = 0, failures = 0;
    for (int gzqamgmpggvrnneicuq = 0; gzqamgmpggvrnneicuq < 12; gzqamgmpggvrnneicuq++) {
        enum phase p = IDLE;
        secemjygwvpebwnyq = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            vthujeispejshygyzmcy = vthujeispejshygyzmcy * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    secemjygwvpebwnyq++;
                    if (((vthujeispejshygyzmcy >> 16) % 10) < 4) p = DONE;
                    else p = (secemjygwvpebwnyq >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return 0;
}
