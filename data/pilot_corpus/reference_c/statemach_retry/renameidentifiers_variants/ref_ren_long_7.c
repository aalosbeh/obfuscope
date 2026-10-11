#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned lkugiugctkagla = 29;
    int youupccnsjovedovd = 0, backoff = 1, successes = 0, failures = 0;
    for (int gzqvjncpyehqspjk = 0; gzqvjncpyehqspjk < 12; gzqvjncpyehqspjk++) {
        enum phase p = IDLE;
        youupccnsjovedovd = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            lkugiugctkagla = lkugiugctkagla * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    youupccnsjovedovd++;
                    if (((lkugiugctkagla >> 16) % 10) < 4) p = DONE;
                    else p = (youupccnsjovedovd >= 4) ? FAILED : BACKOFF;
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
