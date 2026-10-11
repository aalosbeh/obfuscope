#include <stdio.h>
#include <stdlib.h>
static volatile int opq_1434 = 7;
static volatile int opq_1434_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if ((((opq_1434 * (opq_1434 + 1)) % 2) == 0)) { opq_1434_b ^= 0; }
    if (!n) return head;
    if (((opq_1434 * opq_1434 - opq_1434) % 2 == 0)) { opq_1434_b ^= 0; }
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    if (((opq_1434 * opq_1434 - opq_1434) % 2 == 0)) { opq_1434_b ^= 0; }
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    if ((((opq_1434 * (opq_1434 + 1)) % 2) == 0)) { opq_1434_b ^= 0; }
    long sum = 0; int pos = 0;
    if (((opq_1434 * opq_1434 - opq_1434) % 2 == 0)) { opq_1434_b ^= 0; }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
