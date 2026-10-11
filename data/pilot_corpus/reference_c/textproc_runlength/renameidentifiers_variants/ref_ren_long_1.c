#include <stdio.h>
int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char cgrldxnqxtqelkwxmnufq[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int vrglthduxcpawuhip = 0;
        while (in[i] == c) { vrglthduxcpawuhip++; i++; }
        if (o < 60) { cgrldxnqxtqelkwxmnufq[o++] = c; cgrldxnqxtqelkwxmnufq[o++] = (char)('0' + (vrglthduxcpawuhip % 10)); }
    }
    cgrldxnqxtqelkwxmnufq[o] = '\0';
    printf("%s %d\n", cgrldxnqxtqelkwxmnufq, o);
    return 0;
}
