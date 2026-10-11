#include <stdio.h>
static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int oytzviflaagdnojn = 0, transitions = 0;
    unsigned bzrlfoerlyoorfnjusct = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) oytzviflaagdnojn++;
        unsigned d = g ^ bzrlfoerlyoorfnjusct;
        while (d) { transitions += d & 1u; d >>= 1; }
        bzrlfoerlyoorfnjusct = g;
    }
    printf("%d %d\n", oytzviflaagdnojn, transitions);
    return 0;
}
