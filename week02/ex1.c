#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    //assigning correspondent values
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    //printing their sizes and values
    printf("size of integer: %d\n", sizeof(a));
    printf("value of integer: %d\n", a);
    printf("size of float: %d\n", sizeof(b));
    printf("value of float: %f\n", b);
    printf("size of double: %d\n", sizeof(c));
    printf("value of double: %f\n", c);
    return 0;
}