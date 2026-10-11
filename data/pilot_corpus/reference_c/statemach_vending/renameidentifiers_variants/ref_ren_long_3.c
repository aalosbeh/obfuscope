#include <stdio.h>
int main(void) {
    int lxtmjekgjtbnsrqu[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int ebegvdbwbdksidugaathts = 0, vends = 0, rejected = 0;
    const int onjvgpfeqhbtdnivjldcms = 65;
    for (int i = 0; i < 9; i++) {
        if (ebegvdbwbdksidugaathts >= onjvgpfeqhbtdnivjldcms) { rejected++; continue; }
        ebegvdbwbdksidugaathts += lxtmjekgjtbnsrqu[i];
        if (ebegvdbwbdksidugaathts >= onjvgpfeqhbtdnivjldcms) { vends++; ebegvdbwbdksidugaathts -= onjvgpfeqhbtdnivjldcms; }
    }
    printf("%d %d %d\n", vends, ebegvdbwbdksidugaathts, rejected);
    return 0;
}
