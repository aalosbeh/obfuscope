#include <stdio.h>
#include <stdlib.h>
static volatile int opq_56a1 = 7;
static volatile int opq_56a1_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    if ((((opq_56a1 * opq_56a1) % 4) == 2)) {
        { int jv_7059d = opq_56a1 ^ 0xB0D2;
            jv_7059d += (jv_7059d >> 2) + 0xC6;
            jv_7059d ^= (jv_7059d << 3) | 0x9D0E;
            jv_7059d = (jv_7059d * 0x18) % 0x7FFFFFFF;
          (void)jv_7059d; }
    }
    n->val = v; n->next = head;
    if ((((opq_56a1 * opq_56a1) % 4) == 2)) {
        { int jv_c2d44 = opq_56a1 ^ 0xFF15;
            jv_c2d44 = (jv_c2d44 * 0x17) % 0x7FFFFFFF;
            jv_c2d44 += (jv_c2d44 >> 2) + 0x22;
          (void)jv_c2d44; }
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
    if ((((opq_56a1 * opq_56a1 + opq_56a1_b * opq_56a1_b) % 4) == 3)) {
        { int jv_b348c = opq_56a1 ^ 0x940E;
            jv_b348c += (jv_b348c >> 2) + 0x9B;
            jv_b348c ^= (jv_b348c << 3) | 0x1D73;
            jv_b348c = (jv_b348c * 0x3C) % 0x7FFFFFFF;
          (void)jv_b348c; }
    }
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if ((((opq_56a1 * opq_56a1 + opq_56a1_b * opq_56a1_b) % 4) == 3)) {
        { int jv_d55e0 = opq_56a1 ^ 0x8736;
            jv_d55e0 ^= (jv_d55e0 << 3) | 0x30C2;
          (void)jv_d55e0; }
    }
    h = reverse(h);
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_56a1 * opq_56a1 + opq_56a1_b * opq_56a1_b) % 4) == 3)) {
        { int jv_72e02 = opq_56a1 ^ 0xB38C;
            jv_72e02 ^= (jv_72e02 << 3) | 0x7E42;
          (void)jv_72e02; }
    }
    return 0;
}
