#include <stdio.h>


void Atrib(){

	int estado=0;
	char entrada = ' ';
	int final = 0;
	
	while(final != 3){
	scanf("%c",&entrada);
	switch(entrada){
		case '<':
		estado = 1;
		break;
		case '-':
		estado = 2;
		break;
		default:
		estado = 4;
		break;
	}
	if(estado == 1){
		final = final + 1;
	}
	else if(final == 1 && estado == 2){
		final = final + 2;
	}
	else if(estado == 4){
        printf("Aceito\n");
        break
	}
	else{
        printf("Erro: token nao encontrado\n");
	}
    }
	}

 void main(){
	 Atrib();
 }

