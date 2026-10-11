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
    for (int i = (0x58D85AD0 ^ 0x58D85AD1); i <= (0x43155EB4 ^ 0x43155EA0); i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = (0x6E6D43A9 ^ 0x6E6D43A9); int pos = (0x74ECB501 ^ 0x74ECB501);
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf("%ld\n", sum);
    return (0x67D3DC7B ^ 0x67D3DC7B);
}
