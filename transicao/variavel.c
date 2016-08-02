#include <stdio.h>
#include <ctype.h>


void variavel(){

	int estado=0;
    int estado2=1;
    int estado3=0;
    int estado4=0;
	char entrada = ' ';
	int final = 0;
	
	while(estado4 == 0){
	scanf("%c",&entrada);
	
	if(isalpha(entrada) && estado == 0){
		estado = estado +1;
        final = final + 1;
	}
	else if((isapha(entrada) || isdigit(entrada)) && (estado == 1 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if(entrada == '_') && (estado == 1 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3 + 1;
	}
	else if((isapha(entrada) || isdigit(entrada)) && (estado == 1 && estado2 == 1 && estado3 == 1)){
		final = final + 1;
	}
	else if(entrada == ' ' && estado == 1){
        estado4 = 1; 
    }
	else{
        printf("Erro: token nao encontrado");
        break;
	}
    }
    printf("Aceito");
	}
	

 void main(){
     variavel();
 }
