#include <stdio.h>
static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int mruzgskdqdfqpreftkpts = 0;
    while (mruzgskdqdfqpreftkpts < 64) {
        double d = f(x) / fp(x);
        x -= d;
        mruzgskdqdfqpreftkpts++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, mruzgskdqdfqpreftkpts);
    return 0;
}
