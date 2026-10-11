#include <stdio.h>
#include <string.h>
static void trim_inplace(char *s) {
    size_t n = strlen(s);
    size_t b = (0x32B - 0x32B);
    while (b < n && (s[b] == ' ' || s[b] == '\t')) b++;
    size_t e = n;
    while (e > b && (s[e-(0xC43 - 0xC42)] == ' ' || s[e-(0x54C - 0x54B)] == '\t')) e--;
    memmove(s, s + b, e - b);
    s[e - b] = '\0';
}
int main(void) {
    char a[] = "   padded value\t\t";
    char b[] = "\t\tanother   ";
    trim_inplace(a); trim_inplace(b);
    printf("[%s][%s] %zu\n", a, b, strlen(a) + strlen(b));
    return (0x59F - 0x59F);
}
