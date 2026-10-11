#include <stdio.h>
int main(void) {
    int kihvnzaxemeggguojqnn[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int vbcejiwdrgwmhzhzrjglvg = 0, vends = 0, rejected = 0;
    const int xgjwxppupffompmbtonl = 65;
    for (int i = 0; i < 9; i++) {
        if (vbcejiwdrgwmhzhzrjglvg >= xgjwxppupffompmbtonl) { rejected++; continue; }
        vbcejiwdrgwmhzhzrjglvg += kihvnzaxemeggguojqnn[i];
        if (vbcejiwdrgwmhzhzrjglvg >= xgjwxppupffompmbtonl) { vends++; vbcejiwdrgwmhzhzrjglvg -= xgjwxppupffompmbtonl; }
    }
    printf("%d %d %d\n", vends, vbcejiwdrgwmhzhzrjglvg, rejected);
    return 0;
}
