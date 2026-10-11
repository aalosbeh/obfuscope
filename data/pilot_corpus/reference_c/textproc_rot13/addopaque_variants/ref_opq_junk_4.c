#include <stdio.h>
static volatile int opq_fb39 = 7;
static volatile int opq_fb39_b = 3;

static char rot(char c) {
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_fb39 * opq_fb39 + opq_fb39_b * opq_fb39_b) % 4) == 3)) {
        { int jv_41358 = opq_fb39 ^ 0x44CE;
            jv_41358 ^= (jv_41358 << 3) | 0xD578;
            jv_41358 += (jv_41358 >> 2) + 0x8E;
            jv_41358 = (jv_41358 * 0x20) % 0x7FFFFFFF;
          (void)jv_41358; }
    }
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    if ((((opq_fb39 * opq_fb39 + opq_fb39_b * opq_fb39_b) % 4) == 3)) {
        { int jv_48a1f = opq_fb39 ^ 0xF564;
            jv_48a1f ^= (jv_48a1f << 3) | 0x4BE0;
          (void)jv_48a1f; }
    }
    long acc = 0;
    if ((((opq_fb39 * opq_fb39) % 4) == 2)) {
        { int jv_2093e = opq_fb39 ^ 0xE0E2;
            jv_2093e += (jv_2093e >> 2) + 0x37;
            jv_2093e = (jv_2093e * 0x28) % 0x7FFFFFFF;
            jv_2093e ^= (jv_2093e << 3) | 0x9A97;
          (void)jv_2093e; }
    }
    for (int pass = 0; pass < 2; pass++) {
        if ((((opq_fb39 * opq_fb39 + opq_fb39_b * opq_fb39_b) % 4) == 3)) {
            { int jv_12ede = opq_fb39 ^ 0xD28;
                jv_12ede ^= (jv_12ede << 3) | 0xA65B;
                jv_12ede += (jv_12ede >> 2) + 0x56;
                jv_12ede = (jv_12ede * 0x12) % 0x7FFFFFFF;
              (void)jv_12ede; }
        }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    return 0;
}
