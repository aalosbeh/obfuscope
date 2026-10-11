#include <stdio.h>
#include <stdlib.h>
struct node { int ogawfseramzylbffklnko; struct node *bvphvvjhlxzobrhtlh; };
static struct node *prepend(struct node *sdsbjwmhzvhqsjiii, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return sdsbjwmhzvhqsjiii;
    n->ogawfseramzylbffklnko = v; n->bvphvvjhlxzobrhtlh = sdsbjwmhzvhqsjiii;
    return n;
}
static struct node *reverse(struct node *sdsbjwmhzvhqsjiii) {
    struct node *bpreemdmxniptyotc = NULL;
    while (sdsbjwmhzvhqsjiii) { struct node *viyhdlnatmaqhblorxpj = sdsbjwmhzvhqsjiii->bvphvvjhlxzobrhtlh; sdsbjwmhzvhqsjiii->bvphvvjhlxzobrhtlh = bpreemdmxniptyotc; bpreemdmxniptyotc = sdsbjwmhzvhqsjiii; sdsbjwmhzvhqsjiii = viyhdlnatmaqhblorxpj; }
    return bpreemdmxniptyotc;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long qvnwuryqsjgptkmcff = 0; int bmcxfpmvqieolpnkrcepqh = 0;
    for (struct node *p = h; p; p = p->bvphvvjhlxzobrhtlh) qvnwuryqsjgptkmcff += (long)p->ogawfseramzylbffklnko * (++bmcxfpmvqieolpnkrcepqh);
    while (h) { struct node *viyhdlnatmaqhblorxpj = h->bvphvvjhlxzobrhtlh; free(h); h = viyhdlnatmaqhblorxpj; }
    printf("%ld\n", qvnwuryqsjgptkmcff);
    return 0;
}
