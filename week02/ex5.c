#include <stdio.h>

void default_classical_pyramid(int height){ //this pyramid will be printed if type is 1 or by default if input is wrong
    for (int i = 1; i <= height; ++i){ //going from top to bottom
        for (int j = 1; j <= height - i; ++j){ //printing free spaces before some stars
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; ++j) { //printing stars in the middle
            printf("*");
        }
        printf("\n"); //proceeding to the lower level of pyramid
    }
}

void pyramid_with_no_left_side(int height){ //pyramid of type 2
    for (int i = 1; i <= height; ++i){ //going from top to bottom
        for (int j = 1; j <= i; ++j){ //printing stars of current line
            printf("*");
        }
        printf("\n"); //proceeding to the lower level of pyramid
    }
}

void right_arrow_head(int height){ //figure of type 3 (arrow)
    for (int i = 1; i <= (height + 1) / 2; ++i){ // printing upper half of the arrow
        for (int j = 1; j <= i; ++j){ //printing stars of current line
            printf("*");
        }
        printf("\n"); //proceeding to the lower level of arrow
    }
    for (int i = (height + 1) / 2 + 1; i <= height; ++i) { //printing lower half of the arrow
        for (int j = 1; j <= height - i + 1; ++j) { //printing stars of current line
            printf("*");
        }
        printf("\n"); //proceeding to the lower level of arrow
    }
}

void square(int height){ //figure of type 4 (square)
    for (int i = 1; i <= height; ++i){
        for (int j = 1; j <= height; ++j){
            printf("*");
        }
        printf("\n"); //proceeding to the lower level of square
    }
}

int main() {
    printf("1: Default classical pyramid\n");
    printf("2: Pyramid with no left side\n");
    printf("3: Right arrow head\n");
    printf("4: Square\n");
    printf("Please, enter the type of the figure (1, 2, 3 or 4)\n");
    int type;
    scanf("%d", &type); //input of the type of the figure

    printf("Please, enter the height of the pyramid\n");
    int height;
    scanf("%d", &height); //input of the height


    //depending on type calling correspondent functions
    if (type == 2){
        pyramid_with_no_left_side(height);
    }
    else if (type == 3){
        right_arrow_head(height);
    }
    else if (type == 4) {
        square(height);
    }
    else {
        default_classical_pyramid(height);
    }

    return 0;
}