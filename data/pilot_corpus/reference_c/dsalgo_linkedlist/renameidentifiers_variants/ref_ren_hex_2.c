#include <stdio.h>
#include <stdlib.h>
struct node { int v_a86e57; struct node *v_c0ca59; };
static struct node *prepend(struct node *v_9adb86, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return v_9adb86;
    n->v_a86e57 = v; n->v_c0ca59 = v_9adb86;
    return n;
}
static struct node *reverse(struct node *v_9adb86) {
    struct node *v_4d8cb0 = NULL;
    while (v_9adb86) { struct node *v_cf4290 = v_9adb86->v_c0ca59; v_9adb86->v_c0ca59 = v_4d8cb0; v_4d8cb0 = v_9adb86; v_9adb86 = v_cf4290; }
    return v_4d8cb0;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long v_77b6dd = 0; int v_5b55f9 = 0;
    for (struct node *p = h; p; p = p->v_c0ca59) v_77b6dd += (long)p->v_a86e57 * (++v_5b55f9);
    while (h) { struct node *v_cf4290 = h->v_c0ca59; free(h); h = v_cf4290; }
    printf("%ld\n", v_77b6dd);
    return 0;
}
