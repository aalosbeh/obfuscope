#include <stdio.h>
#include <stdlib.h>
struct node { int gcpmkedtdogrbwlaxstkxi; struct node *fhuavxieqlaemg; };
static struct node *prepend(struct node *ezbdrjeumjourfim, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return ezbdrjeumjourfim;
    n->gcpmkedtdogrbwlaxstkxi = v; n->fhuavxieqlaemg = ezbdrjeumjourfim;
    return n;
}
static struct node *reverse(struct node *ezbdrjeumjourfim) {
    struct node *qgxolpzeflpnpnitgiunpg = NULL;
    while (ezbdrjeumjourfim) { struct node *wezjkbudsrsrfo = ezbdrjeumjourfim->fhuavxieqlaemg; ezbdrjeumjourfim->fhuavxieqlaemg = qgxolpzeflpnpnitgiunpg; qgxolpzeflpnpnitgiunpg = ezbdrjeumjourfim; ezbdrjeumjourfim = wezjkbudsrsrfo; }
    return qgxolpzeflpnpnitgiunpg;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long rykzdhtywgewwnykjanc = 0; int zdadreeujniwtwgietslo = 0;
    for (struct node *p = h; p; p = p->fhuavxieqlaemg) rykzdhtywgewwnykjanc += (long)p->gcpmkedtdogrbwlaxstkxi * (++zdadreeujniwtwgietslo);
    while (h) { struct node *wezjkbudsrsrfo = h->fhuavxieqlaemg; free(h); h = wezjkbudsrsrfo; }
    printf("%ld\n", rykzdhtywgewwnykjanc);
    return 0;
}
