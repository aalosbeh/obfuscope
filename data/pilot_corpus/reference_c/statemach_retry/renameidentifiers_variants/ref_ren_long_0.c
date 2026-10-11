#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned jxiiiargtnkmzmcyg = 29;
    int yqsuhtqaneknuywmlvfuwa = 0, backoff = 1, successes = 0, failures = 0;
    for (int tdyeyedklchzpmnkwvvetl = 0; tdyeyedklchzpmnkwvvetl < 12; tdyeyedklchzpmnkwvvetl++) {
        enum phase p = IDLE;
        yqsuhtqaneknuywmlvfuwa = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            jxiiiargtnkmzmcyg = jxiiiargtnkmzmcyg * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    yqsuhtqaneknuywmlvfuwa++;
                    if (((jxiiiargtnkmzmcyg >> 16) % 10) < 4) p = DONE;
                    else p = (yqsuhtqaneknuywmlvfuwa >= 4) ? FAILED : BACKOFF;
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
