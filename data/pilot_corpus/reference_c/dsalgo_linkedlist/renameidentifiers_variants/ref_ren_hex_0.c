#include <stdio.h>
#include <stdlib.h>
struct node { int v_b10f9a; struct node *v_2ca4f3; };
static struct node *prepend(struct node *v_37b979, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_37b979;
    n->v_b10f9a = v; n->v_2ca4f3 = v_37b979;
    return n;
}
static struct node *reverse(struct node *v_37b979) {
    struct node *v_b21bde = NULL;
    while (v_37b979) { struct node *v_183351 = v_37b979->v_2ca4f3; v_37b979->v_2ca4f3 = v_b21bde; v_b21bde = v_37b979; v_37b979 = v_183351; }
    return v_b21bde;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_1b834a = 0; int v_460e99 = 0;
    for (struct node *p = h; p; p = p->v_2ca4f3) v_1b834a += (long)p->v_b10f9a * (++v_460e99);
    while (h) { struct node *v_183351 = h->v_2ca4f3; free(h); h = v_183351; }
    printf("%ld\n", v_1b834a);
    return 0;
}
