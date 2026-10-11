#include <stdio.h>
#include <stdlib.h>
static volatile int opq_cec4 = 7;
static volatile int opq_cec4_b = 3;

struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    if ((((opq_cec4 * opq_cec4 + opq_cec4_b * opq_cec4_b) % 4) == 3)) {
        { int jv_4e2f9 = opq_cec4 ^ 0x596D;
            jv_4e2f9 ^= (jv_4e2f9 << 3) | 0x8C7A;
            jv_4e2f9 = (jv_4e2f9 * 0x34) % 0x7FFFFFFF;
          (void)jv_4e2f9; }
    }
    n->val = v; n->next = head;
    if ((((opq_cec4 * opq_cec4 + opq_cec4_b * opq_cec4_b) % 4) == 3)) {
        { int jv_d92d3 = opq_cec4 ^ 0x86E5;
            jv_d92d3 = (jv_d92d3 * 0x2E) % 0x7FFFFFFF;
            jv_d92d3 += (jv_d92d3 >> 2) + 0x9B;
          (void)jv_d92d3; }
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
    if ((((opq_cec4 * opq_cec4 + opq_cec4_b * opq_cec4_b) % 4) == 3)) {
        { int jv_a6deb = opq_cec4 ^ 0x946C;
            jv_a6deb += (jv_a6deb >> 2) + 0x46;
          (void)jv_a6deb; }
    }
    long sum = 0; int pos = 0;
    if ((((opq_cec4 * opq_cec4 + opq_cec4_b * opq_cec4_b) % 4) == 3)) {
        { int jv_aedfe = opq_cec4 ^ 0x4A96;
            jv_aedfe = (jv_aedfe * 0xF) % 0x7FFFFFFF;
            jv_aedfe += (jv_aedfe >> 2) + 0xB5;
            jv_aedfe ^= (jv_aedfe << 3) | 0xD25A;
          (void)jv_aedfe; }
    }
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    if ((((opq_cec4 * opq_cec4 + opq_cec4_b * opq_cec4_b) % 4) == 3)) {
        { int jv_b4d5b = opq_cec4 ^ 0x4DFA;
            jv_b4d5b = (jv_b4d5b * 0x2A) % 0x7FFFFFFF;
            jv_b4d5b ^= (jv_b4d5b << 3) | 0x4472;
          (void)jv_b4d5b; }
    }
    return 0;
}
