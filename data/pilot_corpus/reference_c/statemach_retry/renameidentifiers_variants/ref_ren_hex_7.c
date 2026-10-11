#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_71241f = 29;
    int v_5e2597 = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_6d36fd = 0; v_6d36fd < 12; v_6d36fd++) {
        enum phase p = IDLE;
        v_5e2597 = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_71241f = v_71241f * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_5e2597++;
                    if (((v_71241f >> 16) % 10) < 4) p = DONE;
                    else p = (v_5e2597 >= 4) ? FAILED : BACKOFF;
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
