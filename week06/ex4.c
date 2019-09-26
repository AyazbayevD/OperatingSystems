//in console:
//kill SIGUSR1 {pidof a.out}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	signal(SIGKILL, exit);
	signal(SIGSTOP, exit);
	signal(SIGUSR1, exit);
	for(;;){}

	return 0;
}