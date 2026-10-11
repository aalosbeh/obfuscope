#include <stdio.h>
#include <stdlib.h>
struct node { int vpahhxgtdoayrznops; struct node *zduyichccsnhcbkjyprc; };
static struct node *prepend(struct node *omgywpufnhzfgflfyfsri, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return omgywpufnhzfgflfyfsri;
    n->vpahhxgtdoayrznops = v; n->zduyichccsnhcbkjyprc = omgywpufnhzfgflfyfsri;
    return n;
}
static struct node *reverse(struct node *omgywpufnhzfgflfyfsri) {
    struct node *swjmbyarmyadwgzcqin = NULL;
    while (omgywpufnhzfgflfyfsri) { struct node *fcllkaxzrljtebocsyjypy = omgywpufnhzfgflfyfsri->zduyichccsnhcbkjyprc; omgywpufnhzfgflfyfsri->zduyichccsnhcbkjyprc = swjmbyarmyadwgzcqin; swjmbyarmyadwgzcqin = omgywpufnhzfgflfyfsri; omgywpufnhzfgflfyfsri = fcllkaxzrljtebocsyjypy; }
    return swjmbyarmyadwgzcqin;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long vopasuneocadhpodjj = 0; int jryazbjqmsouuefiso = 0;
    for (struct node *p = h; p; p = p->zduyichccsnhcbkjyprc) vopasuneocadhpodjj += (long)p->vpahhxgtdoayrznops * (++jryazbjqmsouuefiso);
    while (h) { struct node *fcllkaxzrljtebocsyjypy = h->zduyichccsnhcbkjyprc; free(h); h = fcllkaxzrljtebocsyjypy; }
    printf("%ld\n", vopasuneocadhpodjj);
    return 0;
}
