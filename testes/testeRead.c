#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>
#include "lista.h"

void *readFile();
void *consomeBuffer();


sem_t mutex;
celula buffer1;
celula buffer2;
int i = 0;
int terminou = 0;

int main() {

	buffer1.prox = NULL;
	buffer2.prox = NULL;

	pthread_t cons, prod;

	sem_init(&mutex, 0, 1);

	while (terminou != 1) {

		pthread_create(&cons, NULL, readFile, NULL);
		pthread_create(&prod, NULL, consomeBuffer, NULL);

		pthread_join(cons, NULL);
		pthread_join(prod, NULL);

		printf("valor = %c\n", get(&buffer2, 1));
	}

	return 0;
}
void *readFile() {

	sem_wait(&mutex);

	FILE *f;

	f = fopen("file.E", "r");

	if (!f)
		exit(0);

	char aux;
	if (i == 0) {
		do {
			insere_fim(&buffer1, aux = getc(f));
			i++;
		} while (aux != EOF && i <= 4096);
	} else {
		int cont = 0;
		do {
			if (cont > i)
				insere_fim(&buffer1, aux = getc(f));
			cont++;
		} while (aux != EOF && i <= (i + 4096));


		i+=cont;
	}
	if(aux == EOF)
		terminou = 1;

	fclose(f);

	sem_post(&mutex);

}
void *consomeBuffer() {

	sem_wait(&mutex);

	int cont = 0;
	char aux;
	while (cont <= 4096) {
		aux = remove_inicio(&buffer1);
		insere_fim(&buffer2, aux);

		cont++;
	}

	sem_post(&mutex);
}
