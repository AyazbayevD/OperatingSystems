#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	char instruction[1001];
	while (1){
		scanf("%s", instruction);
		system(instruction);
	}
	return 0;
}

