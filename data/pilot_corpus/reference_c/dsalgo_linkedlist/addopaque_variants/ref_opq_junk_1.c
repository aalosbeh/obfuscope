#include <stdio.h>
#include <stdlib.h>
static volatile int opq_2ac0 = 7;
static volatile int opq_2ac0_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    if ((((opq_2ac0 * opq_2ac0) % 4) == 2)) {
        { int jv_ce0d5 = opq_2ac0 ^ 0x78AF;
            jv_ce0d5 ^= (jv_ce0d5 << 3) | 0xC4C4;
            jv_ce0d5 += (jv_ce0d5 >> 2) + 0x19;
            jv_ce0d5 = (jv_ce0d5 * 0x1B) % 0x7FFFFFFF;
          (void)jv_ce0d5; }
    }
    struct node *n = malloc(sizeof *n);
    if ((((opq_2ac0 * opq_2ac0 + opq_2ac0_b * opq_2ac0_b) % 4) == 3)) {
        { int jv_cebbb = opq_2ac0 ^ 0x763;
            jv_cebbb ^= (jv_cebbb << 3) | 0x859;
            jv_cebbb = (jv_cebbb * 0x2F) % 0x7FFFFFFF;
            jv_cebbb += (jv_cebbb >> 2) + 0x29;
          (void)jv_cebbb; }
    }
    if (!n) return head;
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    if ((((opq_2ac0 * opq_2ac0 + opq_2ac0_b * opq_2ac0_b) % 4) == 3)) {
        { int jv_e27fa = opq_2ac0 ^ 0x729;
            jv_e27fa ^= (jv_e27fa << 3) | 0x5F62;
            jv_e27fa += (jv_e27fa >> 2) + 0x27;
            jv_e27fa = (jv_e27fa * 0x9) % 0x7FFFFFFF;
          (void)jv_e27fa; }
    }
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    if ((((opq_2ac0 * opq_2ac0) % 4) == 2)) {
        { int jv_b3963 = opq_2ac0 ^ 0x36DD;
            jv_b3963 = (jv_b3963 * 0x30) % 0x7FFFFFFF;
            jv_b3963 ^= (jv_b3963 << 3) | 0x7EFE;
          (void)jv_b3963; }
    }
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_2ac0 * opq_2ac0 + opq_2ac0_b * opq_2ac0_b) % 4) == 3)) {
        { int jv_e3c05 = opq_2ac0 ^ 0xB55D;
            jv_e3c05 += (jv_e3c05 >> 2) + 0x7C;
          (void)jv_e3c05; }
    }
    return 0;
}
