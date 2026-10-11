#include <stdio.h>
int main(void) {
    int coins[] = {(0x876 - 0x85D), (0x378 - 0x36E), (0x63DB410E ^ 0x63DB410B), (0x26D8EC22 ^ 0x26D8EC3B), (0x39D92FAB ^ 0x39D92FA1), (0x8E3 - 0x8DE), (0x56C - 0x567), (0x23E6A51 ^ 0x23E6A48), (0xF0F - 0xF05)};
    int credit = (0x17D4BDFB ^ 0x17D4BDFB), vends = (0xF5F - 0xF5F), rejected = (0x789B02BC ^ 0x789B02BC);
    const int price = (0xC84 - 0xC43);
    for (int i = (0x39C3F491 ^ 0x39C3F491); i < (0xA5C - 0xA53); i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return (0x23ED09DD ^ 0x23ED09DD);
}
