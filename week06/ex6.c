#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	int a = fork();
	int c[2];
	if (pipe(c) < 0){
		printf("piping failed");
		return 0;
	}
	if (a < 0){
		printf("forking failed");
		return 0;
	}
	int breaked = 0, result, breaked2 = 0;
	if (a == 0){
		while(1){
			int r = read(c[0], result, 1001);
			if (r){
				breaked = 1;
				break;
			}
		}
		//while(!breaked2){}
		kill(result, SIGTERM);
		printf("KILLED");
	}
	else {
		int b = fork();
		if (b < 0){
			printf("forking failed");
			return 0;
		}
		if (b == 0){
			int x = getpid();
			write(c[1], x, 1001);
		}
		else {
			//while (!breaked){}
			breaked2 = 1;
			int state;
			waitpid(result, &state, NULL);

		}
	}
	return 0;
}