#include "buffer2.h"

char buffer2[4096];
int first2;
int last2;
int lexemeBegin;
int forwd;

void initializa2(){
   first2 = 0;
    last2 = 0;
    lexemeBegin = 0;
    forwd = 0;
}

int vazio2(){
  if(first2 == last2)
      return 1;

  return 0;
}
int cheio2(){
    if(last2 >= 4096)
      return 1;

    return 0;
}
void inserir2(char x){
  if(cheio2())
      return;
    buffer2[last2] = x;
    last2++;
}
char remover2(){
    if(vazio2())
        return '\0';
    char aux = buffer2[first2];
    int i = 0;
    while(i < last2){
      buffer2[i] = buffer2[i+1];
      i++;
    }
    last2--;
    return aux;
}
char get2(int i){
    if(i >= last2)
      return '\0';
    return buffer2[i];
}
char escandimento(int foundToken){
  if(foundToken == 1){
      lexemeBegin = forwd;
    }
  return buffer2[forwd++];
}

