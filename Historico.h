#ifndef HISTORICO_H
#define HISTORICO_H

typedef struct {
  int tentativas;
  char nome[30];
} conteudoNo;

typedef struct NoTemp {
  conteudoNo dados;
  struct NoTemp *prox;
} no;

typedef struct {
  no *inicio;
} hist;

/*
* Função responsável por inicializar uma instância da estrutura hist, definida anteriormente.
* Recebe um ponteiro para a estrutura hist que será inicializada.
*/
void iniciaHist(hist *h);

/*
* Função responsável por testar se o usuário acertou o número.
* Recebe um inteiro (o número jogado pela máquina), um ponteiro para valot e a lista.
*/
void verificaNum(hist *h, conteudoNo *valor, int numComputador);

/*
* Função responsável por inserir um valor no histórico.
* Recebe um ponteiro para a estrutura hist e o valor a ser inserido como parâmetros.
*/
void inserirHist(hist *h, conteudoNo valor);

/*
* Função responsável por exibir os recordes armazenados no histórico.
* Recebe uma estrutura hist como parâmetro
*/
void verRecordes(hist h);

#endif