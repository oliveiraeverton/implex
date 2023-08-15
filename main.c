#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}


void imprimeVetor(int arr[], int n){


    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n\n");

}

void CriaVetoComElementosRandomicos(int **arr, int *n){
    // Inicializar o gerador de números randômicos com um valor de semente
    srand(time(NULL));
    *n = 5000;
    // Alocar memória para o vetor
    *arr = (int *)malloc(*n * sizeof(int));

    // Variável *vetor guarda a posição inicial do vetor alocado
    int *vetor = *arr;
    // Preencher o vetor com elementos randômicos
    for (int i = 0; i < *n; i++) {
        
        **arr = rand() % 1000; // Gera um número randômico entre 0 e 99
        (*arr)++;
    }
    // Recupera a posição do vetor inicial
    *arr = vetor;
}

void CriaVetoComElementosRandomicos2(int **arr, int *n){
    // Inicializar o gerador de números randômicos com um valor de semente
    srand(time(NULL));
    *n = 500;
    // Alocar memória para o vetor
    *arr = (int *)malloc(*n * sizeof(int));

    // Variável *vetor guarda a posição inicial do vetor alocado
    //int *vetor = *arr;
    // Preencher o vetor com elementos randômicos
    int *pointF = *arr+*n;
    for (int *i = *arr; i < pointF; i++) {

        *i = rand() % 1000; // Gera um número randômico entre 0 e 99
        
    }

}



void CopiarElementosDoVetor(int *vetor,int *vetorC ,int tamanhoDoVetor){
    for(int i = 0; i < tamanhoDoVetor; i++){
        vetorC[i] = vetor[i];
    }
}

int main(){

    clock_t start_time, end_time;
    double elapsed_time;
    double calculoDeTempo = 0;
    int tamanhoDoVetor=0;
    

    int *vetor;
    //printf("Quantidade de elementos: %d \n", tamanhoDoVetor);
    CriaVetoComElementosRandomicos2(&vetor, &tamanhoDoVetor);
    //printf("Quantidade de elementos: %d \n", tamanhoDoVetor);

    int vetorOriginal[tamanhoDoVetor];
    CopiarElementosDoVetor(vetor, vetorOriginal, tamanhoDoVetor);

    for(int k = 0; k < 10; k++){
        // Iniciar a contagem de tempo
        start_time = clock();
        insertionSort(vetor, tamanhoDoVetor);
        // Parar a contagem de tempo
        end_time = clock();
        printf("Tempo decorrido: %.6f segundos\n", elapsed_time);
        // Calcular o tempo decorrido em segundos
        elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        calculoDeTempo += elapsed_time;
        //imprimeVetor(vetor, tamanhoDoVetor);
        //imprimeVetor(vetorOriginal, tamanhoDoVetor);
        CopiarElementosDoVetor(vetorOriginal, vetor, tamanhoDoVetor);
        //imprimeVetor(vetor, tamanhoDoVetor);
        //imprimeVetor(vetorOriginal, tamanhoDoVetor);
    }
    printf("AQUI\n");
    printf("Tempo decorrido: %.6f segundos\n", calculoDeTempo/10);

    //imprimeVetor(vetor, tamanhoDoVetor);
    //imprimeVetor(vetorOriginal, tamanhoDoVetor);

    free(vetor);

    // TO-DO Em um laço
    // TO-DO : COPIAR VETOR
    // TO-DO : CHAMAR A FUNÇÃO
    // TO-DO : RESETAR O VETOR

    return 0;
}