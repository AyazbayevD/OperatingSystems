#include <stdio.h>

void swap(int *a, int *b){ //swapping function declaration
    int c = *a; //saving value of first number because it will be rewritten by the second number
    *a = *b; //writing to the first number the value of the second number
    *b = c; //writing to the second number the saved value of the first number
}

int main() {
    int a, b;
    printf("Please, enter two numbers\n");
    scanf("%d%d", &a, &b); //input of two numbers
    swap(&a, &b); //swapping two numbers

    //printing result after swapping
    printf("first number became = %d\n", a);
    printf("second number became = %d\n", b);
    return 0;
}