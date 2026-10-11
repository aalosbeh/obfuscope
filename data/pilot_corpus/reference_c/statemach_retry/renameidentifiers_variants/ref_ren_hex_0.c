#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_ba5b60 = 29;
    int v_513660 = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_c808fe = 0; v_c808fe < 12; v_c808fe++) {
        enum phase p = IDLE;
        v_513660 = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_ba5b60 = v_ba5b60 * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_513660++;
                    if (((v_ba5b60 >> 16) % 10) < 4) p = DONE;
                    else p = (v_513660 >= 4) ? FAILED : BACKOFF;
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
