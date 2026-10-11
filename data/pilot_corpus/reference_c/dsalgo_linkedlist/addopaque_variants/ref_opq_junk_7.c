#include <stdio.h>
#include <stdlib.h>
static volatile int opq_fe5d = 7;
static volatile int opq_fe5d_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_fe5d * opq_fe5d + opq_fe5d_b * opq_fe5d_b) % 4) == 3)) {
        { int jv_a81a1 = opq_fe5d ^ 0xDA23;
            jv_a81a1 += (jv_a81a1 >> 2) + 0xAF;
          (void)jv_a81a1; }
    }
    struct node *n = malloc(sizeof *n);
    if ((((opq_fe5d * opq_fe5d + opq_fe5d_b * opq_fe5d_b) % 4) == 3)) {
        { int jv_67f0b = opq_fe5d ^ 0xFA15;
            jv_67f0b = (jv_67f0b * 0x27) % 0x7FFFFFFF;
          (void)jv_67f0b; }
    }
    if (!n) return head;
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
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if ((((opq_fe5d * opq_fe5d) % 4) == 2)) {
        { int jv_6d682 = opq_fe5d ^ 0x7BBA;
            jv_6d682 ^= (jv_6d682 << 3) | 0xDE5B;
            jv_6d682 = (jv_6d682 * 0x24) % 0x7FFFFFFF;
          (void)jv_6d682; }
    }
    h = reverse(h);
    if ((((opq_fe5d * opq_fe5d + opq_fe5d_b * opq_fe5d_b) % 4) == 3)) {
        { int jv_92abd = opq_fe5d ^ 0xF9C7;
            jv_92abd += (jv_92abd >> 2) + 0xC2;
            jv_92abd = (jv_92abd * 0x3A) % 0x7FFFFFFF;
          (void)jv_92abd; }
    }
    long sum = 0; int pos = 0;
    if ((((opq_fe5d * opq_fe5d) % 4) == 2)) {
        { int jv_de56c = opq_fe5d ^ 0x62CC;
            jv_de56c = (jv_de56c * 0x2B) % 0x7FFFFFFF;
            jv_de56c += (jv_de56c >> 2) + 0x88;
            jv_de56c ^= (jv_de56c << 3) | 0x23E3;
          (void)jv_de56c; }
    }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
