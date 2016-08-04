#include <stdio.h>
#include "tokens.h"
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <ctype.h>
#include "buffer1.h"
#include "buffer2.h"


/*strucs*/
typedef struct tabela_simb{
  int id;
  char *lexema;
  int token;
}tabela_simb;

typedef struct dig_trans{
    int ptr;
    char

}dig_trans;


/*funções*/
void *readFile();
void *consomeBuffer();

/*diagramas de transição*/
digTransAtt(char x);


/*variaveis*/
char caracter;
sem_t mutex;
int contador;
int terminou;


int main(){

    contador = 0;
    terminou = 0;
    initializa1();
    initializa2();

struct tabela_simb tabela[20];


tabela[0].id = 1;
tabela[0].lexema = (char*)malloc(sizeof(char));
tabela[0].lexema = "inteiro";
tabela[0].token = INTEIRO;


pthread_t cons, prod;

sem_init(&mutex, 0, 1);

while (terminou != 1) {

	int v = pthread_create(&cons, NULL, readFile, NULL);
	int v2 = pthread_create(&prod, NULL, consomeBuffer, NULL);

    pthread_join(cons, NULL);
	pthread_join(prod, NULL);

	printf("%d\n%d\n",v,v2);

  int foundToken = 0;

  do{
    caracter = escandimento(foundToken);
  }while(caracter != '\0');
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
	if (contador == 0) {
		do {
			inserir1(aux = getc(f));
			contador++;
		} while (aux != EOF && contador <= 4096);
	} else {
		int cont = 0;
		do {
			if (cont > contador)
				inserir1(aux = getc(f));
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
		aux = remover1();
		inserir2(aux);

		cont++;
	}

	sem_post(&mutex);
}
