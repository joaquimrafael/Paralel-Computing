/* Joaquim Rafael Mariano Prieto Pereira - 10408805
  Computação Paralela - 05G - CC
  Conta Corrente - fase2
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2147483000L

double saldo = 1000.00;

pthread_mutex_t mutex;

void *depositos(void *arg) {
  for (long int i = 0; i < MAX_SIZE; i++) {
    pthread_mutex_lock(&mutex);
    saldo += 5.0;
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

void *saques(void *arg) {
  for (long int i = 0; i < MAX_SIZE; i++) {
    pthread_mutex_lock(&mutex);
    saldo -= 2.0;
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}

int main() {
  pthread_t threadSaques, threadDepositos;

  pthread_mutex_init(&mutex, NULL);

  if (pthread_create(&threadDepositos, NULL, depositos, NULL) != 0) {
    perror("pthread_create() error");
    exit(1);
  }

  if (pthread_create(&threadSaques, NULL, saques, NULL) != 0) {
    perror("pthread_create() error");
    exit(1);
  }

  if (pthread_join(threadDepositos, NULL) != 0) {
    perror("pthread_create() error");
    exit(3);
  }

  if (pthread_join(threadSaques, NULL) != 0) {
    perror("pthread_create() error");
    exit(3);
  }

  pthread_mutex_destroy(&mutex);

  printf("%.2lf", saldo);
  return 0;
}
