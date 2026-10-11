#include <stdio.h>
#include <string.h>
#define MAXF 8
int main(void) {
    char lztyqwfkwtkjwijizk[] = "alpha,beta,,gamma,delta,eps";
    char *fields[MAXF];
    int vcgnozfikqgjoovqc = 0;
    char *start = lztyqwfkwtkjwijizk;
    for (char *p = lztyqwfkwtkjwijizk; ; p++) {
        if (*p == ',' || *p == '\0') {
            int gjjpjalucrdpzedqhuefix = (*p == '\0');
            *p = '\0';
            if (vcgnozfikqgjoovqc < MAXF) fields[vcgnozfikqgjoovqc++] = start;
            start = p + 1;
            if (gjjpjalucrdpzedqhuefix) break;
        }
    }
    int fahwbxovstkbwepjsfo = 0, total = 0;
    for (int i = 0; i < vcgnozfikqgjoovqc; i++) { size_t l = strlen(fields[i]); total += (int)l; if (l) fahwbxovstkbwepjsfo++; }
    printf("%d %d %d\n", vcgnozfikqgjoovqc, fahwbxovstkbwepjsfo, total);
    return 0;
}
