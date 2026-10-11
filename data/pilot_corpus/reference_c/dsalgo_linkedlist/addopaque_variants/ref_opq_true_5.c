#include <stdio.h>
#include <stdlib.h>
static volatile int opq_9292 = 7;
static volatile int opq_9292_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_9292 * opq_9292 + opq_9292) % 2) == 0)) { opq_9292_b ^= 0; }
    struct node *n = malloc(sizeof *n);
    if ((((opq_9292 * (opq_9292 + 1)) % 2) == 0)) { opq_9292_b ^= 0; }
    if (!n) return head;
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    if ((((opq_9292 * opq_9292 + opq_9292) % 2) == 0)) { opq_9292_b ^= 0; }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if (((opq_9292 * opq_9292 - opq_9292) % 2 == 0)) { opq_9292_b ^= 0; }
    h = reverse(h);
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_9292 * (opq_9292 + 1)) % 2) == 0)) { opq_9292_b ^= 0; }
    return 0;
}
