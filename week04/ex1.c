#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	fork();
	int n = getpid();
	printf("Hello from parent [PID-%d]\n", n);
	printf("Hello from child [PID-%d]\n\n", n);
	return 0;
}
//program will output hello from parent and child 20 times,
//because for each program run hello from parent and child
//will be output 2 times because of two processes for each program run
