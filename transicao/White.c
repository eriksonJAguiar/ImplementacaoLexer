#include <stdio.h>


void White(){

	int estado=0;
	char entrada = ' ';
	int final = 0;
	
	do{
	scanf("%c",&entrada);
	
	if(entrada == '>' && estado == 0){
		final = final + 1;
        estado = estado + 1;
	}
	else if(entrada == '>' && estado == 1){
		final = final + 1;
        estado = estado + 1;
	}
	else if(entrada == '>' && estado == 2){
		final = final + 2;
        estado = estado + 1;
	}
	else{
        printf("Erro: token nao encontrado");
	}
    }while(final != 4);
    printf("Aceito");
	}
	

 void main(){
     White();
 }
