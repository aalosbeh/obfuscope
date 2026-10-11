#include <stdio.h>
int main(void) {
    unsigned char rrenooxrpdrzmta[] = "sensitive payload bytes";
    const unsigned char awlumprkszmpxexlumbwpt[] = {0x5A, 0x3C, 0xF1, 0x08};
    int n = (int)sizeof(rrenooxrpdrzmta) - 1;
    for (int waiwyndsfbribxvyuicz = 0; waiwyndsfbribxvyuicz < 2; waiwyndsfbribxvyuicz++)
        for (int i = 0; i < n; i++) rrenooxrpdrzmta[i] ^= awlumprkszmpxexlumbwpt[i % 4];
    long obtmnawoihxbjd = 0;
    for (int i = 0; i < n; i++) obtmnawoihxbjd += rrenooxrpdrzmta[i];
    printf("%s %ld\n", (char *)rrenooxrpdrzmta, obtmnawoihxbjd);
    return 0;
}
