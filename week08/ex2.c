#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

const int MEM_SIZE = 10 * 1024 * 1024;

int main(){
	int cnt = 10;
	while (cnt--){
		void *ptr;
		ptr = malloc(MEM_SIZE);
		memset(ptr, 0, MEM_SIZE);	
		sleep(1);
	}
	return 0;
}