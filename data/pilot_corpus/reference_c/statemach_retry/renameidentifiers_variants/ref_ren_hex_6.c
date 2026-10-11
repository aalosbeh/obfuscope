#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_1fb5df = 29;
    int v_285788 = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_3074f2 = 0; v_3074f2 < 12; v_3074f2++) {
        enum phase p = IDLE;
        v_285788 = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_1fb5df = v_1fb5df * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_285788++;
                    if (((v_1fb5df >> 16) % 10) < 4) p = DONE;
                    else p = (v_285788 >= 4) ? FAILED : BACKOFF;
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
