#include "lista.h"
#include <stdlib.h>


typedef struct celula celula;

struct celula
{
    char item;
    celula *prox;
    int lexemebegin;
    int forward;
};

celula *nova(char x)
{
    celula *p = (celula *)malloc(sizeof(celula));
    if(p==NULL)
    {
        exit(1);
    }
    p->item=x;
    p->prox=NULL;
    p->lexemebegin = 0;
    p->forward = 0;
    return p;
}
void insere(char x, celula *p)
{
    celula *q = nova(x);
    q->prox=p->prox;
    p->prox=q;
    tam++;
}

char remove_celula(celula *p)
{
    celula *q = p->prox;
		char aux = q->item;
    p->prox = q->prox;
    free(q);
    tam--;

		return aux;
}

void insere_fim(celula *ini, char x)
{
    celula *u=ini->prox;
    if(u==NULL)
    {
        insere(x,ini);
        return;
    }
    while(u->prox != NULL)
    {
        u=u->prox;
    }
    insere(x,u);
}
char remove_inicio(celula *ini)
{
		char aux;

		if(ini->prox!=NULL)
    {
			aux = remove_celula(ini);
    }

		return aux;
}
char get(celula *ini,int pos){
		celula *l = ini->prox;
		int cont = 0;
		while(cont < pos){
			l = l->prox;
			cont++;
		}

		return l->item;
}

char escandimento(celula *ini,int foundToken){
  celula *l = ini->prox;
  if(foundToken == 1)
      ini->lexemebegin = ini->forward;
  int cont = 0;
  while(cont < ini->forward+1){
        int i = 0;
        while(i < ini->lexemebegin){
            l = l->prox;
        }
        if(i >= ini->lexemebegin)
            l = l->prox;
          cont++;
      }
      ini->forward++;
      return l->item;
}


