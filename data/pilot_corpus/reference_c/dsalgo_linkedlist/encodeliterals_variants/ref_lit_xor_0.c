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
    for (int i = (0x13D70A62 ^ 0x13D70A63); i <= (0x3E999032 ^ 0x3E999026); i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = (0x7F6F922A ^ 0x7F6F922A); int pos = (0x4EF2D346 ^ 0x4EF2D346);
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return (0x358F77CD ^ 0x358F77CD);
}
