%{
  #include<stdio.h>
  #include "tokens.h"

  int nline;

%}
%%
"inteiro"                                 return INTEIRO;
[a-zA-Z][a-zA-Z0-9]*"_"?[a-zA-Z0-9]*      return VAR;
"<-"                                      return ATT;
"<<<"                                     return READ;
">>>"                                     return WRITE;
"palavra("[a-zA-Z]+[a-zA-Z]*")"           return STRING;
","                                       return SEP;
"+"                                       return SOMA;
"-"                                       return SUB;
"/"                                       return DIV;
"*"                                       return MULT;
"resto("[a-zA-Z0-9]+","[a-zA-Z0-9]+")"    return RESTO;
"-"?[0-9][0-9]*                           return NUM;
[;]                                       return FINAL;
[\n]                                      nline++;
[ \t]                                         ;
. printf("Caracter Inesperado na linha %d",nline);


%%
int yywrap(void){
	return 1;
}
