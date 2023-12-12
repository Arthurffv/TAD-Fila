#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"

void FFVazia(TFila *Fila) {
  Fila->frente = (TCelula *)malloc(sizeof(TCelula));
  Fila->tras = Fila->frente;
  Fila->frente->prox = NULL;
  Fila->tamanho = 0;
}

int Vazia(TFila Fila) { return (Fila.frente == Fila.tras); }

void Enfileirar(TProduto x, TFila *Fila) {
  Fila->tras->prox = (TCelula *)malloc(sizeof(TCelula));
  Fila->tras = Fila->tras->prox;
  Fila->tras->Item = x;
  Fila->tras->prox = NULL;
  Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item) {
  TCelula *aux;
  if (!Vazia(*Fila)) {
    aux = Fila->frente->prox;
    Fila->frente->prox = aux->prox;
    *Item = aux->Item;
    free(aux);
    if (Fila->frente->prox == NULL)
      Fila->tras = Fila->frente;
    Fila->tamanho--;
  }
}

void LerProduto(TProduto *Produto) {
  printf("Digite o codigo do produto:\n");
  fflush(stdin);
  getchar();
  scanf("%d", &Produto->codigo);
  printf("\nDigite o valor do produto:\n");
  fflush(stdin);
  getchar();
  scanf("%f", &Produto->preco);
  printf("\nDigite o nome do produto, ate 100 caracteres:\n");
  fflush(stdin);
  getchar();
  fgets(Produto->nome, 100, stdin);
  printf("\nDigite a descricao do produto, ate 200 caracteres:\n");
  fflush(stdin);
  getchar();
  fgets(Produto->descricao, sizeof(Produto->descricao), stdin);
  printf("\nDigite a quantidade de produtos:\n");
  fflush(stdin);
  scanf("%d", &Produto->quantidade);
}

void ImprimirProduto(TProduto produto) {
  printf("\nO codigo do produto solicitado: %d\n", produto.codigo);
  printf("O valor do produto solicitado, R$ %.2f\n", produto.preco);
  printf("O nome do produto solicitado e %s\n", produto.nome);
  printf("Descricao do produto: %s\n", produto.descricao);
  printf("Temos %d unidades desse produto\n", produto.quantidade);
}

void LiberarFila(TFila *fila) {
  TProduto *Item;
  TCelula *aux;
  while (!Vazia(*fila)) {
    if (!Vazia(*fila)) {
      aux = fila->frente->prox;
      fila->frente->prox = aux->prox;
      *Item = aux->Item;
      free(aux);
      if (fila->frente->prox == NULL) {
        fila->tras = fila->frente;
      }
      (fila->tamanho)--;
    }
  }
  free(fila->frente);
}

void Imprimir(TFila *Fila) {
  TFila Aux;
  FFVazia(&Aux);
  TProduto ProdAux;
  while (Fila->frente->prox != NULL) {
    Desenfileirar(Fila, &ProdAux);
    ImprimirProduto(ProdAux);
    Enfileirar(ProdAux, &Aux);
  }
  while (Aux.frente->prox != NULL) {
    Desenfileirar(&Aux, &ProdAux);
    Enfileirar(ProdAux, Fila);
  }
  free(Aux.frente);
}

TCelula *Pesquisar(TFila *Fila, TProduto *Item) {
    TCelula *CelAux;
    CelAux = Fila->frente->prox;
    TFila Aux;
    FFVazia(&Aux);
    TProduto ProdAux;
    while (CelAux != NULL) {
      Desenfileirar(Fila, &ProdAux);
      if (CelAux->Item.codigo == Item->codigo) {
        free(Aux.frente);
        return CelAux;
      }
      Enfileirar(ProdAux, &Aux);
    }
    while (Aux.frente->prox != NULL) {
      Desenfileirar(&Aux, &ProdAux);
      Enfileirar(ProdAux, Fila);
    }
    free(Aux.frente);
  return NULL;
  }

void Excluir(TFila *Fila, TProduto *Item) {
  TCelula *Aux;
  Aux = Fila->frente->prox;
  for (int i = 1; i <= Fila->tamanho; i++) {
    if (!Vazia(*Fila)) {
      Aux = Fila->frente->prox;
      Fila->frente->prox = Aux->prox;
      *Item = Aux->Item;
      free(Aux);
      if (Fila->frente->prox == NULL)
        Fila->tras = Fila->frente;
      Fila->tamanho--;
    }
    if (Fila->frente->Item.codigo == Item->codigo) {
      free(Item);
    } else {
      Enfileirar(Aux->Item, Fila);
      Aux = Aux->prox;
    }
  }
}

TProduto PesquisarPorNomeFila(TFila Fila, TProduto Item) {
  TCelula *Aux;
  Aux = Fila.frente->prox;
  for (int i = 1; i <= Fila.tamanho; i++) {
    Desenfileirar(&Fila, &Aux->Item);
    if (strcmp(Fila.frente->Item.nome, Item.nome) == -10) {
      return Aux->Item;
    }
    Enfileirar(Aux->Item, &Fila);
    Aux = Aux->prox;
  }
  Aux->Item.codigo = -1;
  return Aux->Item;
}
int VerificarElementos(TFila *Fila01, TFila *Fila02) {
  TCelula *Aux;
  Aux = Fila01->frente->prox;
  int cont = 0;
  for (int i = 1; i <= Fila01->tamanho; i++) {
    Desenfileirar(Fila01, &Aux->Item);
    if (Pesquisar(Fila02, &Aux->Item) != NULL) {
      cont++;
    } else {
      Enfileirar(Aux->Item, Fila01);
      Aux = Aux->prox;
    }
  }
  if (cont == Fila02->tamanho)
    return 1;
  else {
    return 0;
  }
}
