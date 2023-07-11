#include "Historico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iniciaHist(hist *h) { h->inicio = NULL; }

void verificaNum(hist *h, conteudoNo *valor, int numComputador) {
  int numJogador;
  printf("\nNúmero: ");
  while (scanf("%d", &numJogador) != 1) {
    printf("Entrada inválida! Digite um número: ");
    while (getchar() != '\n')
      ;
  }
  valor->tentativas = 1;
  while (numJogador != numComputador) {
    if (numJogador < numComputador) {
      printf("\nErrado! Tente um valor mais alto.");
    } else {
      printf("\nErrado! Tente um valor mais baixo.");
    }
    printf("\nNúmero: ");
    while (scanf("%d", &numJogador) != 1) {
      printf("Entrada inválida! Digite um número: ");
      while (getchar() != '\n')
        ;
    }
    valor->tentativas++;
  }
}

void inserirHist(hist *h, conteudoNo valor) {
  no *aux = (no *)malloc(sizeof(no));
  aux->dados = valor;

  if (!h->inicio) {
    aux->prox = NULL;
    h->inicio = aux;
  } else {
    no *atual = h->inicio;
    while (atual->prox &&
           aux->dados.tentativas > atual->prox->dados.tentativas) {
      atual = atual->prox;
    }

    if (!atual->prox && aux->dados.tentativas > atual->dados.tentativas) {
      aux->prox = atual->prox;
      atual->prox = aux;
    } else {
      if (aux->dados.tentativas < atual->dados.tentativas) {
        aux->prox = atual;
        h->inicio = aux;
      } else {
        aux->prox = atual->prox;
        atual->prox = aux;
      }
    }
  }
}

void verRecordes(hist h) {
  no *aux = h.inicio;
  int cont = 1;
  printf("\nPosição | Tentativas | Jogador");

  while (aux && cont <= 3) {
    printf("\n %d - %d - %s", cont, aux->dados.tentativas, aux->dados.nome);
    aux = aux->prox;
    cont++;
  }
}