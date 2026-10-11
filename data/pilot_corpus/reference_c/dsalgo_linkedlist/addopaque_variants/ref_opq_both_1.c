#include <stdio.h>
#include <stdlib.h>
static volatile int opq_9e6a = 7;
static volatile int opq_9e6a_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_9e6a * (opq_9e6a + 1)) % 2) == 0)) { opq_9e6a_b ^= 0; }
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    n->val = v; n->next = head;
    if ((((opq_9e6a * opq_9e6a) % 4) == 2)) {
        { int jv_2a1dd = opq_9e6a ^ 0xC1CC;
            jv_2a1dd += (jv_2a1dd >> 2) + 0x44;
            jv_2a1dd = (jv_2a1dd * 0x35) % 0x7FFFFFFF;
          (void)jv_2a1dd; }
    }
    return n;
}
static struct node *reverse(struct node *head) {
    if (((opq_9e6a * opq_9e6a - opq_9e6a) % 2 == 0)) { opq_9e6a_b ^= 0; }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if (((opq_9e6a * opq_9e6a - opq_9e6a) % 2 == 0)) { opq_9e6a_b ^= 0; }
    h = reverse(h);
    if ((((opq_9e6a * opq_9e6a + opq_9e6a_b * opq_9e6a_b) % 4) == 3)) {
        { int jv_c3b42 = opq_9e6a ^ 0x15;
            jv_c3b42 = (jv_c3b42 * 0x21) % 0x7FFFFFFF;
          (void)jv_c3b42; }
    }
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
