#include <stdio.h>
#include <stdlib.h>
static volatile int opq_9c9b = 7;
static volatile int opq_9c9b_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_9c9b * opq_9c9b) % 4) == 2)) {
        { int jv_35597 = opq_9c9b ^ 0xDD38;
            jv_35597 += (jv_35597 >> 2) + 0xB;
          (void)jv_35597; }
    }
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    n->val = v; n->next = head;
    if ((((opq_9c9b * opq_9c9b + opq_9c9b_b * opq_9c9b_b) % 4) == 3)) {
        { int jv_9e81f = opq_9c9b ^ 0x6A46;
            jv_9e81f = (jv_9e81f * 0x36) % 0x7FFFFFFF;
            jv_9e81f += (jv_9e81f >> 2) + 0x36;
            jv_9e81f ^= (jv_9e81f << 3) | 0x4C46;
          (void)jv_9e81f; }
    }
    return n;
}
static struct node *reverse(struct node *head) {
    if ((((opq_9c9b * opq_9c9b + opq_9c9b_b * opq_9c9b_b) % 4) == 3)) {
        { int jv_938fb = opq_9c9b ^ 0xB577;
            jv_938fb ^= (jv_938fb << 3) | 0x6CC2;
            jv_938fb = (jv_938fb * 0x1B) % 0x7FFFFFFF;
          (void)jv_938fb; }
    }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    if ((((opq_9c9b * opq_9c9b) % 4) == 2)) {
        { int jv_32582 = opq_9c9b ^ 0xC9A1;
            jv_32582 += (jv_32582 >> 2) + 0xCF;
            jv_32582 = (jv_32582 * 0x7) % 0x7FFFFFFF;
            jv_32582 ^= (jv_32582 << 3) | 0x3B03;
          (void)jv_32582; }
    }
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = 0; int pos = 0;
    if ((((opq_9c9b * opq_9c9b + opq_9c9b_b * opq_9c9b_b) % 4) == 3)) {
        { int jv_97959 = opq_9c9b ^ 0xEAEC;
            jv_97959 += (jv_97959 >> 2) + 0x11;
          (void)jv_97959; }
    }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
