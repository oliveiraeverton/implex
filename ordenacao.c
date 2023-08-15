#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include"ordenacao.h"

int main(){

    //***************************************ABERTURA DE ARQUIVO****************************************************//
    FILE *arq= fopen("saidas.txt", "w");
    if(arq == NULL){
        printf("Erro na criacao do documento TXT");
        return 1;
    }
    //***************************************************************************************************************//


    //******************************************   DECLARAÇÃO DE VARIÁVEIS ******************************************//
    clock_t start_time, end_time;   // Variável para iniciar e terminar o cronômetro
    double elapsed_time;            // Variável que guardará a diferença entre inicío e fim do cronômetro
    double calculoDeTempo = 0;      // variável para calcular a média do tempo
    int *vetor;                     //Vetor utilizado para a ordenação dentro das funções de ordenação
    int *vetorOriginal;             // Vetor que terá as posições originais de cada elemento
    int inc = 1000;    // Tamanho Inicial
    int fim = 20000;    // Tamanho Final
    int stp = 1000;    // Intervalo entre os Tamanhos
    int rpt = fim/stp;    // Número de repetições a serem realizadas
    //***************************************************************************************************************//

      
   
    //******************************************   DEBBUGUER ******************************************//
    //imprimeVetor(vetor, inc);
    //imprimeVetor(vetorOriginal, inc);
    //CopiarElementosDoVetor(vetor, &vetorOriginal, inc);
    //******************************************   DEBBUGUER ******************************************//


    //*********************************************************************************************************************************//
    //****************************************************RANDOM***********************************************************************//
    //*********************************************************************************************************************************// 
    printf("[[RANDOM]]\n");
    fprintf(arq, "[[RANDOM]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    for(int w = 0; w < rpt; w++ ){
        printf("%d\t", inc);
        fprintf(arq, "%d\t", inc);
        // Alimenta o vetor com números Randômicos
        CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &inc);
        //inc = inc;
       
        

        calculoDeTempo = 0;
        //**************************** SELECTION-SORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
        //**************************** INSERTION-SORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //**************************** MERGESORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, 0, inc-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  HEAPSORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  QUICKSORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, 0, inc-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  COUNTINGSORT *************************************************-//
       for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\n", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
        
        
        free(vetor);
        free(vetorOriginal);
        inc += stp; // Incrementa a quantidade de elementos que será para a próxima iteração
    }

    printf("\n\n\n"); 


    //*********************************************************************************************************************************//
    //****************************************************REVERSE**********************************************************************//
    //*********************************************************************************************************************************//
    printf("[[REVERSE]]\n");
    fprintf(arq, "[[REVERSE]]\n");

    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    int *vetorInverso=NULL;
    inc = 1000;

    for(int w = 0; w < rpt; w++ ){
        printf("%d\t", inc);
        fprintf(arq, "%d\t", inc);
        // Alimenta o vetor com números Randômicos
        CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &inc);
        //inc = inc;


        quickSort(vetor, 0, inc-1);

        //imprimeVetor(vetor, inc);

        vetorInverso = inverte(vetor, inc);
        //imprimeVetor(vetor, inc);
        free(vetor);

          //Vetor reverso//
       
        
       
        calculoDeTempo = 0;
        //**************************** SELECTION-SORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetorInverso, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetorInverso, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
        //**************************** INSERTION-SORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetorInverso, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetorInverso, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //**************************** MERGESORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetorInverso, 0, inc-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetorInverso, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  HEAPSORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetorInverso, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetorInverso, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  QUICKSORT *************************************************-//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetorInverso, 0, inc-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetorInverso, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  COUNTINGSORT *************************************************-//
       for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetorInverso, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetorInverso, inc);
            

        }
        printf("%.6f\n", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
        
        
        free(vetorInverso);
        free(vetorOriginal);
        inc += stp; // Incrementa a quantidade de elementos que será para a próxima iteração
        
            

    }

    printf("\n\n\n"); 



    
    //*********************************************************************************************************************************//
    //****************************************************SORTED***********************************************************************//
    //*********************************************************************************************************************************//

    printf("[[SORTED]]\n");
    fprintf(arq, "[[SORTED]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    int teste = 10;
    inc = 1000;// Reseta o início da quantidade de elementos
    for(int w = 0; w < rpt; w++ ){
        printf("%d\t", inc); // Imprime a quantidade de elementos que estamos passando para o vetor
        fprintf(arq, "%d\t", inc); // Imprime a quantidade de elementos que estamos passando para o vetor

        // Alimenta o vetor com números Randômicos
        CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &inc);
        selectionSort(vetor, inc); // Deixa o vetor ordenado
        

        calculoDeTempo = 0;
        //**************************** SELECTION-SORT *************************************************-//
        for(int k = 0; k < teste; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            //imprimeVetor(vetor, inc);

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
        //**************************** INSERTION-SORT *************************************************-//
        for(int k = 0; k < teste; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc); //RETIRAR DEPOIS
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //**************************** MERGESORT *************************************************-//
        for(int k = 0; k < teste; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, 0, inc-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  HEAPSORT *************************************************-//
        for(int k = 0; k < teste; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  QUICKSORT *************************************************-//
        for(int k = 0; k < teste; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, 0, inc-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
       //****************************  COUNTINGSORT *************************************************-//
       for(int k = 0; k < teste; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\n", calculoDeTempo/10);
        fprintf(arq, "%.6f\t", calculoDeTempo/10);

        calculoDeTempo = 0;
        
        
        free(vetor);
        free(vetorOriginal);
        inc += stp; // Incrementa a quantidade de elementos que será para a próxima iteração
    }

       

    
    return 0;
}