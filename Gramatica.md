#My Grammar

###Ideias Iniciais
    
    *Inserção de dados equivale a <<<
    *Saida de dados equivale a >>>
    *Operadores equivale a + - / * rest(resto da divisao)
    *variáveis equivale a...z e A..Z
    *String equivale a palavra->sua string aqui
    *atribuição de valores as variaveis equivale a x <- 2
    
###Gramática 

    <LinguagemE>::= <cmd> | <cmd><final><LinguagemE>
    <cmd>::= <leia> | <escreva> | <opecao> | <atribuicao> | <opercao> | <declaracao>
    <ler>::= read var   
    <escrever>::= write <texto>
    <texto>::= string | var | <texto> 
    <declaracao>::= <tipo><vars> | <tipo>var<atribuicao>
    <vars>::= var | var sep <vars> | var <atribuicao> sep <vars>
    <tipo>::= inteiro
    <expressao>::= num | <expressao><opercao><expressao> | PA<expressao>PF | var
    <operacao>::= soma | subtracao | divisao | multiplicacao | resto
    <atribuicao>::= var att <val>
    <val>::= num | var | <expr>
  
    
###Tokens
    

| Tokens        |     Padrão                                 | Atributo                                 |
|---------------|--------------------------------------------|------------------------------------------|
|  var          |[a-zA-Z]+"_"?[a-zA-Z0-9]*                   |  ID                                      |
| read          |  "<<<"                                     |                                          |
| write         |  ">>>"                                     |                                          |
| string        |"palavra("[a-zA-Z]+[a-zA-Z ]*")"            |   ponteiro para tabela de símbolos       |
| sep           |       ","                                  |                                          |
| inteiro       |  "inteiro"                                 |                                          |
| soma          |  "+"                                       |                                          |
| divisao       |  "/"                                       |                                          |
| subtração     |  "-"                                       |                                          |
| multiplicação |  "*"                                       |                                          |
| resto         | "resto("[a-zA-Z0-9]+","[a-zA-Z0-9]+")"     |                                          |
| num           | "-"?[0-9][0-9]*                            |                                          |
| att           | "<-"                                       |                                          |
| final         | ";"                                        |                                          |


                                   
    

