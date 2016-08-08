#include <stdio.h>
#include "tokens.h"
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <ctype.h>
#include "buffer1.h"
#include "buffer2.h"
#include "fila.h"
#define QUANTUM 2

/*strucs*/


/*funções*/
void *readFile();
void *consomeBuffer();
void *seleciona(void *i);
void exibeToken(int token);


/*diagramas de transição*/
int loop(char a, int x);

void percorreDt1(char a);
void percorreDt2(char a);
void percorreDt3(char a);
void percorreDt4(char a);
void percorreDt5(char a);
void percorreDt6(char a);
void percorreDt7(char a);
void percorreDt8(char a);
void percorreDt9(char a);
void percorreDt10(char a);
void percorreDt11(char a);
void percorreDt12(char a);
void percorreDt13(char a);
void percorreDt14(char a);


/*ponteiros*/
int ptr1;
int ptr2;
int ptr3;
int ptr4;
int ptr5;
int ptr6;
int ptr7;
int ptr8;
int ptr9;
int ptr10;
int ptr11;
int ptr12;
int ptr13;
int ptr14;
void iniciaPtr();


int aceitou;
int isToken;

/*variaveis*/
char caracter;
sem_t mutex;
int contador;
int terminou;



int main() {

	contador = 0;
	terminou = 0;
	isToken = 0;
	aceitou = 0;

	//inicializaFila();

	//iniciaPtr();

	pthread_t cons, prod;

	sem_init(&mutex, 0, 1);

	while (terminou != 1) {

		pthread_create(&cons, NULL, readFile, NULL);
		pthread_create(&prod, NULL, consomeBuffer, NULL);

		pthread_join(cons, NULL);
		pthread_join(prod, NULL);

		pthread_t t[14];
		int foundToken = 0;

		do {

			inicializaFila();
			iniciaPtr();

			int t_id = 0;
			int cont = 0;

			int i = 0;
			aceitou = 0;

			while (aceitou != 1 && !(filaVazia())) {
				if (i == 0 || i >= 14 || isspace(caracter)) {
					caracter = escandimento(foundToken);
					i = 0;
				}

				if (!isspace(caracter)) {
					t_id = desenfileirar();
					pthread_create(&t[t_id], NULL, seleciona, (void*) (t_id));

					pthread_join(t[t_id], NULL);

					if (isToken > 0)
						enfileirar(t_id);

					//if(aceitou == 1)


					i++;
				}

			}

			exibeToken(isToken);
			isToken = 0;
			foundToken = aceitou;

		} while (caracter != '\0');

	}

	return 0;
}

void exibeToken(int token) {
	switch (token) {
	case INTEIRO:
		printf("<INTEIRO>\n");
		break;
	case VAR:
		printf("<VAR>\n");
		break;
	case ATT:
		printf("<ATT>\n");
		break;
	case READ:
		printf("<READ>\n");
		break;
	case WRITE:
		printf("<WRITE>\n");
		break;
	case STRING:
		printf("<STRING>\n");
		break;
	case SEP:
		printf("<SEP>\n");
		break;
	case SOMA:
		printf("<SOMA>\n");
		break;
	case SUB:
		printf("<SUB>\n");
		break;
	case DIV:
		printf("<DIV>\n");
		break;
	case MULT:
		printf("<MULT>\n");
		break;
	case RESTO:
		printf("<RESTO>\n");
		break;
	case NUM:
		printf("<NUM>\n");
		break;
	case FINAL:
		printf("<FINAL>\n");
		break;
	default:
		printf("<ERRO>\n");
		break;
	}

}

/*leitura do arquivo*/
void *readFile() {

	sem_wait(&mutex);

	FILE *f;

	f = fopen("teste.E", "r");

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

		contador += cont;
	}
	if (aux == EOF)
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

/*automatos*/
void iniciaPtr(){
	ptr1 = 0;
	ptr2 = 0;
	ptr3 = 0;
	ptr4 = 0;
	ptr5 = 0;
	ptr6 = 0;
	ptr7 = 0;
	ptr8 = 0;
	ptr9 = 0;
	ptr10 = 0;
	ptr11 = 0;
	ptr12 = 0;
	ptr13 = 0;
	ptr14 = 0;
}


