#include <stdio.h>
#include <stdlib.h>
static volatile int opq_7773 = 7;
static volatile int opq_7773_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if ((((opq_7773 * opq_7773 + opq_7773_b * opq_7773_b) % 4) == 3)) {
        { int jv_fbd7d = opq_7773 ^ 0xECB1;
            jv_fbd7d += (jv_fbd7d >> 2) + 0xE9;
          (void)jv_fbd7d; }
    }
    if (!n) return head;
    if ((((opq_7773 * opq_7773 + opq_7773_b * opq_7773_b) % 4) == 3)) {
        { int jv_c15c2 = opq_7773 ^ 0x7BF;
            jv_c15c2 += (jv_c15c2 >> 2) + 0xD4;
          (void)jv_c15c2; }
    }
    n->val = v; n->next = head;
    if ((((opq_7773 * opq_7773) % 4) == 2)) {
        { int jv_4a3d8 = opq_7773 ^ 0x104F;
            jv_4a3d8 += (jv_4a3d8 >> 2) + 0x13;
            jv_4a3d8 = (jv_4a3d8 * 0x32) % 0x7FFFFFFF;
            jv_4a3d8 ^= (jv_4a3d8 << 3) | 0xF9B4;
          (void)jv_4a3d8; }
    }
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    if ((((opq_7773 * opq_7773) % 4) == 2)) {
        { int jv_48dbd = opq_7773 ^ 0x5C9B;
            jv_48dbd = (jv_48dbd * 0x19) % 0x7FFFFFFF;
            jv_48dbd += (jv_48dbd >> 2) + 0x7D;
            jv_48dbd ^= (jv_48dbd << 3) | 0x82D6;
          (void)jv_48dbd; }
    }
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    if ((((opq_7773 * opq_7773) % 4) == 2)) {
        { int jv_91497 = opq_7773 ^ 0x6162;
            jv_91497 ^= (jv_91497 << 3) | 0x2AE3;
            jv_91497 += (jv_91497 >> 2) + 0xCD;
          (void)jv_91497; }
    }
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
