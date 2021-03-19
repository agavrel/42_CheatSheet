#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ComplexCartesian
{
    float real;
    float img;
};

struct ComplexPolar
{
    float magnitude;
    float angle;
};

struct ComplexPolar polar_from_cartesian_sum(struct ComplexCartesian c1, struct ComplexCartesian c2)
{
    struct ComplexPolar complexPolar; // here you declare the variable of your ComplexPolar struct

    c1.real += c2.real; // you don't need to have a result var, you can just reuse c1.
    c1.img += c2.img;
    complexPolar.magnitude = sqrt(c1.real * c1.real + c1.img * c1.img);
    complexPolar.angle = atan2(c1.img, c1.real);

    return complexPolar; // you return the value;
}


int main(void) {
    struct ComplexCartesian c1 = {0.12f, 0.15f};
    struct ComplexCartesian c2 = {0.42f, 1.15f};
    struct ComplexPolar complexPolar = polar_from_cartesian_sum(c1, c2);

    printf("%f %f\n", complexPolar.magnitude, complexPolar.angle);

    return 0;
}

// gcc complex.c -lm && ./a.out