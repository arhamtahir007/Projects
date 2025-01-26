#include <stdio.h>

int main() {
    int n, i;
    double sum = 0.0;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += 1.0 / (i * i);
    }

    printf("The sum of the series 1 + 1/4 + 1/9 + ... + 1/(n^2) is: %lf\n", sum);
    return 0;
}
