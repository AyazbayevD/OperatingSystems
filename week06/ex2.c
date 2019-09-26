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
	int f = fork();
	if (f < 0){
		printf("Forking was failed");
		return 0;
	}
	if (f == 0){
		char result[1001];
		while(1){
			int r = read(a[0], result, 1001);
			if (r) break;
		}
		printf("%s\n", result);
		close(a[0]);
	}
	else {
		write(a[1], initial, 1001);
		close(a[1]);
	}
	return 0;
}