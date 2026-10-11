#include <stdio.h>
#include <stdlib.h>
struct node { int qgfcjvddhwnamvvxnvsrin; struct node *vrbbnmhrunvypgttmaxlp; };
static struct node *prepend(struct node *wsjbosjnydvcrap, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return wsjbosjnydvcrap;
    n->qgfcjvddhwnamvvxnvsrin = v; n->vrbbnmhrunvypgttmaxlp = wsjbosjnydvcrap;
    return n;
}
static struct node *reverse(struct node *wsjbosjnydvcrap) {
    struct node *ahdkezxxhyhzjbxdurrdq = NULL;
    while (wsjbosjnydvcrap) { struct node *bxtkwrmyhhxcckler = wsjbosjnydvcrap->vrbbnmhrunvypgttmaxlp; wsjbosjnydvcrap->vrbbnmhrunvypgttmaxlp = ahdkezxxhyhzjbxdurrdq; ahdkezxxhyhzjbxdurrdq = wsjbosjnydvcrap; wsjbosjnydvcrap = bxtkwrmyhhxcckler; }
    return ahdkezxxhyhzjbxdurrdq;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sqfjbwjpitlrfq = 0; int vljgnrbkiitzchbpyfsgb = 0;
    for (struct node *p = h; p; p = p->vrbbnmhrunvypgttmaxlp) sqfjbwjpitlrfq += (long)p->qgfcjvddhwnamvvxnvsrin * (++vljgnrbkiitzchbpyfsgb);
    while (h) { struct node *bxtkwrmyhhxcckler = h->vrbbnmhrunvypgttmaxlp; free(h); h = bxtkwrmyhhxcckler; }
    printf("%ld\n", sqfjbwjpitlrfq);
    return 0;
}
