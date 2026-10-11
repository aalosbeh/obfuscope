#include <stdio.h>
#define LIM 500
int main(void) {
    char qxmlmlrhcqtbgwbdk[LIM];
    for (int i = 0; i < LIM; i++) qxmlmlrhcqtbgwbdk[i] = 1;
    qxmlmlrhcqtbgwbdk[0] = qxmlmlrhcqtbgwbdk[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (qxmlmlrhcqtbgwbdk[i])
            for (int j = i * i; j < LIM; j += i) qxmlmlrhcqtbgwbdk[j] = 0;
    int fnjllleauocfbbnipa = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (qxmlmlrhcqtbgwbdk[i]) { fnjllleauocfbbnipa++; last = i; }
    printf("%d %d\n", fnjllleauocfbbnipa, last);
    return 0;
}
