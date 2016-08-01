#include <stdio.h>
#include "tokens.h"
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include <ctype.h>


int dt1(char lexema[]);
int dt2(char lexema[]);

int main(){

    char lexema[4096];

    char caracter;
    int i = 0;
    do{
      caracter = getchar();
      lexema[i] = caracter;
      i++;
    }while (caracter != '\n');
    lexema[i - 1] = '\0';

    int dt = dt2(lexema);

    if(dt == 2){
      printf("Var\n");
    }
    else{
      printf("ERRO\n");
    }

    return 0;
}
int dt1(char lexema[]){

  if(lexema[0] != 'i')
      return 0;
  if(lexema[1] != 'n')
      return 0;
  if(lexema[2] != 't')
      return 0;
  if(lexema[3] != 'e')
      return 0;
  if(lexema[4] != 'i')
      return 0;
  if(lexema[5] != 'r')
      return 0;
  if(lexema[6] != 'o')
      return 0;

  return INTEIRO;

}
int dt2(char lexema[]){

  if(!isalpha(lexema[0]))
    return 0;
    int i = 1;
  while((isalpha(lexema[i+1]) || isdigit(lexema[i+1])) && lexema[i+1] != '_'){
    if(lexema[i+1] == '\0')
        return VAR;
      i++;
  }
  if(lexema[i+1] != '_')
      return 0;

      while((isalpha(lexema[i+1]) || isdigit(lexema[i+1])) && lexema[i+1] != '_'){
        if(lexema[i+1] == '\0')
            return VAR;
          i++;
      }

  return VAR;
}
