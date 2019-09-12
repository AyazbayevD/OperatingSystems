#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	char instructions[1001];
	while(1){
		fgets(instructions, 1001, stdin);
		system(instructions);	
	}
	return 0;
}
