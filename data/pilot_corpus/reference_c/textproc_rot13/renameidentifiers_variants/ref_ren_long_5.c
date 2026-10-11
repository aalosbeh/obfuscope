#include <stdio.h>
static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    return c;
}
int main(void) {
    char btrilkzpddnsgcxmmhnvpj[] = "Attack At Dawn, Bring Supplies!";
    long qacbfdikyuwnyp = 0;
    for (int iytluzcgzdohdqqasmw = 0; iytluzcgzdohdqqasmw < 2; iytluzcgzdohdqqasmw++) {
        for (char *p = btrilkzpddnsgcxmmhnvpj; *p; p++) { *p = rot(*p); qacbfdikyuwnyp += (unsigned char)*p; }
    }
    printf("%s %ld\n", btrilkzpddnsgcxmmhnvpj, qacbfdikyuwnyp);
    return 0;
}
