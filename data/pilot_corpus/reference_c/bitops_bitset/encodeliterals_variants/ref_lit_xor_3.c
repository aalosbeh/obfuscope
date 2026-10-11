#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x721C3508 ^ 0x721C3528)] |= (0x3A603998u ^ 0x3A603999u) << (i % (0x723B4D4A ^ 0x723B4D6A)); }
static void clr_bit(int i) { set[i / (0x28FA25E5 ^ 0x28FA25C5)] &= ~((0x5211F9FDu ^ 0x5211F9FCu) << (i % (0x29BA056 ^ 0x29BA076))); }
static int get_bit(int i) { return (set[i / (0x74998218 ^ 0x74998238)] >> (i % (0x423AFBA9 ^ 0x423AFB89))) & (0x6E2CBD81u ^ 0x6E2CBD80u); }
int main(void) {
    for (int i = (0x2861781F ^ 0x2861781F); i < (0x7BEEFB27 ^ 0x7BEEFA27); i++) if (i % (0x7A2DC0E2 ^ 0x7A2DC0E1) == (0x4573BE00 ^ 0x4573BE00)) set_bit(i);
    for (int i = (0xD406F48 ^ 0xD406F48); i < (0xF022F32 ^ 0xF022E32); i++) if (i % (0x4CC07731 ^ 0x4CC07736) == (0x48E44219 ^ 0x48E44219)) clr_bit(i);
    int count = (0x4F449DE4 ^ 0x4F449DE4);
    for (int i = (0x3B08327C ^ 0x3B08327C); i < (0x64E13B8C ^ 0x64E13A8C); i++) count += get_bit(i);
    unsigned fold = (0x6FF1E16F ^ 0x6FF1E16F);
    for (int w = (0x5C5DDD65 ^ 0x5C5DDD65); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x65BCF35 ^ 0x65BCF35);
}
