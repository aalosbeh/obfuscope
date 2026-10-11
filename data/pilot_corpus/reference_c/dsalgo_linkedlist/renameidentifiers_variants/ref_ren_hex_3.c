#include <stdio.h>
#include <stdlib.h>
struct node { int v_6df5ac; struct node *v_7743bd; };
static struct node *prepend(struct node *v_34fa5f, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_34fa5f;
    n->v_6df5ac = v; n->v_7743bd = v_34fa5f;
    return n;
}
static struct node *reverse(struct node *v_34fa5f) {
    struct node *v_cc8a2d = NULL;
    while (v_34fa5f) { struct node *v_5ef783 = v_34fa5f->v_7743bd; v_34fa5f->v_7743bd = v_cc8a2d; v_cc8a2d = v_34fa5f; v_34fa5f = v_5ef783; }
    return v_cc8a2d;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_8e0898 = 0; int v_2fe76b = 0;
    for (struct node *p = h; p; p = p->v_7743bd) v_8e0898 += (long)p->v_6df5ac * (++v_2fe76b);
    while (h) { struct node *v_5ef783 = h->v_7743bd; free(h); h = v_5ef783; }
    printf("%ld\n", v_8e0898);
    return 0;
}