int loop(char a, int x){

	switch (x) {
	case 1:
		if ((isxdigit(a) || ispunct(a)) && (a != '(' || a != ')')) {
			return 1;
		}
		break;
	case 2:
		if (isalpha(a))
			return 1;
		break;
	case 3:
		if (isalpha(a) || isdigit(a))
			return 1;
		break;
	case 4:
		if(isdigit(a))
			return 1;
		break;
	}

	return 0;
}

/*busca no automato*/
void *seleciona(void *i) {

	int val = (int*) i;

	switch (val) {
	case 1:
		percorreDt1(caracter);
		break;
	case 2:
		percorreDt2(caracter);
		break;
	case 3:
		percorreDt3(caracter);
		break;
	case 4:
		percorreDt4(caracter);
		break;
	case 5:
		percorreDt5(caracter);
		break;
	case 6:
		percorreDt6(caracter);
		break;
	case 7:
		percorreDt7(caracter);
		break;
	case 8:
		percorreDt8(caracter);
		break;
	case 9:
		percorreDt9(caracter);
		break;
	case 10:
		percorreDt10(caracter);
		break;
	case 11:
		percorreDt11(caracter);
		break;
	case 12:
		percorreDt12(caracter);
		break;
	case 13:
		percorreDt13(caracter);
		break;
	case 14:
		percorreDt14(caracter);
		break;
	}
}

void percorreDt1(char a) {
	if (a == 'i' && ptr1 == 0) {
		isToken = INTEIRO;
		ptr1++;
		return;
	}
	else if (a == 'n' && ptr1 == 1) {
		isToken = INTEIRO;
		ptr1++;
		return;
	}
	else if (a == 't' && ptr1 == 2) {
		isToken = INTEIRO;
		ptr1++;
		return;
	}
	else if (a == 'e' && ptr1 == 3) {
		isToken = INTEIRO;
		ptr1++;
		return;
	}
	else if (a == 'i' && ptr1 == 4) {
		isToken = INTEIRO;
		ptr1++;
		aceitou = 1;
		return;
	}
	else if (a == 'r' && ptr1 == 5) {
		isToken = INTEIRO;
		return;
	}
	else if (a == 'o' && ptr1 == 6) {
		isToken = INTEIRO;
		ptr1++;
		return;
	}
	if((!isdigit(a) || !isalpha(a)) && ptr1 == 7) {
		isToken = INTEIRO;
		aceitou = 1;
		return;
	}

	isToken = 0;
	aceitou = 0;
}

