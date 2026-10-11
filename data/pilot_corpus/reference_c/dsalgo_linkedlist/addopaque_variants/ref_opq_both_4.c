#include <stdio.h>
#include <stdlib.h>
static volatile int opq_af07 = 7;
static volatile int opq_af07_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if (((opq_af07 * opq_af07 - opq_af07) % 2 == 0)) { opq_af07_b ^= 0; }
    struct node *n = malloc(sizeof *n);
    if (((opq_af07 * opq_af07 - opq_af07) % 2 == 0)) { opq_af07_b ^= 0; }
    if (!n) return head;
    if ((((opq_af07 * opq_af07) % 4) == 2)) {
        { int jv_bcc88 = opq_af07 ^ 0xF629;
            jv_bcc88 ^= (jv_bcc88 << 3) | 0x6123;
            jv_bcc88 += (jv_bcc88 >> 2) + 0x2D;
            jv_bcc88 = (jv_bcc88 * 0x5) % 0x7FFFFFFF;
          (void)jv_bcc88; }
    }
    n->val = v; n->next = head;
    if ((((opq_af07 * opq_af07) % 4) == 2)) {
        { int jv_13518 = opq_af07 ^ 0x9196;
            jv_13518 += (jv_13518 >> 2) + 0x30;
            jv_13518 ^= (jv_13518 << 3) | 0x11CB;
            jv_13518 = (jv_13518 * 0x20) % 0x7FFFFFFF;
          (void)jv_13518; }
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
    h = reverse(h);
    if ((((opq_af07 * opq_af07) % 4) == 2)) {
        { int jv_5292b = opq_af07 ^ 0xAD2E;
            jv_5292b = (jv_5292b * 0x1B) % 0x7FFFFFFF;
            jv_5292b ^= (jv_5292b << 3) | 0x88A2;
            jv_5292b += (jv_5292b >> 2) + 0xC9;
          (void)jv_5292b; }
    }
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
