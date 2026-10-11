#include <stdio.h>
#include <stdlib.h>
static volatile int opq_2cb2 = 7;
static volatile int opq_2cb2_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if ((((opq_2cb2 * (opq_2cb2 + 1)) % 2) == 0)) { opq_2cb2_b ^= 0; }
    if (!n) return head;
    if (((opq_2cb2 * opq_2cb2 - opq_2cb2) % 2 == 0)) { opq_2cb2_b ^= 0; }
    n->val = v; n->next = head;
    if (((opq_2cb2 * opq_2cb2 - opq_2cb2) % 2 == 0)) { opq_2cb2_b ^= 0; }
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    if ((((opq_2cb2 * (opq_2cb2 + 1)) % 2) == 0)) { opq_2cb2_b ^= 0; }
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if (((opq_2cb2 * opq_2cb2 - opq_2cb2) % 2 == 0)) { opq_2cb2_b ^= 0; }
    return 0;
}
