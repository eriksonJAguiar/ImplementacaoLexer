#include "buffer2.h"

char buffer2[20];
int first2;
int last2;
int lexemeBegin;
int forwd;
int iniciou = 0;
int tamBf2;

void initializaLista2(){
   first2 = 0;
    last2 = 0;
    tamBf2 = 0;
}
void initializa2(){
    lexemeBegin = 0;
    forwd = 0;
}
int vazio2(){
  if(first2 == last2)
      return 1;

  return 0;
}
int cheio2(){
    if(last2 >= 20)
      return 1;

    return 0;
}
void inserir2(char x){
  if(cheio2())
      return;
  //int i;
  /*for(i=last2-1;i>=first2;i--){
    buffer2[i+1] = buffer2[i];
  }*/
  	buffer2[last2] = x;
    last2++;
    tamBf2++;
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
    tamBf2--;
    return aux;
}
char get2(int i){
    if(i >= last2)
      return '\0';
    return buffer2[i];
}
char escandimento(int foundToken){
  char aux;
	if(foundToken == 1){
	  forwd--;
	  limpaToken();
	  lexemeBegin = forwd;
	  aux = buffer2[forwd];
	  forwd++;
  }
  else{
	  aux = buffer2[forwd];
	  forwd++;
  }

  return aux;
}
void limpaToken(){
	int i;
	for(i=lexemeBegin;i<forwd;i++){
		buffer2[i] = '\0';
	}
}
void organizaBuffer(){
	int ultimo = last2;
	int i=0;
	while(i < ultimo && buffer2[0] == '\0'){
		if(buffer2[0] == '\0'){
			removerQualquer(0);
		}else if(buffer2[i] == '\0'){
			removerQualquer(i);
		}
		i++;
	}
}
void removerQualquer(int pos){
	if(pos == 0){
		remover2();
		return;
	}
	else if(pos == last2){
		buffer2[pos] = '\0';
		tamBf2--;
		last2--;
		return;
	}

	int i;

	for(i=pos;i<last2;i++){
		buffer2[i] = buffer2[i+1];
	}
	tamBf2--;
	last2--;

}

