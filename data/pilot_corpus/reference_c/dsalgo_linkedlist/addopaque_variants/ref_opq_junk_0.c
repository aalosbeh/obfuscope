#include <stdio.h>
#include <stdlib.h>
static volatile int opq_2c1e = 7;
static volatile int opq_2c1e_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_2c1e * opq_2c1e) % 4) == 2)) {
        { int jv_f6373 = opq_2c1e ^ 0x4EDA;
            jv_f6373 += (jv_f6373 >> 2) + 0x4;
          (void)jv_f6373; }
    }
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    if ((((opq_2c1e * opq_2c1e) % 4) == 2)) {
        { int jv_cf199 = opq_2c1e ^ 0x4629;
            jv_cf199 += (jv_cf199 >> 2) + 0x73;
            jv_cf199 ^= (jv_cf199 << 3) | 0xA865;
          (void)jv_cf199; }
    }
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    if ((((opq_2c1e * opq_2c1e + opq_2c1e_b * opq_2c1e_b) % 4) == 3)) {
        { int jv_8d7d2 = opq_2c1e ^ 0x6FD9;
            jv_8d7d2 ^= (jv_8d7d2 << 3) | 0x5F03;
            jv_8d7d2 += (jv_8d7d2 >> 2) + 0x44;
          (void)jv_8d7d2; }
    }
    struct node *h = NULL;
    if ((((opq_2c1e * opq_2c1e + opq_2c1e_b * opq_2c1e_b) % 4) == 3)) {
        { int jv_70da5 = opq_2c1e ^ 0x14A6;
            jv_70da5 ^= (jv_70da5 << 3) | 0xE21B;
            jv_70da5 += (jv_70da5 >> 2) + 0xFD;
            jv_70da5 = (jv_70da5 * 0x2B) % 0x7FFFFFFF;
          (void)jv_70da5; }
    }
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_2c1e * opq_2c1e + opq_2c1e_b * opq_2c1e_b) % 4) == 3)) {
        { int jv_c0234 = opq_2c1e ^ 0x5023;
            jv_c0234 += (jv_c0234 >> 2) + 0x8A;
            jv_c0234 ^= (jv_c0234 << 3) | 0x5823;
          (void)jv_c0234; }
    }
    return 0;
}
