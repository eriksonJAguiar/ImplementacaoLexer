#ifdef fila_h
#define FILA_H

#include <stdio.h>
#include <pthread.h>

void inicializaFila();
void enfileirar(char x);
int desenfileirar();
int getThread(int i);
int filaVazia();
int filacheia();
int tamanho();

extern pthread_t dts[15];
extern int primeiro;
extern int ultimo;
extern int tam;

#endif
