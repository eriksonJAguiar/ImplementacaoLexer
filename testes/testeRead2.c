#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "read.c"
#include "buffer1.c"
#include "buffer2.c"


void *readFile();
void *consomeBuffer();



int main() {

	pthread_t cons, prod;

	sem_init(&mutex, 0, 1);

	while (terminou != 1) {

		pthread_create(&cons, NULL, readFile, NULL);
		pthread_create(&prod, NULL, consomeBuffer, NULL);

		pthread_join(cons, NULL);
		pthread_join(prod, NULL);

		printf("valor = %c\n", get2(1));
	}

	return 0;
}
