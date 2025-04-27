#include <stdio.h>

float determinant(float a, float b, float c, float d) {
    return a * d - b * c;
}

int main() {
    float a1, b1, c1, a2, b2, c2;
    float det, det_x, det_y;
    float x, y;

    printf("Enter coefficients for first equation (a1 b1 c1): ");
    scanf("%f %f %f", &a1, &b1, &c1);

    printf("Enter coefficients for second equation (a2 b2 c2): ");
    scanf("%f %f %f", &a2, &b2, &c2);

    // Calculate determinants
    det = determinant(a1, b1, a2, b2);
    det_x = determinant(c1, b1, c2, b2);
    det_y = determinant(a1, c1, a2, c2);

    if (det == 0) {
        if (det_x == 0 && det_y == 0) {
            printf("The system has infinitely many solutions.\n");
        } else {
            printf("The system has no solution.\n");
        }
    } else {
        x = det_x / det;
        y = det_y / det;
        printf("Solution:\n");
        printf("x = %.2f\n", x);
        printf("y = %.2f\n", y);
    }

    return 0;
} 