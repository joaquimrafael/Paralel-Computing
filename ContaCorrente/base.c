/* Joaquim Rafael Mariano Prieto Pereira - 10408805
  Computação Paralela - 05G - CC
  Conta Corrente - base
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2147483000L

double saldo = 1000.00;

void depositos() {
    for(long int i = 0; i < MAX_SIZE; i++){
        saldo += 5.0;
    }
}

void saques() {
    for(long int i = 0; i < MAX_SIZE; i++){
        saldo -= 2.0;
    }
}

int main()
{

    depositos();
    saques();

    printf("%.2lf", saldo);
    return 0;
}
