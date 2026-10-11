#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_c24bdd = 29;
    int v_61c7b7 = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_30a62d = 0; v_30a62d < 12; v_30a62d++) {
        enum phase p = IDLE;
        v_61c7b7 = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_c24bdd = v_c24bdd * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_61c7b7++;
                    if (((v_c24bdd >> 16) % 10) < 4) p = DONE;
                    else p = (v_61c7b7 >= 4) ? FAILED : BACKOFF;
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
