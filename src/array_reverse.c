#include <stdio.h>
#include <stdlib.h>

int* vetor_alloc(int n) {
    int* tmp;

    tmp = (int*)malloc(n * sizeof(int));

    if (tmp == NULL) {
        printf("Erro na funcao vetor_alloc\n");

        return NULL;
    }
    return tmp;
}

int main() {
    int i;
    int* a;
    int num;

    printf("Digite o tamanho do array que voce quer inverter:\n");
    scanf("%d", &num);

    a = vetor_alloc(num); /* alloc uma quantidade indefinida no vetor */
    printf("Digite os elementos do array:\n");
    for (i = 0; i < num; i++) {
        // Insere os elementos no vetor percorrendo o index do pointer
        scanf("%d", a + i);
    }
    printf("Array  invertido e:\n");
    // Percorre os elementos no vetor usando o index do pointer - 1 de tras pra frente
    // Comeca do ultimo elemento num - 1 
    for (i = num - 1; i >= 0; i--) printf("%d ", (a[i]));
    return 0;
}