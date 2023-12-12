#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU() {
  system("cls");
  printf(
      "\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
  printf("\n\n\t1. ENFILEIRAR");
  printf("  \n\t2. PESQUISAR");
  printf("  \n\t3. DESENFILEIRAR");
  printf("  \n\t4. IMPRIMIR");
  printf("  \n\t5. EXCLUIR");
  printf("  \n\t6. LIBERAR FILA");
  printf("  \n\t7. PESQUISAR POR NOME");
  printf("  \n\t8. VERIFICAR ELEMENTOS DA FILA IGUAIS");
  printf("  \n\t9. SAIR");
}

void MENU(TFila *Fila01, TFila *Fila02) {
  TProduto produto;
  int opcao = 0;
  int ret;
  do {
    MSG_MENU();
    printf("\n\nDigite uma opcao: ");
    fflush(stdin);
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      LerProduto(&produto);
      Enfileirar(produto, Fila01);
      break;
    case 2:
      printf("Digite o codigo do produto que deseja pesquisar: ");
      scanf("%d", &produto.codigo);
      Pesquisar(Fila01, &produto);
      break;
    case 3:
      Desenfileirar(Fila01, &produto);
      break;
    case 4:
      printf("Fila 01: \n");
      Imprimir(Fila01);
      break;
    case 5:
      printf("Digite o codigo do produto que deseja excluir: ");
      scanf("%d", &produto.codigo);
      Excluir(Fila01, &produto);
      break;
    case 6:
      LiberarFila(Fila01);
      break;
    case 7:
      printf("Digite o nome do produto que deseja pesquisar: \n");
      fflush(stdin);
      getchar();
      fgets(produto.nome, sizeof(produto.nome), stdin);
      PesquisarPorNomeFila(*Fila01, produto);
      break;
    case 8:
      ret = VerificarElementos(Fila01, Fila02);
      if (ret == 1) {
        printf("AS FILAS RETEM O MESMO CONTEUDO");
      } else {
        printf("AS FILAS NAO RETEM O MESMO CONTEUDO");
      }
      break;
    case 9:
      system("cls");
      printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
      system("PAUSE");
      break;
    default:
      system("cls");
      printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
      system("PAUSE");
    }
  } while (opcao != 9);
}
