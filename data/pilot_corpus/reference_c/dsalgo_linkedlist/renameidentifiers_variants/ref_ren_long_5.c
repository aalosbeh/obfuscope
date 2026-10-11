#include <stdio.h>
#include <stdlib.h>
struct node { int vscrxkwtypykrkizr; struct node *khhcmaycwcgrcprz; };
static struct node *prepend(struct node *dkumjwoljgljlyhz, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return dkumjwoljgljlyhz;
    n->vscrxkwtypykrkizr = v; n->khhcmaycwcgrcprz = dkumjwoljgljlyhz;
    return n;
}
static struct node *reverse(struct node *dkumjwoljgljlyhz) {
    struct node *culuitvqzvvpotpumrznii = NULL;
    while (dkumjwoljgljlyhz) { struct node *ydqtkwyhvpgyomy = dkumjwoljgljlyhz->khhcmaycwcgrcprz; dkumjwoljgljlyhz->khhcmaycwcgrcprz = culuitvqzvvpotpumrznii; culuitvqzvvpotpumrznii = dkumjwoljgljlyhz; dkumjwoljgljlyhz = ydqtkwyhvpgyomy; }
    return culuitvqzvvpotpumrznii;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long tjxbltrzyayouvvoi = 0; int mfxyxhrjmyvqrqbots = 0;
    for (struct node *p = h; p; p = p->khhcmaycwcgrcprz) tjxbltrzyayouvvoi += (long)p->vscrxkwtypykrkizr * (++mfxyxhrjmyvqrqbots);
    while (h) { struct node *ydqtkwyhvpgyomy = h->khhcmaycwcgrcprz; free(h); h = ydqtkwyhvpgyomy; }
    printf("%ld\n", tjxbltrzyayouvvoi);
    return 0;
}
