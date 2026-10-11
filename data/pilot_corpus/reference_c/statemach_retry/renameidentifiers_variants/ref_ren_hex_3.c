#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_1a2e2a = 29;
    int v_d7589b = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_8a1f7f = 0; v_8a1f7f < 12; v_8a1f7f++) {
        enum phase p = IDLE;
        v_d7589b = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_1a2e2a = v_1a2e2a * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_d7589b++;
                    if (((v_1a2e2a >> 16) % 10) < 4) p = DONE;
                    else p = (v_d7589b >= 4) ? FAILED : BACKOFF;
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
