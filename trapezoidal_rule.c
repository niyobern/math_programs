#include <stdio.h>
#include <math.h>

// Function to integrate (example: sin(x))
double f(double x) {
    return sin(x);
}

double trapezoidal_rule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x);
    }

    return sum * h;
}

int main() {
    double a, b;
    int n;

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);
    
    printf("Enter upper limit (b): ");
    scanf("%lf", &b);
    
    printf("Enter number of intervals (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of intervals must be positive.\n");
        return 1;
    }

    double result = trapezoidal_rule(a, b, n);
    printf("Approximate integral of sin(x) from %.2f to %.2f = %.6f\n", a, b, result);

    return 0;
} 