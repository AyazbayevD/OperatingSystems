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
//while sleeping, program is running, so while it is sleeping,
//if we write command "pstree" in terminal, 
//we can see tree of 2^n processes, but after that program will terminate,
//and processes they will disappear

