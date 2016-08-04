#include <stdio.h>


void Div(){

	int estado=0;
	char entrada = ' ';
	int final = 0;
	
	do{
	scanf("%c",&entrada);
	
	if(entrada == '/' && estado == 0){
		final = final + 1;
	}
	else{
        printf("Erro: token nao encontrado\n");
	}
    }while(final != 1);
    printf("Aceito\n");
	}
	

 void main(){
     Div();
 }
