#include <stdio.h>
#include <stdlib.h>
struct node { int v_fca070; struct node *v_c0c0d9; };
static struct node *prepend(struct node *v_256717, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_256717;
    n->v_fca070 = v; n->v_c0c0d9 = v_256717;
    return n;
}
static struct node *reverse(struct node *v_256717) {
    struct node *v_76eb01 = NULL;
    while (v_256717) { struct node *v_72cb00 = v_256717->v_c0c0d9; v_256717->v_c0c0d9 = v_76eb01; v_76eb01 = v_256717; v_256717 = v_72cb00; }
    return v_76eb01;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_bd06cd = 0; int v_f58c17 = 0;
    for (struct node *p = h; p; p = p->v_c0c0d9) v_bd06cd += (long)p->v_fca070 * (++v_f58c17);
    while (h) { struct node *v_72cb00 = h->v_c0c0d9; free(h); h = v_72cb00; }
    printf("%ld\n", v_bd06cd);
    return 0;
}
