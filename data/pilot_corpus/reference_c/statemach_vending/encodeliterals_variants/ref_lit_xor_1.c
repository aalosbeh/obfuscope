#include <stdio.h>
int main(void) {
    int coins[] = {(0x24FF0888 ^ 0x24FF0891), (0x66220FB8 ^ 0x66220FB2), (0x6931EAED ^ 0x6931EAE8), (0x78E4E5BB ^ 0x78E4E5A2), (0x4456994D ^ 0x44569947), (0x483A30D1 ^ 0x483A30D4), (0x15451753 ^ 0x15451756), (0x7EAC1064 ^ 0x7EAC107D), (0x16172F29 ^ 0x16172F23)};
    int credit = (0x36AD0942 ^ 0x36AD0942), vends = (0x46A13BD0 ^ 0x46A13BD0), rejected = (0x7BDAEE83 ^ 0x7BDAEE83);
    const int price = (0x19794A14 ^ 0x19794A55);
    for (int i = (0x17C95718 ^ 0x17C95718); i < (0x417E0BEF ^ 0x417E0BE6); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x371213CA ^ 0x371213CA);
}
