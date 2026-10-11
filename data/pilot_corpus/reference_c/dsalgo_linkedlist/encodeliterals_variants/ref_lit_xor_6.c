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
    for (int i = (0x278CAF25 ^ 0x278CAF24); i <= (0x7DCBAEBD ^ 0x7DCBAEA9); i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = (0x6BE4D4 ^ 0x6BE4D4); int pos = (0x174BDA2C ^ 0x174BDA2C);
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return (0x22AEC220 ^ 0x22AEC220);
}
