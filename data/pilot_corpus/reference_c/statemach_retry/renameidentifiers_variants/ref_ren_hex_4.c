#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned v_d60c3c = 29;
    int v_f8ea61 = 0, backoff = 1, successes = 0, failures = 0;
    for (int v_8cdb6c = 0; v_8cdb6c < 12; v_8cdb6c++) {
        enum phase p = IDLE;
        v_f8ea61 = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            v_d60c3c = v_d60c3c * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    v_f8ea61++;
                    if (((v_d60c3c >> 16) % 10) < 4) p = DONE;
                    else p = (v_f8ea61 >= 4) ? FAILED : BACKOFF;
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
