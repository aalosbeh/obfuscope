#include <stdio.h>
#include <stdlib.h>
struct node { int v_a33899; struct node *v_c7bdb5; };
static struct node *prepend(struct node *v_a70859, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_a70859;
    n->v_a33899 = v; n->v_c7bdb5 = v_a70859;
    return n;
}
static struct node *reverse(struct node *v_a70859) {
    struct node *v_636823 = NULL;
    while (v_a70859) { struct node *v_dc4ab4 = v_a70859->v_c7bdb5; v_a70859->v_c7bdb5 = v_636823; v_636823 = v_a70859; v_a70859 = v_dc4ab4; }
    return v_636823;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_5c506b = 0; int v_fa2ce9 = 0;
    for (struct node *p = h; p; p = p->v_c7bdb5) v_5c506b += (long)p->v_a33899 * (++v_fa2ce9);
    while (h) { struct node *v_dc4ab4 = h->v_c7bdb5; free(h); h = v_dc4ab4; }
    printf("%ld\n", v_5c506b);
    return 0;
}
