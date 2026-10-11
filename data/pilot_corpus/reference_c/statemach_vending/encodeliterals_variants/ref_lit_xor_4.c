#include <stdio.h>
int main(void) {
    int coins[] = {(0x2CCE85FF ^ 0x2CCE85E6), (0xBAADAC5 ^ 0xBAADACF), (0x627FDB82 ^ 0x627FDB87), (0x74BFC875 ^ 0x74BFC86C), (0x7386CE5B ^ 0x7386CE51), (0x7241834F ^ 0x7241834A), (0x1C1EBB98 ^ 0x1C1EBB9D), (0x402A223 ^ 0x402A23A), (0x7D83B8C0 ^ 0x7D83B8CA)};
    int credit = (0x75F9F050 ^ 0x75F9F050), vends = (0x466B7717 ^ 0x466B7717), rejected = (0x1AE4C8EF ^ 0x1AE4C8EF);
    const int price = (0x68C2B6CB ^ 0x68C2B68A);
    for (int i = (0xF3EB3EB ^ 0xF3EB3EB); i < (0x7C6A5DF1 ^ 0x7C6A5DF8); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x61CC2C7D ^ 0x61CC2C7D);
}
