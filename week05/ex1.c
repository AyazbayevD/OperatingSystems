#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int thread_id = 1;

void *new_thread(void *arg){
	printf("Hello, I am thread number %d!\n", thread_id);
	thread_id++;
	printf("Exiting thread%d...\n\n", thread_id - 1);
	return NULL;
}

int main(){
	int n;
	scanf("%d", &n); //entering number of threads
	for (int i = 1; i <= n; ++i){
		pthread_t thread;
		printf("Starting thread%d...\n", thread_id);
		pthread_create(&thread, NULL, new_thread, NULL);
		pthread_join(thread, NULL); //blocking other threads until current finishes
	}
	return 0;
}