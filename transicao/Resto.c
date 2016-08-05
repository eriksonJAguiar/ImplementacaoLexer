#include <stdio.h>
#include <ctype.h>


void Resto(){

	int estado=0;
    int estado2=1;
    int estado3=0;
	char entrada = ' ';
	int final = 0;
	
	while(estado4 == 0){
	scanf("%c",&entrada);
	
	if(entrada = 'r' && estado == 0){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada = 'e' && estado == 1){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada = 's' && estado == 2){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada = 't' && estado == 3){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada = 'o' && estado == 4){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada = '(' && estado == 5){
        final = final + 1;
	}
	
	else if((isapha(entrada) || isdigit(entrada)) && (estado == 5 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if(entrada == ',') && (estado == 5 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3 + 1;
	}
	else if((isapha(entrada) || isdigit(entrada)) && (estado == 5 && estado3 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if(entrada == ')' && estado == 5){
        estado4 = 1; 
    }
	else{
        printf("Erro: token nao encontrado\n");
        break;
	}
    }
    printf("Aceito\n");
	}
	

 void main(){
     Resto();
 }
