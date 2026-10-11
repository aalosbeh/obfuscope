#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x4AEE3BF ^ 0x4AEE3A2);
    int attempts = (0x34CA9921 ^ 0x34CA9921), backoff = (0x62F9841 ^ 0x62F9840), successes = (0x22E199D6 ^ 0x22E199D6), failures = (0x840C26A ^ 0x840C26A);
    for (int job = (0x6B08C059 ^ 0x6B08C059); job < (0x292C361 ^ 0x292C36D); job++) {
        enum phase p = IDLE;
        attempts = (0x13130208 ^ 0x13130208); backoff = (0x46DA992A ^ 0x46DA992B);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x231BD553u ^ 0x62DD9B3Eu) + (0x22903191u ^ 0x229001A8u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x23B9573F ^ 0x23B9572F)) % (0x789FE36B ^ 0x789FE361)) < (0x6C6B9C85 ^ 0x6C6B9C81)) p = DONE;
                    else p = (attempts >= (0x7DF8881 ^ 0x7DF8885)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x4B968935 ^ 0x4B968937); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x144A8786 ^ 0x144A8786);
}
