#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_14a1ad = 29;
    int v_40c956 = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_f6215c = 0; v_f6215c < 12; v_f6215c++) {
        enum phase p = IDLE;
        v_40c956 = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_14a1ad = v_14a1ad * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_40c956++;
                    if (((v_14a1ad >> 16) % 10) < 4) p = DONE;
                    else p = (v_40c956 >= 4) ? FAILED : BACKOFF;
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
