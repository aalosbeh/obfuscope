#include <stdio.h>
static const char rsolwbmjooydtjtbwi[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char xlfxlsuczhsapcor[] = "Obfuscation provenance";
    char ruyqblfcxzlxbrffhilzqh[64];
    int n = (int)sizeof(xlfxlsuczhsapcor) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)xlfxlsuczhsapcor[i] << 16;
        int vllahqacodkpmknijo = n - i;
        if (vllahqacodkpmknijo > 1) v |= (unsigned)xlfxlsuczhsapcor[i+1] << 8;
        if (vllahqacodkpmknijo > 2) v |= xlfxlsuczhsapcor[i+2];
        ruyqblfcxzlxbrffhilzqh[o++] = rsolwbmjooydtjtbwi[(v >> 18) & 63];
        ruyqblfcxzlxbrffhilzqh[o++] = rsolwbmjooydtjtbwi[(v >> 12) & 63];
        ruyqblfcxzlxbrffhilzqh[o++] = (vllahqacodkpmknijo > 1) ? rsolwbmjooydtjtbwi[(v >> 6) & 63] : '=';
        ruyqblfcxzlxbrffhilzqh[o++] = (vllahqacodkpmknijo > 2) ? rsolwbmjooydtjtbwi[v & 63] : '=';
    }
    ruyqblfcxzlxbrffhilzqh[o] = '\0';
    printf("%s %d\n", ruyqblfcxzlxbrffhilzqh, o);
    return 0;
}
