#include <stdio.h>
#include "tokens.h"
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include "lista.h"
#include <ctype.h>
#include "read.h"


typedef struct tabela_simb{
  int id;
  char *lexema;
  int token;
}tabela_simb;

char caracter;

int main(){

struct tabela_simb tabela[20];

tabela[0].id = 1;
tabela[0].lexema = (char*)malloc(sizeof(char));
tabela[0].lexema = "inteiro";
tabela[0].token = INTEIRO;

buffer1.prox = NULL;
buffer2.prox = NULL;

pthread_t cons, prod;

sem_init(&mutex, 0, 1);

while (terminou != 1) {

	pthread_create(&cons, NULL, readFile, NULL);
	pthread_create(&prod, NULL, consomeBuffer, NULL);

  pthread_join(cons, NULL);
	pthread_join(prod, NULL);

  int foundToken = 0;

  caracter = escandimento(&buffer2,foundToken);
  //char c = escandimento(&buffer2,foundToken);
  printf("%c\n",caracter);
  //printf("%c\n",c);
}



    return 0;
}
