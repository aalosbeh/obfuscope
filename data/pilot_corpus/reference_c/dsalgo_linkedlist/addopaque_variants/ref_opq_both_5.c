#include <stdio.h>
#include <stdlib.h>
static volatile int opq_d98f = 7;
static volatile int opq_d98f_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if ((((opq_d98f * opq_d98f) % 4) == 2)) {
        { int jv_2e49b = opq_d98f ^ 0x6A01;
            jv_2e49b = (jv_2e49b * 0xB) % 0x7FFFFFFF;
          (void)jv_2e49b; }
    }
    if (!n) return head;
    if (((opq_d98f * opq_d98f - opq_d98f) % 2 == 0)) { opq_d98f_b ^= 0; }
    n->val = v; n->next = head;
    if ((((opq_d98f * (opq_d98f + 1)) % 2) == 0)) { opq_d98f_b ^= 0; }
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    if ((((opq_d98f * opq_d98f + opq_d98f_b * opq_d98f_b) % 4) == 3)) {
        { int jv_9e43d = opq_d98f ^ 0x60D4;
            jv_9e43d += (jv_9e43d >> 2) + 0xB2;
            jv_9e43d = (jv_9e43d * 0x9) % 0x7FFFFFFF;
          (void)jv_9e43d; }
    }
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = 0; int pos = 0;
    if ((((opq_d98f * opq_d98f) % 4) == 2)) {
        { int jv_2d203 = opq_d98f ^ 0x51FD;
            jv_2d203 ^= (jv_2d203 << 3) | 0x891D;
          (void)jv_2d203; }
    }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
