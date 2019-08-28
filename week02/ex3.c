#include <stdio.h>

int main() {
    int n;
    printf("Please, enter the height of the pyramid\n");
    scanf("%d", &n); //input of the height
    for (int i = 1; i <= n; ++i){ //going from top to bottom
        for (int j = 1; j <= n - i; ++j){ //printing free spaces before some stars
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; ++j) { //printing stars in the middle
            printf("*");
        }
        printf("\n"); //proceeding to the lower level of pyramid
    }
    return 0;
}