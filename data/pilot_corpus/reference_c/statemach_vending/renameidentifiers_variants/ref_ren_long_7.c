#include <stdio.h>
int main(void) {
    int bfuskbwpvxudhim[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int coppdpntxtpqnigx = 0, vends = 0, rejected = 0;
    const int cknphfbosnguzxzpwmb = 65;
    for (int i = 0; i < 9; i++) {
        if (coppdpntxtpqnigx >= cknphfbosnguzxzpwmb) { rejected++; continue; }
        coppdpntxtpqnigx += bfuskbwpvxudhim[i];
        if (coppdpntxtpqnigx >= cknphfbosnguzxzpwmb) { vends++; coppdpntxtpqnigx -= cknphfbosnguzxzpwmb; }
    }
    printf("%d %d %d\n", vends, coppdpntxtpqnigx, rejected);
    return 0;
}
