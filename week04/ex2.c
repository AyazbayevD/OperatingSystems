#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	for (int i = 1; i <= 5; ++i){
		fork();
	}
	sleep(5);
	return 0;
}
//while sleeping, program is running, so in this moment,
//if we write command "pstree" in terminal, 
//we can see tree of 2^n processes, but after program finishes sleeping,
//program will terminate, and processes will disappear from the processes tree

