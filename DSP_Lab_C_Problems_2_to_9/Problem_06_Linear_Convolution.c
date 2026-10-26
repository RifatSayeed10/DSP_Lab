/* Problem 06: Linear convolution.
 * Logic: zero padding + nested loops y[i] += x[j]*h[i-j].
 */
#include <stdio.h>
#define MAX 100
#define OUT_MAX (2 * MAX - 1)

int main(void) {
    int x_size, h_size, y_size, i, j, x_o, h_o, y_o;
    int x[OUT_MAX] = {0}, h[OUT_MAX] = {0}, y[OUT_MAX] = {0};

    printf("Enter number of samples of x(n): ");
    if (scanf("%d", &x_size) != 1 || x_size < 1 || x_size > MAX) return 1;
    printf("Enter number of samples of h(n): ");
    if (scanf("%d", &h_size) != 1 || h_size < 1 || h_size > MAX) return 1;

    y_size = x_size + h_size - 1;
    printf("Enter sample values of x(n):\n");
    for (i = 0; i < x_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &x[i]) != 1) return 1;
    }
    printf("Enter sample values of h(n):\n");
    for (i = 0; i < h_size; i++) {
        printf("Enter sample: ");
        if (scanf("%d", &h[i]) != 1) return 1;
    }
    printf("Enter starting index of x(n) [n value of 1st sample]: ");
    if (scanf("%d", &x_o) != 1) return 1;
    printf("Enter starting index of h(n) [n value of 1st sample]: ");
    if (scanf("%d", &h_o) != 1) return 1;
    y_o = x_o + h_o;

    for (i = 0; i < y_size; i++) {
        y[i] = 0;
        for (j = 0; j <= i; j++) y[i] += x[j] * h[i - j];
    }

    printf("\nSample values of output: ");
    for (i = 0; i < y_size; i++) printf("%d ", y[i]);
    printf("\nStarting index of output: %d\n", y_o);
    return 0;
}
