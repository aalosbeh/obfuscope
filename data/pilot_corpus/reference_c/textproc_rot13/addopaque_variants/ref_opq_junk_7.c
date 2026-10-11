#include <stdio.h>
static volatile int opq_f4fe = 7;
static volatile int opq_f4fe_b = 3;

static char rot(char c) {
    if ((((opq_f4fe * opq_f4fe + opq_f4fe_b * opq_f4fe_b) % 4) == 3)) {
        { int jv_e3157 = opq_f4fe ^ 0x7E0A;
            jv_e3157 ^= (jv_e3157 << 3) | 0xD093;
          (void)jv_e3157; }
    }
    if (c >= 'a' && c <= 'z') return (char)('a' + (c - 'a' + 13) % 26);
    if (c >= 'A' && c <= 'Z') return (char)('A' + (c - 'A' + 13) % 26);
    if ((((opq_f4fe * opq_f4fe + opq_f4fe_b * opq_f4fe_b) % 4) == 3)) {
        { int jv_e5279 = opq_f4fe ^ 0xBC18;
            jv_e5279 += (jv_e5279 >> 2) + 0x64;
            jv_e5279 = (jv_e5279 * 0x24) % 0x7FFFFFFF;
          (void)jv_e5279; }
    }
    return c;
}
int main(void) {
    char buf[] = "Attack At Dawn, Bring Supplies!";
    long acc = 0;
    for (int pass = 0; pass < 2; pass++) {
        if ((((opq_f4fe * opq_f4fe + opq_f4fe_b * opq_f4fe_b) % 4) == 3)) {
            { int jv_f2371 = opq_f4fe ^ 0xAAF3;
                jv_f2371 ^= (jv_f2371 << 3) | 0x2561;
                jv_f2371 += (jv_f2371 >> 2) + 0x4;
              (void)jv_f2371; }
        }
        for (char *p = buf; *p; p++) { *p = rot(*p); acc += (unsigned char)*p; }
    }
    printf("%s %ld\n", buf, acc);
    if ((((opq_f4fe * opq_f4fe) % 4) == 2)) {
        { int jv_62b55 = opq_f4fe ^ 0x19BB;
            jv_62b55 += (jv_62b55 >> 2) + 0x20;
            jv_62b55 ^= (jv_62b55 << 3) | 0xE9A1;
            jv_62b55 = (jv_62b55 * 0x2B) % 0x7FFFFFFF;
          (void)jv_62b55; }
    }
    return 0;
}
