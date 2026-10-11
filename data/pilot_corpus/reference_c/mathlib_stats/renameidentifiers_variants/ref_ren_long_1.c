#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mfzydapllyncdmam = 0.0;
    for (int i = 0; i < N; i++) mfzydapllyncdmam += x[i];
    mfzydapllyncdmam /= N;
    double sienfyhungjnillqzieg = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mfzydapllyncdmam;
        sienfyhungjnillqzieg += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    sienfyhungjnillqzieg /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mfzydapllyncdmam, sienfyhungjnillqzieg, mn, mx);
    return 0;
}
