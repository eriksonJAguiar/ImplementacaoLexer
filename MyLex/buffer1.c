#include "buffer1.h"

char buffer1[4096];
int first1;
int last1;


void initializa1(){
   first1 = 0;
    last1 = 0;
}
int vazio1(){
  if(first1 == last1)
      return 1;

  return 0;
}
int cheio1(){
    if(last1 >= 4096)
      return 1;

    return 0;
}
void inserir1(char x){
  if(cheio1())
      return;
    buffer1[last1] = x;
    last1++;
}
char remover1(){
    if(vazio1())
        return '\0';
    char aux = buffer1[first1];
    int i = 0;
    while(i < last1){
      buffer1[i] = buffer1[i+1];
        i++;
    }
    last1--;
    return aux;
}
char get1(int i){
    if(i >= last1)
      return '\0';
    return buffer1[i];
}

