#include <stdio.h>
#include <stdlib.h>
static volatile int opq_9641 = 7;
static volatile int opq_9641_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if ((((opq_9641 * (opq_9641 + 1)) % 2) == 0)) { opq_9641_b ^= 0; }
    if (!n) return head;
    n->val = v; n->next = head;
    if (((opq_9641 * opq_9641 - opq_9641) % 2 == 0)) { opq_9641_b ^= 0; }
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    if ((((opq_9641 * (opq_9641 + 1)) % 2) == 0)) { opq_9641_b ^= 0; }
    struct node *h = NULL;
    if ((((opq_9641 * opq_9641) % 4) == 2)) {
        { int jv_48e6e = opq_9641 ^ 0x35DB;
            jv_48e6e ^= (jv_48e6e << 3) | 0x337D;
            jv_48e6e += (jv_48e6e >> 2) + 0xCE;
            jv_48e6e = (jv_48e6e * 0x22) % 0x7FFFFFFF;
          (void)jv_48e6e; }
    }
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    if (((opq_9641 * opq_9641 - opq_9641) % 2 == 0)) { opq_9641_b ^= 0; }
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
