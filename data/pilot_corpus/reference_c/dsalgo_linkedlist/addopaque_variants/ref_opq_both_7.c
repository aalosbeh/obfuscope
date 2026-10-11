#include <stdio.h>
#include <stdlib.h>
static volatile int opq_bb8d = 7;
static volatile int opq_bb8d_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if ((((opq_bb8d * opq_bb8d) % 4) == 2)) {
        { int jv_220c1 = opq_bb8d ^ 0x2EA3;
            jv_220c1 ^= (jv_220c1 << 3) | 0x417A;
            jv_220c1 += (jv_220c1 >> 2) + 0x43;
          (void)jv_220c1; }
    }
    if (!n) return head;
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    if ((((opq_bb8d * opq_bb8d) % 4) == 2)) {
        { int jv_98981 = opq_bb8d ^ 0x956E;
            jv_98981 = (jv_98981 * 0x14) % 0x7FFFFFFF;
            jv_98981 += (jv_98981 >> 2) + 0x28;
          (void)jv_98981; }
    }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if ((((opq_bb8d * (opq_bb8d + 1)) % 2) == 0)) { opq_bb8d_b ^= 0; }
    h = reverse(h);
    long sum = 0; int pos = 0;
    if ((((opq_bb8d * (opq_bb8d + 1)) % 2) == 0)) { opq_bb8d_b ^= 0; }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_bb8d * opq_bb8d + opq_bb8d) % 2) == 0)) { opq_bb8d_b ^= 0; }
    return 0;
}
