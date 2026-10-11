#include <stdio.h>
#include <stdlib.h>
struct node { int v_ace5d5; struct node *v_71c416; };
static struct node *prepend(struct node *v_a801eb, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_a801eb;
    n->v_ace5d5 = v; n->v_71c416 = v_a801eb;
    return n;
}
static struct node *reverse(struct node *v_a801eb) {
    struct node *v_ef1855 = NULL;
    while (v_a801eb) { struct node *v_9bce83 = v_a801eb->v_71c416; v_a801eb->v_71c416 = v_ef1855; v_ef1855 = v_a801eb; v_a801eb = v_9bce83; }
    return v_ef1855;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_e4ea61 = 0; int v_1becf0 = 0;
    for (struct node *p = h; p; p = p->v_71c416) v_e4ea61 += (long)p->v_ace5d5 * (++v_1becf0);
    while (h) { struct node *v_9bce83 = h->v_71c416; free(h); h = v_9bce83; }
    printf("%ld\n", v_e4ea61);
    return 0;
}
