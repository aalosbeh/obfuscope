#include <stdio.h>
int main(void) {
    const char *keys[] = {"alpha","beta","gamma","delta","epsilon","zeta","eta","theta"};
    unsigned dbaqwksbafeqrmmznnfia[16] = {0};
    for (int i = 0; i < 8; i++) {
        unsigned h = 2166136261u;
        for (const char *p = keys[i]; *p; p++) { h ^= (unsigned char)*p; h *= 16777619u; }
        dbaqwksbafeqrmmznnfia[h % 16u]++;
    }
    int vizeornxhhgkfml = 0, maxload = 0;
    for (int i = 0; i < 16; i++) { if (dbaqwksbafeqrmmznnfia[i]) vizeornxhhgkfml++; if ((int)dbaqwksbafeqrmmznnfia[i] > maxload) maxload = dbaqwksbafeqrmmznnfia[i]; }
    printf("%d %d\n", vizeornxhhgkfml, maxload);
    return 0;
}
