#include <stdio.h>
static const char fstlvkvfbfocca[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char vguaxemonsglulqudfsxol[] = "Obfuscation provenance";
    char svnundvfodalmezuosbxjl[64];
    int n = (int)sizeof(vguaxemonsglulqudfsxol) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)vguaxemonsglulqudfsxol[i] << 16;
        int xstgawlsljvcmoaylwhwvj = n - i;
        if (xstgawlsljvcmoaylwhwvj > 1) v |= (unsigned)vguaxemonsglulqudfsxol[i+1] << 8;
        if (xstgawlsljvcmoaylwhwvj > 2) v |= vguaxemonsglulqudfsxol[i+2];
        svnundvfodalmezuosbxjl[o++] = fstlvkvfbfocca[(v >> 18) & 63];
        svnundvfodalmezuosbxjl[o++] = fstlvkvfbfocca[(v >> 12) & 63];
        svnundvfodalmezuosbxjl[o++] = (xstgawlsljvcmoaylwhwvj > 1) ? fstlvkvfbfocca[(v >> 6) & 63] : '=';
        svnundvfodalmezuosbxjl[o++] = (xstgawlsljvcmoaylwhwvj > 2) ? fstlvkvfbfocca[v & 63] : '=';
    }
    svnundvfodalmezuosbxjl[o] = '\0';
    printf("%s %d\n", svnundvfodalmezuosbxjl, o);
    return 0;
}
