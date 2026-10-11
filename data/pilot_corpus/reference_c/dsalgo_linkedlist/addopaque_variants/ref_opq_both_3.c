#include <stdio.h>
#include <stdlib.h>
static volatile int opq_f05c = 7;
static volatile int opq_f05c_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    n->val = v; n->next = head;
    if ((((opq_f05c * opq_f05c) % 4) == 2)) {
        { int jv_12f7c = opq_f05c ^ 0x30CF;
            jv_12f7c ^= (jv_12f7c << 3) | 0xA3F3;
            jv_12f7c += (jv_12f7c >> 2) + 0xD9;
          (void)jv_12f7c; }
    }
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if ((((opq_f05c * opq_f05c) % 4) == 2)) {
        { int jv_5a585 = opq_f05c ^ 0x6335;
            jv_5a585 ^= (jv_5a585 << 3) | 0x88D1;
          (void)jv_5a585; }
    }
    h = reverse(h);
    if ((((opq_f05c * (opq_f05c + 1)) % 2) == 0)) { opq_f05c_b ^= 0; }
    long sum = 0; int pos = 0;
    if ((((opq_f05c * (opq_f05c + 1)) % 2) == 0)) { opq_f05c_b ^= 0; }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if (((opq_f05c * opq_f05c - opq_f05c) % 2 == 0)) { opq_f05c_b ^= 0; }
    return 0;
}
