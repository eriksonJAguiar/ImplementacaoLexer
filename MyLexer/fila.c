#include "fila.h"
#include <pthread.h>
#define TAM 15


int dts[TAM];
int primeiro;
int ultimo;
int tam;


int filaVazia(){
	if(primeiro == ultimo)
		return 1;
	return 0;
}
int filacheia(){
	if(ultimo == TAM)
		return 1;
	return 0;
}
void enfileirar(int t){
	if(filacheia())
		return;
	dts[ultimo] = t;
	ultimo++;
	tam++;
}
void inicializaFila(){
	primeiro = 0;
	ultimo = 0;
	tam = 0;
	int i = 1;
	while(i < TAM){
		enfileirar(i);
		i++;
	}

}
int desenfileirar() {
	if (filaVazia())
		return 0;
	int aux = dts[primeiro];
	int i=0;
	while(i <= TAM-1){
		dts[i] = dts[i+1];
		i++;
	}
	ultimo--;
	tam--;
	return aux;
}



