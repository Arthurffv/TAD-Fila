#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  float preco;
  char nome[100];
  char descricao[200];
  int quantidade;
} TProduto;

typedef struct celula {
  TProduto Item;
  struct celula *prox;
} TCelula;

typedef struct fila {
  TCelula *frente;
  TCelula *tras;
  int tamanho;
} TFila;

void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Enfileirar(TProduto x, TFila *Fila);
void Desenfileirar(TFila *Fila, TProduto *Item);
void LerProduto(TProduto *Produto);
void ImprimirProduto(TProduto produto);
void LiberarFila(TFila *fila);
void Imprimir(TFila *Fila);
TCelula *Pesquisar(TFila *Fila, TProduto *Item);
void Excluir(TFila *Fila, TProduto *Item);
TProduto PesquisarPorNomeFila(TFila Fila, TProduto Item);
int VerificarElementos(TFila *Fila01, TFila *Fila02);

#endif // FILA_H_INCLUDED
