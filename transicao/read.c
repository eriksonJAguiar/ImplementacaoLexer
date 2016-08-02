#include <stdio.h>


void Read(){

	int estado=0;
	char entrada = ' ';
	int final = 0;
	
	while(final != 4){
	scanf("%c",&entrada);
	
	if(entrada == '<' && estado == 0){
		final = final + 1;
        estado = estado + 1;
	}
	else if(entrada == '<' && estado == 1){
		final = final + 1;
        estado = estado + 1;
	}
	else if(entrada == '<' && estado == 2){
		final = final + 2;
        estado = estado + 1;
	}
	else{
        printf("Erro: token nao encontrado\n");
        break;
	}
    }
    printf("Aceito\n");
	}
	

 void main(){
	 Read();
 }
