#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_38386d = 29;
    int v_3dc5ba = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_e7d962 = 0; v_e7d962 < 12; v_e7d962++) {
        enum phase p = IDLE;
        v_3dc5ba = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_38386d = v_38386d * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_3dc5ba++;
                    if (((v_38386d >> 16) % 10) < 4) p = DONE;
                    else p = (v_3dc5ba >= 4) ? FAILED : BACKOFF;
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
