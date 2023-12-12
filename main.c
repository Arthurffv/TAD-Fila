#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

int main() {
  TFila Fila01;
  TFila Fila02;

  FFVazia(&Fila01);
  FFVazia(&Fila02);
  Vazia(Fila01);
  Vazia(Fila02);

  MENU(&Fila01, &Fila02);

  LiberarFila(&Fila01);
  LiberarFila(&Fila02);

  return 0;
}