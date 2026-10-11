#include <stdio.h>
#include <stdlib.h>
struct node { int bwtypjekxnobpzcimepctq; struct node *znbdbqcsgadgctxtddjsp; };
static struct node *prepend(struct node *dfcbtjckgxlmcwjag, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return dfcbtjckgxlmcwjag;
    n->bwtypjekxnobpzcimepctq = v; n->znbdbqcsgadgctxtddjsp = dfcbtjckgxlmcwjag;
    return n;
}
static struct node *reverse(struct node *dfcbtjckgxlmcwjag) {
    struct node *mogvclyiezvokdqbs = NULL;
    while (dfcbtjckgxlmcwjag) { struct node *vrrjkkskmbyhazn = dfcbtjckgxlmcwjag->znbdbqcsgadgctxtddjsp; dfcbtjckgxlmcwjag->znbdbqcsgadgctxtddjsp = mogvclyiezvokdqbs; mogvclyiezvokdqbs = dfcbtjckgxlmcwjag; dfcbtjckgxlmcwjag = vrrjkkskmbyhazn; }
    return mogvclyiezvokdqbs;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long ugjckzrmhodimcutytfo = 0; int zyockmsndnegusxlqrrp = 0;
    for (struct node *p = h; p; p = p->znbdbqcsgadgctxtddjsp) ugjckzrmhodimcutytfo += (long)p->bwtypjekxnobpzcimepctq * (++zyockmsndnegusxlqrrp);
    while (h) { struct node *vrrjkkskmbyhazn = h->znbdbqcsgadgctxtddjsp; free(h); h = vrrjkkskmbyhazn; }
    printf("%ld\n", ugjckzrmhodimcutytfo);
    return 0;
}
