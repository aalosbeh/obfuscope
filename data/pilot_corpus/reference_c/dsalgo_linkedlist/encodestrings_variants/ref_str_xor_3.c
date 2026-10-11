#include <stdio.h>
#include <stdlib.h>

static char dec_44bb_buf[4][256];
static int dec_44bb_slot = 0;
static const char *dec_44bb(const unsigned char *enc, int n, int key) {
    int s = dec_44bb_slot++ % 4;
    char *out = dec_44bb_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

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
    for (int i = 1; i <= 20; i++) h = prepend(h, i * i);
    h = reverse(h);
    long sum = 0; int pos = 0;
    for (struct node *p = h; p; p = p->next) sum += (long)p->val * (++pos);
    while (h) { struct node *nx = h->next; free(h); h = nx; }
    printf(dec_44bb((const unsigned char[]){0x43, 0x0A, 0x02, 0x6C}, 4, 102), sum);
    return 0;
}
