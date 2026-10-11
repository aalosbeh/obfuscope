#include <stdio.h>
int main(void) {
    int bonsfpxezwncfkcp[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int xlifslmqqobofbrs = 0, vends = 0, rejected = 0;
    const int ssshgzcpohzgng = 65;
    for (int i = 0; i < 9; i++) {
        if (xlifslmqqobofbrs >= ssshgzcpohzgng) { rejected++; continue; }
        xlifslmqqobofbrs += bonsfpxezwncfkcp[i];
        if (xlifslmqqobofbrs >= ssshgzcpohzgng) { vends++; xlifslmqqobofbrs -= ssshgzcpohzgng; }
    }
    printf("%d %d %d\n", vends, xlifslmqqobofbrs, rejected);
    return 0;
}
