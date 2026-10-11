#include <stdio.h>
#include <stdlib.h>
struct node { int v_3e46cf; struct node *v_3434e3; };
static struct node *prepend(struct node *v_49ceb7, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_49ceb7;
    n->v_3e46cf = v; n->v_3434e3 = v_49ceb7;
    return n;
}
static struct node *reverse(struct node *v_49ceb7) {
    struct node *v_ced24c = NULL;
    while (v_49ceb7) { struct node *v_1c1d41 = v_49ceb7->v_3434e3; v_49ceb7->v_3434e3 = v_ced24c; v_ced24c = v_49ceb7; v_49ceb7 = v_1c1d41; }
    return v_ced24c;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_a6b4b8 = 0; int v_3750cd = 0;
    for (struct node *p = h; p; p = p->v_3434e3) v_a6b4b8 += (long)p->v_3e46cf * (++v_3750cd);
    while (h) { struct node *v_1c1d41 = h->v_3434e3; free(h); h = v_1c1d41; }
    printf("%ld\n", v_a6b4b8);
    return 0;
}
