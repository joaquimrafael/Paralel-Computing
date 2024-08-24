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
  // loop 0^3 que se movimenta entra as matrizes para multiplicar e somar os
  // resultados
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        resultado[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }
}

// *adicionar avaliações de tempo e de memória, além de alterar para desempenho aprimorado*

int main(void) {
  // usei valores aleatorios para cada célula da matriz e uma constante para os
  // tamanhos
  srand(time(NULL));
  int matriz1[SIZE][SIZE];
  int matriz2[SIZE][SIZE];
  int resultado[SIZE][SIZE];

  printf("<Programa para multiplicação de matrizes>\n");

  // inicialização dos valores das matrizes
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      matriz1[i][j] = rand() % 10;
      matriz2[i][j] = rand() % 10;
      resultado[i][j] = 0;
    }
  }

  printf("\nMatriz 1: \n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf(" %d ", matriz1[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz 2: \n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf(" %d ", matriz2[i][j]);
    }
    printf("\n");
  }

  multiplicaMatriz(matriz1, matriz2, resultado);

  printf("\nMatriz resultante: \n");
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf(" %d ", resultado[i][j]);
    }
    printf("\n");
  }

  return 0;
}