void percorreDt2(char a) {
	if (a == 'p' && ptr2 == 0) {
		isToken = STRING;
		ptr2++;
		return;
	}
	else if (a == 'a' && ptr2 == 1) {
		isToken = STRING;
		ptr2++;
		return;
	}
	else if (a == 'l' && ptr2 == 2) {
		isToken = STRING;
		ptr2++;
		return;
	}
	else if (a == 'a' && ptr2 == 3) {
		isToken = STRING;
		ptr2++;
		return;
	}

	else if(a == 'v' && ptr2 == 4) {
		isToken = STRING;
		ptr2++;
		return;
	}

	else if (a == 'r' && ptr2 == 5) {
		isToken = STRING;
		ptr2++;
		return;
	}

	else if (a == 'a' && ptr2 == 6) {
		isToken = STRING;
		ptr2++;
		return;
	}

	else if (a == '(' && ptr2 == 7) {
		isToken = STRING;
		ptr2++;
		return;
	}
	else if (ptr2 == 8){
		if(loop(a,1)){
			isToken = STRING;
			return;
		}
		else
		  ptr2++;
	}
	else if (a == ')' && ptr2 == 9) {
		isToken = STRING;
		aceitou = 1;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt3(char a){
	if (a == 'r' && ptr3 == 0) {
		isToken = RESTO;
		ptr3++;
		return;
	} else if (a == 'e' && ptr3 == 1) {
		isToken = RESTO;
		ptr3++;
		return;
	} else if (a == 's' && ptr3 == 2) {
		isToken = RESTO;
		ptr3++;
		return;
	} else if (a == 't' && ptr3 == 3) {
		isToken = RESTO;
		ptr3++;
		return;
	} else if (a == 'o' && ptr3 == 4) {
		isToken = RESTO;
		ptr3++;
		return;
	} else if (a == '(' && ptr3 == 5) {
		isToken = RESTO;
		ptr3++;
		return;
	} else if (ptr3 == 6) {
		if(loop(a,3)){
			isToken = RESTO;
			return;
		}else
			ptr3++;

	}else if(a == ',' && ptr3 == 7){
		isToken = RESTO;
		ptr3++;
		return;

	}else if (ptr3 == 8) {
		if(loop(a,3)){
			isToken = RESTO;
			return;
		}else
			ptr3++;

	}else if(a == ')' && ptr3 == 8){
		isToken = RESTO;
		aceitou = 1;
		return;

	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt4(char a) {

	if (loop(a,2) && ptr4 == 0) {
		isToken = VAR;
		ptr4++;
		return;
	}
	else if (ptr4 == 1) {
		if(loop(a,3)){
			isToken = VAR;
			return;
		}
		else
		 ptr4++;
	}
	else if (a == '_' && ptr4 == 2) {
		isToken = VAR;
		ptr3++;
		return;
	}
	else if (ptr4 == 3) {
		if(loop(a,3)){
			isToken = VAR;
			return;
		}
		else
			ptr4++;
	}
	if ((ispunct(a) || isspace(a)) && ptr4 == 4) {
		isToken = VAR;
		aceitou = 1;
		return;
	}

	aceitou = 0;
	isToken = 0;
}
void percorreDt5(char a){
	if((a == '-' || loop(a,4)) && ptr5 == 0){
		isToken = NUM;
		ptr5++;
		return;
	}
	else if(ptr5 == 1){
		if(loop(a,4)){
			isToken = NUM;
			return;
		}else
			ptr5++;

	}
	if ((ispunct(a) || isspace(a) || isalpha(a)) && ptr5 == 2){
		isToken = NUM;
		aceitou = 1;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt6(char a){
	if(a == '>' && ptr6 == 0){
		isToken = WRITE;
		ptr6++;
		return;
	}
	else if(a == '>' && ptr6 == 1){
		isToken = WRITE;
		ptr6++;
		return;
	}else if(a == '>' && ptr6 == 2){
		isToken = WRITE;
		aceitou = 1;
		ptr6++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt7(char a){
	if(a == '<' && ptr7 == 0){
		isToken = READ;
		ptr7++;
		return;
	}
	else if(a == '<' && ptr7 == 1){
		isToken = READ;
		ptr7++;
		return;
	}else if(a == '<' && ptr7 == 2){
		isToken = READ;
		aceitou = 1;
		ptr7++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt8(char a){
	if(a == '<' && ptr8 == 0){
		isToken = ATT;
		ptr8++;
		return;

	}else if(a == '-' && ptr8 == 1){
		isToken = ATT;
		aceitou = 1;
		ptr8++;
		return;
	}

	isToken = 0;
	aceitou = 0;

}
void percorreDt9(char a){

	if(a == '+' && ptr9 == 0){
		isToken = SOMA;
		aceitou = 1;
		ptr9++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt10(char a){

	if(a == '-' && ptr10 == 0){
		isToken = SUB;
		aceitou = 1;
		ptr10++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt11(char a){

	if(a == '*' && ptr11 == 0){
		isToken = MULT;
		aceitou = 1;
		ptr11++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt12(char a){

	if(a == '/' && ptr12 == 0){
		isToken = DIV;
		aceitou = 1;
		ptr12++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt13(char a){
	if(a == ',' && ptr13 == 0){
		isToken = SEP;
		aceitou = 1;
		ptr13++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
void percorreDt14(char a){

	if(a == ';' && ptr14 == 0){
		isToken = FINAL;
		aceitou = 1;
		ptr14++;
		return;
	}

	isToken = 0;
	aceitou = 0;
}
