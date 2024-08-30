/* Algoritmo aprimorado para multiplicação de matrizes, feito por Joaquim
  Prieto RA: 10408805 para disciplina de Computação Paralela da turma 05G de
  Ciência da Computação ministrada pelo professor Caleb
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 2000

int matriz1[SIZE][SIZE];
int matriz2[SIZE][SIZE];
int resultado[SIZE][SIZE] = {0};

void multiplicaMatriz(int matriz1[SIZE][SIZE], int matriz2[SIZE][SIZE],
                      int resultado[SIZE][SIZE]) {

  for (int i = 0; i < SIZE; i++) {
    for (int k = 0; k < SIZE; k++) {
      for (int j = 0; j < SIZE; j++) {
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }
}

int main(void) {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matriz1[i][j] = 1;
      matriz2[i][j] = 1;
    }
  }

  multiplicaMatriz(matriz1, matriz2, resultado);

  fprintf(stdout, "%d\n", resultado[SIZE - 1][SIZE - 1]);

  return 0;
}
