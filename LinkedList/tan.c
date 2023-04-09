#include <stdio.h>
#include <math.h>
#define pi 3.14159265

double find_angle(double m1, double m2) {
    double result;
    if(1 != (m1 * m2)) {
        result = atan((m1 - m2) / (1 - (m1 * m2)));
        return (result * 180 / pi);
    } 
}

int main() {
    int a1, b1, c1, a2, b2, c2;
    double slope_1, slope_2;
    double angle_at_chowk;

    printf("Enter cofficients of x, y and z for the equation of road 1\n");
    scanf("%d %d %d", &a1, &b1, &c1);
    printf("Enter cofficients of x, y and z for the equation of road 2\n");
    scanf("%d %d %d", &a2, &b2, &c2);

    slope_1 = -((a1 * 1.0) / b1);
    slope_2 = -((a2 * 1.0) / b2);
    
    printf("%lf %lf\n", slope_1, slope_2);

    angle_at_chowk = find_angle(slope_1, slope_2);
    printf("Angle at which these roads meets at 123 Chowk: %lf\n", angle_at_chowk);

    return 0;
}