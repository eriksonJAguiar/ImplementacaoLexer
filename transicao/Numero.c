#include <stdio.h>
#include <ctype.h>

void Num(){

	int estado=0;
    int estado2=1;
	char entrada = ' ';
	int final = 0;
	
	do{
	scanf("%c",&entrada);
	
	if(entrada == '-' && estado == 0){
		estado = estado +1;
        final = final + 1;
	}
	else if(isdigit(entrada) && (estado == 1 || estado2 == 1)){
		final = final + 1;
        estado = estado + 1;
        estado2 = estado2 + 1;
	}
	else if(isdigit(entrada) && estado2 == 2){
		final = final + 1;
        estado = estado + 1;
	}
	else if(entrada == ' '){
        estado2 = estado2 + 1;
    }
	else{
        printf("Erro: token nao encontrado\n");
        break;
	}
    }while(estado2 != 3);
    printf("Aceito\n");
	}
	

 void main(){
     Num();
 }
