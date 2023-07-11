#include "Historico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
  FILE *arq;
  hist h;
  conteudoNo valor;
  int op, numComputador, numJogador, i;

  iniciaHist(&h);
  arq = fopen("historico.txt", "r");
  if (arq == NULL) {
    arq = fopen("historico.txt", "w");
  }

  while (fscanf(arq, "%d %s", &valor.tentativas, valor.nome) != EOF) {
  inserirHist(&h, valor);
  }
  fclose(arq);

  srand(time(NULL));

  printf("\n\t+---------------------+\n\t| 1 | Novo Jogo       "
         "|\n\t+---------------------+\n\t| 2 | Ver Recordes    "
         "|\n\t+---------------------+\n\t| 3 | Limpar Recordes "
         "|\n\t+---------------------+\n\t| 4 | Sair            "
         "|\n\t+---------------------+\n\n\tResposta: ");
  while (scanf("%d", &op) != 1) {
    printf("Entrada inválida! Digite um número: ");
    while (getchar() != '\n')
      ;
  }

  while (op != 4) {
    if (op > 4 || op < 1) {
      printf("\nOpção Inválida!\n");
    }
    switch (op) {
    case 1:
      getchar();
      printf("\nNome: ");
      fgets(valor.nome, sizeof(valor.nome), stdin);
      size_t len = strlen(valor.nome);
      if (len > 0 && valor.nome[len - 1] == '\n') {
        valor.nome[len - 1] = '\0';
      }
      numComputador = (rand() % 100) + 1;
      verificaNum(&h, &valor, numComputador);
      
      printf("\nParabéns! Você acertou depois de %d tentativas.",
             valor.tentativas);

      inserirHist(&h, valor);

      arq = fopen("historico.txt", "w");
      if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
      }
      no *aux;
      for (aux = h.inicio; aux != NULL; aux = aux->prox) {
        fprintf(arq, "%d %s\n", aux->dados.tentativas, aux->dados.nome);
      }
      fclose(arq);
      break;
    case 2:
      if (h.inicio) {
        verRecordes(h);
      } else {
        printf("\nHistórico de Recordes Vazio.\n");
      }
      break;
    case 3:
      iniciaHist(&h);
      arq = fopen("historico.txt", "w");
      if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
      } else {
        fclose(arq);
        printf("\nRecordes Limpos.\n");
      }
      break;
    }

    printf("\n\t+---------------------+\n\t| 1 | Novo Jogo       "
           "|\n\t+---------------------+\n\t| 2 | Ver Recordes    "
           "|\n\t+---------------------+\n\t| 3 | Limpar Recordes "
           "|\n\t+---------------------+\n\t| 4 | Sair            "
           "|\n\t+---------------------+\n\n\tResposta: ");
    while (scanf("%d", &op) != 1) {
      printf("Entrada inválida! Digite um número: ");
      while (getchar() != '\n')
        ;
    }
  }

  return 0;
}
