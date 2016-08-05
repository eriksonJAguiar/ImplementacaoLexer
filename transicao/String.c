#include <stdio.h>
#include <ctype.h>


void String(){

	int estado=0;
    int estado2=1;
    int estado3=0;
    int estado4=0;
	char entrada = ' ';
	int final = 0;

	while(estado4 == 0){
	scanf("%c",&entrada);

	if(entrada == 'p' && estado == 0){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == 'a' && estado == 1){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == 'l' && estado == 2){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == 'a' && estado == 3){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == 'v' && estado == 4){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == 'r' && estado == 5){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == 'a' && estado == 6){
		estado = estado +1;
        final = final + 1;
	}
	else if(entrada == '(' && estado == 7){
        final = final + 1;
	}

	else if((isalpha(entrada) || isdigit(entrada)) && (estado == 7 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if((isalpha(entrada) || isdigit(entrada)) && (estado == 7 && estado3 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if(entrada == ')' && estado == 7){
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
     String();
 }
