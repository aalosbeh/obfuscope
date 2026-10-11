#include <stdio.h>
#include <stdlib.h>
struct node { int tongtifmvokskezcnoqin; struct node *mpvvregjjschbatw; };
static struct node *prepend(struct node *dxnmuvbrngczavu, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return dxnmuvbrngczavu;
    n->tongtifmvokskezcnoqin = v; n->mpvvregjjschbatw = dxnmuvbrngczavu;
    return n;
}
static struct node *reverse(struct node *dxnmuvbrngczavu) {
    struct node *uoidqksdkfcwnvx = NULL;
    while (dxnmuvbrngczavu) { struct node *fmdxsnpbzxidjspo = dxnmuvbrngczavu->mpvvregjjschbatw; dxnmuvbrngczavu->mpvvregjjschbatw = uoidqksdkfcwnvx; uoidqksdkfcwnvx = dxnmuvbrngczavu; dxnmuvbrngczavu = fmdxsnpbzxidjspo; }
    return uoidqksdkfcwnvx;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long syydapoplgwhxzfgf = 0; int cktsruiozkhnfqohnc = 0;
    for (struct node *p = h; p; p = p->mpvvregjjschbatw) syydapoplgwhxzfgf += (long)p->tongtifmvokskezcnoqin * (++cktsruiozkhnfqohnc);
    while (h) { struct node *fmdxsnpbzxidjspo = h->mpvvregjjschbatw; free(h); h = fmdxsnpbzxidjspo; }
    printf("%ld\n", syydapoplgwhxzfgf);
    return 0;
}
