/* Algoritmo convencional para multiplicação de matrizes, feito por Joaquim
  Prieto RA: 10408805 para disciplina de Computação Paralela da turma 05G de
  Ciência da Computação ministrada pelo professor Caleb
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void multiplicaMatriz(int matriz1[SIZE][SIZE], int matriz2[SIZE][SIZE],
                      int resultado[SIZE][SIZE]) {

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }
}


int main(void) {
  
  srand(time(NULL));
  int matriz1[SIZE][SIZE];
  int matriz2[SIZE][SIZE];
  int resultado[SIZE][SIZE];

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matriz1[i][j] = rand() % 10;
      matriz2[i][j] = rand() % 10;
      resultado[i][j] = 0;
    }
  }

  multiplicaMatriz(matriz1, matriz2, resultado);

  fprintf(stdout, "%d\n", resultado[0][0]);

  return 0;
}
