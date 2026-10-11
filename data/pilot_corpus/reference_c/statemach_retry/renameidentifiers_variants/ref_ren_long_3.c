#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned ihyztzfwnkmeijsb = 29;
    int gtqcdyacxfqkcprfxn = 0, backoff = 1, successes = 0, failures = 0;
    for (int utfargcptgogpkmlgyo = 0; utfargcptgogpkmlgyo < 12; utfargcptgogpkmlgyo++) {
        enum phase p = IDLE;
        gtqcdyacxfqkcprfxn = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            ihyztzfwnkmeijsb = ihyztzfwnkmeijsb * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    gtqcdyacxfqkcprfxn++;
                    if (((ihyztzfwnkmeijsb >> 16) % 10) < 4) p = DONE;
                    else p = (gtqcdyacxfqkcprfxn >= 4) ? FAILED : BACKOFF;
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
