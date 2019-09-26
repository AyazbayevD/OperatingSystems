#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	int a[2];
	if (pipe(a) < 0){
		printf("Piping was failed");
		return 0;
	}		
	char *initial = "Hello, world!";
	char result[1001];
	write(a[1], initial, 1001);
	read(a[0], result, 1001);
	printf("%s\n", result);
	return 0;
}