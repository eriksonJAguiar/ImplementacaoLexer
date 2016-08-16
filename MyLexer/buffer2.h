#ifdef bf2_h
#define BF2_H

#include <stdlib.h>
#include <stdio.h>

void initializa2();
void inserir2(char x);
char remover2();
char get2(int i);
int vazio2();
int cheio2();
char lookahead(int foundToken);

extern char buffer2[20];
extern int first2;
extern int last2;
extern int lexemaBegin;
extern int forwd;

#endif
