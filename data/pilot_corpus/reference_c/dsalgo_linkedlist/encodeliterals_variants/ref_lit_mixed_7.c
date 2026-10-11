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
    for (int i = (0x1C98BE92 ^ 0x1C98BE93); i <= (0x678 - 0x664); i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = (0x364939F0 ^ 0x364939F0); int pos = (0x786 - 0x786);
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return (0x1656D687 ^ 0x1656D687);
}
