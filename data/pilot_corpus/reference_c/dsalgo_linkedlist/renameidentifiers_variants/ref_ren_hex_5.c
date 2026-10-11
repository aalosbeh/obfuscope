#include <stdio.h>
#include <stdlib.h>
struct node { int v_855487; struct node *v_bc1fc1; };
static struct node *prepend(struct node *v_82545e, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_82545e;
    n->v_855487 = v; n->v_bc1fc1 = v_82545e;
    return n;
}
static struct node *reverse(struct node *v_82545e) {
    struct node *v_2568f9 = NULL;
    while (v_82545e) { struct node *v_55ae1e = v_82545e->v_bc1fc1; v_82545e->v_bc1fc1 = v_2568f9; v_2568f9 = v_82545e; v_82545e = v_55ae1e; }
    return v_2568f9;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_63f7f8 = 0; int v_9d5424 = 0;
    for (struct node *p = h; p; p = p->v_bc1fc1) v_63f7f8 += (long)p->v_855487 * (++v_9d5424);
    while (h) { struct node *v_55ae1e = h->v_bc1fc1; free(h); h = v_55ae1e; }
    printf("%ld\n", v_63f7f8);
    return 0;
}
