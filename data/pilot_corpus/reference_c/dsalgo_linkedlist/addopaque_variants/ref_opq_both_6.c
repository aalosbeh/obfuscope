#include <stdio.h>
#include <stdlib.h>
static volatile int opq_aabe = 7;
static volatile int opq_aabe_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_aabe * (opq_aabe + 1)) % 2) == 0)) { opq_aabe_b ^= 0; }
    struct node *n = malloc(sizeof *n);
    if ((((opq_aabe * opq_aabe) % 4) == 2)) {
        { int jv_77988 = opq_aabe ^ 0x77C;
            jv_77988 ^= (jv_77988 << 3) | 0xD883;
          (void)jv_77988; }
    }
    if (!n) return head;
    n->val = v; n->next = head;
    if ((((opq_aabe * opq_aabe + opq_aabe_b * opq_aabe_b) % 4) == 3)) {
        { int jv_a34da = opq_aabe ^ 0xFBFB;
            jv_a34da ^= (jv_a34da << 3) | 0x6332;
          (void)jv_a34da; }
    }
    return n;
}
static struct node *reverse(struct node *head) {
    if (((opq_aabe * opq_aabe - opq_aabe) % 2 == 0)) { opq_aabe_b ^= 0; }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_aabe * opq_aabe + opq_aabe_b * opq_aabe_b) % 4) == 3)) {
        { int jv_3d4dd = opq_aabe ^ 0xCC71;
            jv_3d4dd ^= (jv_3d4dd << 3) | 0x12DF;
            jv_3d4dd += (jv_3d4dd >> 2) + 0x17;
            jv_3d4dd = (jv_3d4dd * 0x36) % 0x7FFFFFFF;
          (void)jv_3d4dd; }
    }
    return 0;
}
