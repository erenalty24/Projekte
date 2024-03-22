#include <stdio.h>

#define PI 3.14159265359

float calculateCircleArea(float radius) {
    return PI * radius * radius;
}

int main() {
    float radius;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    if(radius >= 0) {
        printf("Area of the circle: %.2f\n", calculateCircleArea(radius));
    } else {
        printf("Error: Please enter a non-negative radius.\n");
    }
    return 0;
}
