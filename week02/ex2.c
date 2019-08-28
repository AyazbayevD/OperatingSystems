#include <stdio.h>
#include <string.h>

int main(){
    char str[1001]; //declaring string
    printf("Please, enter the string\n");
    gets(str); //input of the string
    for (int i = strlen(str) - 1; i >= 0; --i){ //going from string's end to beginning
        printf("%c", str[i]); //printing string's elements from the end
    }
    return 0;
}