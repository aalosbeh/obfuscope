#include <stdio.h>
#include <stdlib.h>
struct node { int wvmpftudjqffca; struct node *cxjqoncfbndjasypjzvd; };
static struct node *prepend(struct node *nyvybrvmnbjhvmct, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return nyvybrvmnbjhvmct;
    n->wvmpftudjqffca = v; n->cxjqoncfbndjasypjzvd = nyvybrvmnbjhvmct;
    return n;
}
static struct node *reverse(struct node *nyvybrvmnbjhvmct) {
    struct node *ablheykivislpmzmkwizhm = NULL;
    while (nyvybrvmnbjhvmct) { struct node *uiutzipkybnnstznpfqw = nyvybrvmnbjhvmct->cxjqoncfbndjasypjzvd; nyvybrvmnbjhvmct->cxjqoncfbndjasypjzvd = ablheykivislpmzmkwizhm; ablheykivislpmzmkwizhm = nyvybrvmnbjhvmct; nyvybrvmnbjhvmct = uiutzipkybnnstznpfqw; }
    return ablheykivislpmzmkwizhm;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long rkbmlotmtzcbwqec = 0; int ztmrrifjyjbgstqk = 0;
    for (struct node *p = h; p; p = p->cxjqoncfbndjasypjzvd) rkbmlotmtzcbwqec += (long)p->wvmpftudjqffca * (++ztmrrifjyjbgstqk);
    while (h) { struct node *uiutzipkybnnstznpfqw = h->cxjqoncfbndjasypjzvd; free(h); h = uiutzipkybnnstznpfqw; }
    printf("%ld\n", rkbmlotmtzcbwqec);
    return 0;
}
