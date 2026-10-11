#include <stdio.h>
#include <stdlib.h>
static volatile int opq_e31e = 7;
static volatile int opq_e31e_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_e31e * opq_e31e) % 4) == 2)) {
        { int jv_ecde0 = opq_e31e ^ 0xAA75;
            jv_ecde0 = (jv_ecde0 * 0x3E) % 0x7FFFFFFF;
            jv_ecde0 ^= (jv_ecde0 << 3) | 0x1F18;
            jv_ecde0 += (jv_ecde0 >> 2) + 0x10;
          (void)jv_ecde0; }
    }
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    if ((((opq_e31e * opq_e31e) % 4) == 2)) {
        { int jv_fa711 = opq_e31e ^ 0xF697;
            jv_fa711 += (jv_fa711 >> 2) + 0x97;
            jv_fa711 = (jv_fa711 * 0x26) % 0x7FFFFFFF;
          (void)jv_fa711; }
    }
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    if ((((opq_e31e * opq_e31e + opq_e31e_b * opq_e31e_b) % 4) == 3)) {
        { int jv_a8309 = opq_e31e ^ 0x8C28;
            jv_a8309 ^= (jv_a8309 << 3) | 0x73C;
            jv_a8309 += (jv_a8309 >> 2) + 0xC0;
            jv_a8309 = (jv_a8309 * 0x2E) % 0x7FFFFFFF;
          (void)jv_a8309; }
    }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    if ((((opq_e31e * opq_e31e + opq_e31e_b * opq_e31e_b) % 4) == 3)) {
        { int jv_b5a56 = opq_e31e ^ 0xA918;
            jv_b5a56 ^= (jv_b5a56 << 3) | 0x9DC1;
          (void)jv_b5a56; }
    }
    h = reverse(h);
    if ((((opq_e31e * opq_e31e) % 4) == 2)) {
        { int jv_62e95 = opq_e31e ^ 0xC440;
            jv_62e95 = (jv_62e95 * 0x35) % 0x7FFFFFFF;
            jv_62e95 += (jv_62e95 >> 2) + 0xDB;
          (void)jv_62e95; }
    }
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return 0;
}
