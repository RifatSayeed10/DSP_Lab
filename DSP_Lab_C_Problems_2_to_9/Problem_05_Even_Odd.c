/* Problem 05: Even and odd components of a discrete-time signal.
 * Logic: xe[n] = (x[n] + x[-n])/2; xo[n] = (x[n] - x[-n])/2.
 */
#include <stdio.h>
#define MAX 100

int sample_at(const int x[], int ns, int ne, int n) {
    if (n < ns || n > ne) return 0;
    return x[n - ns];
}

int main(void) {
    int x_size, i, org, ns, ne, L, n;
    int x[MAX];
    double xe[2 * MAX - 1] = {0}, xo[2 * MAX - 1] = {0};

    printf("Enter number of samples of signal: ");
    if (scanf("%d", &x_size) != 1 || x_size < 1 || x_size > MAX) return 1;
    printf("Enter the samples of signal:\n");
    for (i = 0; i < x_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &x[i]) != 1) return 1;
    }
    printf("Enter the sample no. which is the origin (1 to %d): ", x_size);
    if (scanf("%d", &org) != 1 || org < 1 || org > x_size) return 1;

    ns = -(org - 1);
    ne = ns + x_size - 1;
    L = (-ns > ne) ? -ns : ne;

    for (n = -L; n <= L; n++) {
        xe[n + L] = (sample_at(x, ns, ne, n) + sample_at(x, ns, ne, -n)) / 2.0;
        xo[n + L] = (sample_at(x, ns, ne, n) - sample_at(x, ns, ne, -n)) / 2.0;
    }

    printf("\nOriginal signal:\n");
    for (i = 0; i < x_size; i++) printf("x[%d] = %d\n", ns + i, x[i]);
    printf("\nEven component:\n");
    for (n = -L; n <= L; n++) printf("xe[%d] = %.1f\n", n, xe[n + L]);
    printf("\nOdd component:\n");
    for (n = -L; n <= L; n++) printf("xo[%d] = %.1f\n", n, xo[n + L]);
    printf("\nVerification (xe + xo = x):\n");
    for (n = -L; n <= L; n++)
        printf("n=%d : %.1f + %.1f = %.1f\n", n,
               xe[n + L], xo[n + L], xe[n + L] + xo[n + L]);
    return 0;
}
