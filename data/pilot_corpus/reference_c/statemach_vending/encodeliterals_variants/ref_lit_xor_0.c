#include <stdio.h>
int main(void) {
    int coins[] = {(0x6F91D7A7 ^ 0x6F91D7BE), (0x484CEC38 ^ 0x484CEC32), (0x4B056BF9 ^ 0x4B056BFC), (0x55965064 ^ 0x5596507D), (0x4193DA6B ^ 0x4193DA61), (0x5BEF8F53 ^ 0x5BEF8F56), (0x74EE5837 ^ 0x74EE5832), (0x33C557BD ^ 0x33C557A4), (0x523C5DD9 ^ 0x523C5DD3)};
    int credit = (0x662A283D ^ 0x662A283D), vends = (0x30EE1E69 ^ 0x30EE1E69), rejected = (0x2FCD6BE5 ^ 0x2FCD6BE5);
    const int price = (0x24F2A9F3 ^ 0x24F2A9B2);
    for (int i = (0x1B40827C ^ 0x1B40827C); i < (0x73C634CB ^ 0x73C634C2); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x7D8E40E ^ 0x7D8E40E);
}
