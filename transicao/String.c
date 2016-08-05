#include <stdio.h>
#include <ctype.h>


void String(){

	int estado=0;
    int estado2=1;
    int estado3=0;
<<<<<<< HEAD
    int estado4=0;
=======
		int estado4 = 0;
>>>>>>> c01b3e5c0226620261bbfdb939690c696b467aa1
	char entrada = ' ';
	int final = 0;

	while(estado4 == 0){
	scanf("%c",&entrada);

<<<<<<< HEAD
	if(entrada == 'p' && estado == 0){
=======
	if(entrada = 'p' && estado == 0){
>>>>>>> c01b3e5c0226620261bbfdb939690c696b467aa1
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

<<<<<<< HEAD
	else if((isalpha(entrada) || isdigit(entrada)) && (estado == 7 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if((isalpha(entrada) || isdigit(entrada)) && (estado == 7 && estado3 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if(entrada == ')' && estado == 7){
=======
	else if((isalpha(entrada) || isdigit(entrada)) && (estado == 5 && estado2 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if((isalpha(entrada) || isdigit(entrada)) && (estado == 5 && estado3 == 1)){
		final = final + 1;
        estado3 = estado3;
	}
	else if(entrada == ')' && estado == 5){
>>>>>>> c01b3e5c0226620261bbfdb939690c696b467aa1
        estado4 = 1;
    }
	else{
        printf("Erro: token nao encontrado\n");
        break;
	}
    }
    printf("Aceito\n");
	}
<<<<<<< HEAD

=======
>>>>>>> c01b3e5c0226620261bbfdb939690c696b467aa1


int main(){
     String();
 }
