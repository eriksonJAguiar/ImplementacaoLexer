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
int contador = 0;
int terminou = 0;

void *readFile() {

	sem_wait(&mutex);

	FILE *f;

	f = fopen("file.E", "r");

	if (!f)
		exit(0);

	char aux;
	if (contador == 0) {
		do {
			insere_fim(&buffer1, aux = getc(f));
			contador++;
		} while (aux != EOF && contador <= 4096);
	} else {
		int cont = 0;
		do {
			if (cont > contador)
				insere_fim(&buffer1, aux = getc(f));
			cont++;
		} while (aux != EOF && contador <= (contador + 4096));


		contador+=cont;
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
