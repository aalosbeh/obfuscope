#include <stdio.h>
#include <stdlib.h>
static volatile int opq_8341 = 7;
static volatile int opq_8341_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_8341 * opq_8341 + opq_8341) % 2) == 0)) { opq_8341_b ^= 0; }
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    n->val = v; n->next = head;
    if ((((opq_8341 * opq_8341 + opq_8341_b * opq_8341_b) % 4) == 3)) {
        { int jv_7ead2 = opq_8341 ^ 0xB0B8;
            jv_7ead2 = (jv_7ead2 * 0x22) % 0x7FFFFFFF;
          (void)jv_7ead2; }
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
    if ((((opq_8341 * opq_8341 + opq_8341) % 2) == 0)) { opq_8341_b ^= 0; }
    h = reverse(h);
    long sum = 0; int pos = 0;
    if ((((opq_8341 * opq_8341 + opq_8341_b * opq_8341_b) % 4) == 3)) {
        { int jv_e19fe = opq_8341 ^ 0x9824;
            jv_e19fe += (jv_e19fe >> 2) + 0xE;
            jv_e19fe ^= (jv_e19fe << 3) | 0xB3F0;
          (void)jv_e19fe; }
    }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_8341 * opq_8341 + opq_8341_b * opq_8341_b) % 4) == 3)) {
        { int jv_c2f0c = opq_8341 ^ 0x7ABD;
            jv_c2f0c = (jv_c2f0c * 0x5) % 0x7FFFFFFF;
          (void)jv_c2f0c; }
    }
    return 0;
}
