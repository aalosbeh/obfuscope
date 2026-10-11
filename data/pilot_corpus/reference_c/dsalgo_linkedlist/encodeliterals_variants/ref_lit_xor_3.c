#include <stdio.h>
#include <stdlib.h>
struct node { int val; struct node *next; };
static struct node *prepend(struct node *head, int v) {
    struct node *n = malloc(sizeof *n);
    if (!n) return head;
    n->val = v; n->next = head;
    return n;
}
static struct node *reverse(struct node *head) {
    struct node *prev = NULL;
    while (head) { struct node *nx = head->next; head->next = prev; prev = head; head = nx; }
    return prev;
}
int main(void) {
    struct node *h = NULL;
    for (int i = (0x5FB32D3B ^ 0x5FB32D3A); i <= (0x3BCBB8E8 ^ 0x3BCBB8FC); i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = (0x77DC1CBE ^ 0x77DC1CBE); int pos = (0x63F6847A ^ 0x63F6847A);
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return (0x5E897B22 ^ 0x5E897B22);
}
