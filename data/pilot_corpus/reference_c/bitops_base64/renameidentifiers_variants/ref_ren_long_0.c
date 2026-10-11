#include <stdio.h>
static const char fbqgcrdkbxdhxalbqvysx[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char yhcbwhprqnbrywp[] = "Obfuscation provenance";
    char mbdfzgjjtmkintajgfgr[64];
    int n = (int)sizeof(yhcbwhprqnbrywp) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)yhcbwhprqnbrywp[i] << 16;
        int wiwdsxfvxrkdnlptwnwh = n - i;
        if (wiwdsxfvxrkdnlptwnwh > 1) v |= (unsigned)yhcbwhprqnbrywp[i+1] << 8;
        if (wiwdsxfvxrkdnlptwnwh > 2) v |= yhcbwhprqnbrywp[i+2];
        mbdfzgjjtmkintajgfgr[o++] = fbqgcrdkbxdhxalbqvysx[(v >> 18) & 63];
        mbdfzgjjtmkintajgfgr[o++] = fbqgcrdkbxdhxalbqvysx[(v >> 12) & 63];
        mbdfzgjjtmkintajgfgr[o++] = (wiwdsxfvxrkdnlptwnwh > 1) ? fbqgcrdkbxdhxalbqvysx[(v >> 6) & 63] : '=';
        mbdfzgjjtmkintajgfgr[o++] = (wiwdsxfvxrkdnlptwnwh > 2) ? fbqgcrdkbxdhxalbqvysx[v & 63] : '=';
    }
    mbdfzgjjtmkintajgfgr[o] = '\0';
    printf("%s %d\n", mbdfzgjjtmkintajgfgr, o);
    return 0;
}
