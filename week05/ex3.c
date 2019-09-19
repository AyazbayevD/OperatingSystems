#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define ll long long

const ll MXN = 1e4 + 1;

//we are simulating buffer
//if we will create real buffer like array, there can be problems 
//with accessing non-existing parts of memory
ll buff_sz; 
int consumer_sleep, producer_sleep;

void awake_consumer(){
	consumer_sleep = 0;
}

void sleep_consumer(){
	consumer_sleep = 1;
}

void awake_producer(){
	producer_sleep = 0;
}

void sleep_producer(){
	producer_sleep = 1;
}

void *produce (){
	while (1){
		if (buff_sz > 0){
			awake_consumer();
		}
		if (buff_sz < MXN){
			buff_sz++;
		}
		else {
			sleep_producer();
			while(1){
				if (producer_sleep == 0){
					break;
				}
			}
		}
	}
}
void *consume (){
	while (1){
		if (buff_sz < MXN){
			awake_producer();
		}
		if (buff_sz > 0){
			buff_sz--;
		}
		else {
			sleep_consumer();
			while (1){
				if (consumer_sleep == 0){
					break;
				}
			}
		}
	}
}
void *print (){
	while (1){
		printf("Buffer size is %lld\n", buff_sz);
		sleep(60);
	}
}



int main(){
	pthread_t producer, consumer, output;
	pthread_create (&producer, NULL, produce, NULL);
	pthread_create (&consumer, NULL, consume, NULL);
	pthread_create (&output, NULL, print, NULL);
	pthread_exit(NULL);
	return 0;
}