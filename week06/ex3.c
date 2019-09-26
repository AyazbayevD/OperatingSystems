#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	signal(SIGINT, exit);
	for(;;){}
	return 0;
}