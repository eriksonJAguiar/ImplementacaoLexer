#include <stdio.h>


void Sub(){

	int estado=0;
	char entrada = ' ';
	int final = 0;
	
	do{
	scanf("%c",&entrada);
	
	if(entrada == '-' && estado == 0){
		final = final + 1;
	}
	else{
        printf("Erro: token nao encontrado");
	}
    }while(final != 1);
    printf("Aceito");
	}
	

 void main(){
     Sub();
 }
