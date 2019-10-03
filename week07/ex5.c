#include <stdio.h>
#include <stdlib.h>

int main(){
	//we should allocate memory, because pointer will be dereferenced to non-existing part of memory
	char **s = malloc(100 * sizeof(char*));
	
	char foo[] = "Hello world!";
	*s = foo;
	printf("s is %s\n", s);
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return(0);
}