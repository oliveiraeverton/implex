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
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Encontra o índice do menor elemento no restante do array não ordenado
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Troca o elemento atual com o menor elemento encontrado
        swap(&arr[i], &arr[minIndex]);
    }
}

void mergeSort(){

}

void heapSort(){

}

void quickSort(){

}

void countingSort(){

}

//Função para imprimir o vetor
void imprimeVetor(int arr[], int n){


    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n\n");

}

//Função para criar os números aleatórios
void CriaVetorComElementosRandomicos(int **vetorParaOrdenacao, int **vetorOriginal,int *n){
    // Inicializar o gerador de números randômicos com um valor de semente
    srand(time(NULL));
    //*n = 500;
    // Alocar memória para o vetor
    *vetorParaOrdenacao = (int *)malloc(*n * sizeof(int));
    *vetorOriginal = (int *)malloc(*n * sizeof(int));
    
    // Preencher o vetor com elementos randômicos
    int *k = *vetorOriginal;
    int *pointF = *vetorParaOrdenacao+*n;
    for (int *i = *vetorParaOrdenacao; i < pointF; i++) {

        *i = rand() % 1000; // Gera um número randômico entre 0 e 99
        *k = *i;
        k++;
    }
    

}


void CopiarElementosDoVetor(int *vetorOriginal,int **vetorCopia ,int tamanhoDoVetor){
    // vetorCopia é o vetor que vai receber os elementos originais do vetorOriginal
    for(int *i = *vetorCopia; i < *vetorCopia + tamanhoDoVetor; i++){
        *i = *vetorOriginal++;
    
    }
}

int main(){

    //******************************************   DECLARAÇÃO DE VARIÁVEIS ******************************************//
    clock_t start_time, end_time;   // Variável para iniciar e terminar o cronômetro
    double elapsed_time;            // Variável que guardará a diferença entre inicío e fim do cronômetro
    double calculoDeTempo = 0;      // variável para calcular a média do tempo
    int tamanhoDoVetor=5;         // Variável que irá controlar o tamanho do vetor
    int *vetor;                     //Vetor utilizado para a ordenação dentro das funções de ordenação
    int *vetorOriginal;             // Vetor que terá as posições originais de cada elemento
    int inc = 1000;    // Tamanho Inicial
    int fim = 10000000;    // Tamanho Final
    int stp = 1000000;    // Intervalo entre os Tamanhos
    int rpt = fim/stp;    // Número de repetições a serem realizadas
    //***************************************************************************************************************//

      
   
    //******************************************   DEBBUGUER ******************************************//
    //imprimeVetor(vetor, tamanhoDoVetor);
    //imprimeVetor(vetorOriginal, tamanhoDoVetor);
    //CopiarElementosDoVetor(vetor, &vetorOriginal, tamanhoDoVetor);
    //******************************************   DEBBUGUER ******************************************//
    
    printf("[[RANDOM]]\n");
    printf("n\tSelection\tInsertion\tMerge\tHeap\tQuick\tCounting\n");
    for(int w = 0; w < rpt; w++ ){
        printf("%d\t", inc);
        // Alimenta o vetor com números Randômicos
        CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &inc);
        inc += stp; // Incrementa a quantidade de elementos que será para a próxima iteração


        //**************************** INSERTION-SORT *************************************************//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, tamanhoDoVetor);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, tamanhoDoVetor);
            

        }
        printf("%.6f\t", calculoDeTempo/10);

        //**************************** SELECTION-SORT *************************************************//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, tamanhoDoVetor);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, tamanhoDoVetor);
            

        }
        printf("%.6f\t\n", calculoDeTempo/10);
        
       //**************************** MERGESORT *************************************************//
        /*for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, tamanhoDoVetor);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, tamanhoDoVetor);
            

        }
        printf("%.6f segundos\n", calculoDeTempo/10);
        */
       //****************************  HEAPSORT *************************************************//
        /*for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, tamanhoDoVetor);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, tamanhoDoVetor);
            

        }
        printf("%.6f segundos\n", calculoDeTempo/10);
        */
       //****************************  QUICKSORT *************************************************//
        /*for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, tamanhoDoVetor);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, tamanhoDoVetor);
            

        }
        printf("%.6f segundos\n", calculoDeTempo/10);
        */
       //****************************  COUNTINGSORT *************************************************//
       /*for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, tamanhoDoVetor);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, tamanhoDoVetor);
            

        }
        printf("%.6f segundos\n", calculoDeTempo/10);
        */



        free(vetor);
        free(vetorOriginal);
    }
    
    return 0;
}