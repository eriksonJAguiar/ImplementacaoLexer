#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>

typedef struct dt{
    int ponteiro = 0;
    int fdt(char a);
}dt;

struct dt dt_att;
struct dt dt_div;
struct dt dt_fim;
struct dt dt_mult;
struct dt dt_num;
struct dt dt_read;
struct dt dt_rest;
struct dt dt_sep;
struct dt dt_soma;
struct dt dt_string;
struct dt dt_sub;
struct dt dt_var;
struct dt dt_write;

dt_att.ponteiro=0;
dt_div.ponteiro=0;
dt_fim.ponteiro=0;
dt_mult.ponteiro=0;
dt_num.ponteiro=0;
dt_read.ponteiro=0;
dt_rest.ponteiro=0;
dt_sep.ponteiro=0;
dt_soma.ponteiro=0;
dt_string.ponteiro=0;
dt_sub.ponteiro=0;
dt_var.ponteiro=0;
dt_write.ponteiro=0;

int *dt_att.fdt(char a){

    if(a == '<' && ponteiro == 0){
        ponteiro++;
        return;
    }
    if(a == '-' && ponteiro == 1){
        ponteiro++;
        return;
    }
    if(ponteiro == 2){
        return 1;
        pthread_join(att,NULL);

    }

    pthread_join(att,NULL);

    return 0;
    }

int *dt_div.fdt(char a){

	if(entrada == '/' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(ponteiro == 1){
        pthread_join(div,NULL);
        return 2;
	}

    pthread_join(div,NULL);

	return 0;

}

int *dt_fim.fdt(char a){

	if(entrada == ';' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(ponteiro == 1){
        pthread_join(fim,,NULL);

        return 3;
	}
        pthread_join(fim,NULL);

	return 0;
}

int *dt_mult.fdt(char a){

    if(entrada == '*' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(ponteiro == 1){
        return 4;
        pthread_join(mult,NULL);

	}
    pthread_join(mult,NULL);

	return 0;

}

int *dt_num.fdt(char a){

    if(a == '-' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(isdigit(a) && ponteiro == 1){
		ponteiro++;
		return;
	}
	if(isdigit(a) && (ponteiro == 0 || ponteiro == 1)){
		ponteiro = 2;
		return;
	}
	if(a == ' ' && ponteiro == 2 ){
        pthread_join(num,NULL);

        return 5;   // retorna um token de numero
    }
    pthread_join(num,NULL);

	return 0;
}

int *dt_read.fdt(char a){

    if(a == '<' && ponteiro == 0){
		ponteiro++;
		return;
	}
	else if(a == '<' && ponteiro == 1){
		ponteiro++;
		return;
	}
	else if(a == '<' && ponteiro == 2){
        pthread_join(read,NULL);

		return 6;
	}
    pthread_join(read,NULL);

   return 0;
}

int *dt_rest.fdt(char a){

    if(a = 'r' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(a = 'e' && ponteiro == 1){
		ponteiro++;
		return;
	}
	if(a = 's' && ponteiro == 2){
		ponteiro++;
        return;
	}
	if(a = 't' && ponteiro == 3){
		ponteiro++;
		return;
	}
	if(a = 'o' && ponteiro == 4){
		ponteiro++;
		return;
	}
	if(a = '(' && ponteiro == 5){
        ponteiro=5;
        return;
	}

    if(isdigit(a) && ponteiro == 5){
		return;
	}
	if(a == ',' && ponteiro == 5){
		ponteiro++;
		return;
	}
	if(isdigit(a) && ponteiro == 6){
        ponteiro = 7
        return;
	}
	if(a == ')' && ponteiro == 7){
    pthread_join(rest,NULL);

        return 7;
    }
    pthread_join(rest,NULL);

	return 0;
}

int *dt_sep.fdt(char a){

    if(entrada == ',' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(ponteiro == 1){
    pthread_join(sep,NULL);

    return 8;
	}
    pthread_join(sep,NULL);

	return 0;

}

int *dt_soma.fdt(char a){

    if(entrada == '+' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(ponteiro == 1){
    pthread_join(soma,NULL);

        return 9;
	}
    pthread_join(soma,NULL);

	return 0;

}

int *dt_string.fdt(char a){

    if(a = 'p' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(a = 'a' && ponteiro == 1){
		ponteiro++;
		return;
	}
	if(a = 'l' && ponteiro == 2){
		ponteiro++;
        return;
	}
	if(a = 'a' && ponteiro == 3){
		ponteiro++;
		return;
	}
	if(a = 'v' && ponteiro == 4){
		ponteiro++;
		return;
	}
	if(a = 'r' && ponteiro == 5){
        ponteiro++;
        return;
	}

	if(a = 'a' && ponteiro == 6){
        ponteiro++;
        return;
	}

	if(a = '(' && ponteiro == 7){
        ponteiro=8;
        return;
	}

    if((isdigit(a) || isalpha(a) || isspace(a) || iscntrl(a)) && ponteiro == 8){
		ponteiro=9;
		return;
	}

	if(a == ')' && ponteiro == 9){
        pthread_join(string,NULL);

        return 10;
    }
    pthread_join(string,NULL);

    return 0;
}

int *dt_sub.fdt(char a){

    if(entrada == '-' && ponteiro == 0){
		ponteiro++;
		return;
	}
	if(ponteiro == 1){
        pthread_join(sub,NULL);

        return 11;
	}
    pthread_join(sub,NULL);

	return 0;

}

int *dt_var.fdt(char a){

    if(isalpha(a) && ponteiro == 0){
        ponteiro++;
        return;
	}
	if((isalpha(a) || isdigit(a) || a == '_') && ponteiro == 1){
        ponteiro=2;
        return;
	}
	if(a == ' ' ponteiro == 2){
        pthread_join(var,NULL);

        return 12;
	}
    pthread_join(var,NULL);

    return 0;
}

int *dt_write.fdt(char a){

    if(a == '>' && ponteiro == 0){
		ponteiro++;
		return;
	}
	else if(a == '>' && ponteiro == 1){
		ponteiro++;
		return;
	}
	else if(a == '>' && ponteiro == 2){
    pthread_join(white,NULL);
    return 13;
	}
    pthread_join(white,NULL);

    return 0;
}


int main()
{
    pthread_t att;
    pthread_t div;
    pthread_t fim;
    pthread_t mult;
    pthread_t num;
    pthread_t read;
    pthread_t rest;
    pthread_t sep;
    pthread_t soma;
    pthread_t string;
    pthread_t subtr;
    pthread_t var;
    pthread_t white;

    pthread_create(&att,NULL,dt_att.fdt(a),char a);
    pthread_create(&div,NULL,dt_div.fdt(a),char a);
    pthread_create(&fim,NULL,dt_fim.fdt(a),char a);
    pthread_create(&mult,NULL,dt_mult.fdt(a),char a);
    pthread_create(&num,NULL,dt_num.fdt(a),char a);
    pthread_create(&read,NULL,dt_read.fdt(a),char a);
    pthread_create(&rest,NULL,dt_rest.fdt(a),char a);
    pthread_create(&sep,NULL,dt_sep.fdt(a),char a);
    pthread_create(&soma,NULL,dt_soma.fdt(a),char a);
    pthread_create(&string,NULL,dt_string.fdt(a),char a);
    pthread_create(&subtr,NULL,dt_sub.fdt(a),char a);
    pthread_create(&var,NULL,dt_var.fdt(a),char a);
    pthread_create(&white,NULL,dt_write.fdt(a),char a);

    return 0;
}
