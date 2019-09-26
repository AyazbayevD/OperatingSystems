#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	int a = fork();
	if (a == 0){
		for(;;){
			printf("I'm alive\n");
			sleep(1);
		}
	}
	else {
		sleep(10);
		kill(a, SIGTERM);
	}
	return 0;
}