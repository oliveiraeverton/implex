#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include"ordenacao.h"


int main(){

    //-************************************************ABERTURA DE ARQUIVO********************************************************-//
    FILE *arq= fopen("saidas.txt", "w");
    FILE *csv_random= fopen("random.csv", "w");
    FILE *csv_reverse= fopen("reverse.csv", "w");
    FILE *csv_sorted= fopen("sorted.csv", "w");
    FILE *csv_nearly= fopen("nearly.csv", "w");
    // Inicializar o gerador de números randômicos com um valor de semente
    srand(time(NULL));
    if(arq == NULL){
        printf("Erro na criacao do documento TXT");
        return 1;
    }
    if(csv_random == NULL || csv_reverse == NULL || csv_sorted == NULL || csv_nearly == NULL){
        printf("Erro na criacao do documento CSV");
        return 1;
    }
    //-****************************************************************************************************************************-//



    //-********************************************   DECLARAÇÃO DE VARIÁVEIS ******************************************************-//
    clock_t start_time, end_time;   // Variável para iniciar e terminar o cronômetro
    double elapsed_time=0;            // Variável que guardará a diferença entre inicío e fim do cronômetro
    double calculoDeTempo = 0;      // variável para calcular a média do tempo
    int *vetor;                     //Vetor utilizado para a ordenação dentro das funções de ordenação
    int *vetorOriginal;             // Vetor que terá as posições originais de cada elemento
    int inc = 0;      // Tamanho Inicial
    int fim = 0;     // Tamanho Final
    int stp = 0;      // Intervalo entre os Tamanhos
    int rpt = 0;        // Número de repetições a serem realizadas
    double tempos[6] = {0};
    //-*******************************************************************************************************************************-//

    //-********************************************************************Leitura das Entradas**********************************************-//

    printf("Digite o inc fim stp rpt: ");
    scanf("%d %d %d %d", &inc, &fim, &stp, &rpt);
   
    //-********************************************************************   DEBBUGUER **********************************************-//
    //imprimeVetor(vetor, inc);
    //imprimeVetor(vetorOriginal, inc);
    //CopiarElementosDoVetor(vetor, &vetorOriginal, inc);
    //-********************************************************************   DEBBUGUER **********************************************-//


    //-*******************************************************************************************************************************-//
    //-***********************************************************RANDOM**************************************************************-//
    //-*******************************************************************************************************************************-//
    printf("[[RANDOM]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    
    fprintf(arq, "[[RANDOM]]\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(csv_random, "n,Selection,Insertion,Merge,Heap,Quick,Counting\n");

    for(int w = inc; w <= fim; w += stp){
        printf("%d\t", w); // Imprime a quantidade de elementos no vetor
        fprintf(arq, "%d\t", w); // Imprime a quantidade de elementos no vetor
        fprintf(csv_random, "%d,", w); // Imprime a quantidade de elementos no vetor

        for(int n = 0; n < rpt; n++){
            // Alimenta o vetor com números Randômicos
            CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &w);

            calculoDeTempo = 0;
            //-********** SELECTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
            tempos[0] = tempos[0] + calculoDeTempo;


            calculoDeTempo = 0;
            //-********** INSERTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
            tempos[1] = tempos[1] + calculoDeTempo;


            calculoDeTempo = 0;
            //-********** MERGESORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
            tempos[2] = tempos[2] + calculoDeTempo;


            calculoDeTempo = 0;
            //-**********  HEAPSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
            tempos[3] = tempos[3] + calculoDeTempo;


            calculoDeTempo = 0;
            //-**********  QUICKSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
            tempos[4] = tempos[4] + calculoDeTempo;


            calculoDeTempo = 0;
            //-**********  COUNTINGSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
            tempos[5] = tempos[5] + calculoDeTempo;


            free(vetor);
            free(vetorOriginal);
            vetor=NULL;
            vetorOriginal=NULL;
       }
       // Imprime os tempos
       for(int i =0; i < 6; i++){
        printf("%.6f\t", tempos[i]/rpt);
        fprintf(arq, "%.6f\t", tempos[i]/rpt);
        if(i < 5){
            fprintf(csv_random, "%.6f,", tempos[i]/rpt);
        }else{
            fprintf(csv_random, "%.6f\n", tempos[i]/rpt);
        }
        
        tempos[i] = 0;
       }
       printf("\n");

    }

    printf("\n\n\n"); 


    //-**************************************************************************************************************************//
    //-**********************************************************REVERSE*********************************************************//
    //-**************************************************************************************************************************//
    printf("[[REVERSE]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    
    fprintf(arq, "[[REVERSE]]\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(csv_reverse, "n,Selection,Insertion,Merge,Heap,Quick,Counting\n");
    
    //int *vetorInverso=NULL;
    
    for(int w = inc; w <= fim; w += stp){
        printf("%d\t", w); // Imprime a quantidade de elementos
        fprintf(arq, "%d\t", w); // Imprime a quantidade de elementos
        fprintf(csv_reverse, "%d,", w); // Imprime a quantidade de elementos

        for(int n = 0; n < rpt; n++){
            // Alimenta o vetor com números Randômicos
            CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &w);

            // Ordena o vetor 
            quickSort(vetor, 0, w-1);
            quickSort(vetorOriginal, 0, w-1);

            // Inverte o vetor
            revert(vetor, w); 
            revert(vetorOriginal, w); 

            
            calculoDeTempo = 0;
            //-********** SELECTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[0] = tempos[0] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);


            calculoDeTempo = 0;
            //-********** INSERTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[1] = tempos[1] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
                

            calculoDeTempo = 0;
            //-********** MERGESORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[2] = tempos[2] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
                

            calculoDeTempo = 0;
            //-**********  HEAPSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[3] = tempos[3] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
                

            calculoDeTempo = 0;
            //-**********  QUICKSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[4] = tempos[4] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, w);
                

            calculoDeTempo = 0;
            //-**********  COUNTINGSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[5] = tempos[5] + calculoDeTempo;

            free(vetor);
            free(vetorOriginal);
            vetor=NULL;
            vetorOriginal=NULL; 
            
        }
        
        // Imprime os tempos
        for(int i =0; i < 6; i++){
        
           printf("%.6f\t", tempos[i]/rpt);
            fprintf(arq, "%.6f\t", tempos[i]/rpt);
            if(i < 5){
                fprintf(csv_reverse, "%.6f,", tempos[i]/rpt);
            }else{
                fprintf(csv_reverse, "%.6f\n", tempos[i]/rpt);
            }
            tempos[i] = 0;
        }
        printf("\n");
        //printf("\nPP. Endereco do vetor %p\n", vetor);
        //printf("PP. Endereco do vetorOriginal %p\n", vetorOriginal);
        
    }

    printf("\n\n\n"); 

    
    //-***************************************************************************************************************************-//
    //-*******************************************************SORTED**************************************************************-//
    //-***************************************************************************************************************************-//

    printf("[[SORTED]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");

    fprintf(arq, "[[SORTED]]\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(csv_sorted, "n,Selection,Insertion,Merge,Heap,Quick,Counting\n");

    for(int w = inc; w <= fim; w += stp){
        printf("%d\t", w); // Imprime a quantidade de elementos que estamos passando para o vetor
        fprintf(arq, "%d\t", w); // Imprime a quantidade de elementos que estamos passando para o vetor
        fprintf(csv_sorted, "%d,", w); // Imprime a quantidade de elementos que estamos passando para o vetor        


        for(int n = 0; n < rpt; n++){
            // Alimenta o vetor com números Randômicos
            CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &w);
            selectionSort(vetor, w); // Deixa o vetor ordenado
            selectionSort(vetorOriginal, w); // Deixa o vetor ordenado
            

            calculoDeTempo = 0;
            //-********** SELECTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[0] = tempos[0] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

            calculoDeTempo = 0;
            //-********** INSERTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[1] = tempos[1] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc); //RETIRAR DEPOIS
            

            calculoDeTempo = 0;
            //-********** MERGESORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[2] = tempos[2] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
                

            calculoDeTempo = 0;
            //-**********  HEAPSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[3] = tempos[3] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
                

            calculoDeTempo = 0;
            //-**********  QUICKSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[4] = tempos[4] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
                

            calculoDeTempo = 0;
            //-**********  COUNTINGSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[5] = tempos[5] + calculoDeTempo;

            free(vetor);
            free(vetorOriginal);
            vetor=NULL;
            vetorOriginal=NULL;             

        }

        // Imprime os tempos
        for(int i =0; i < 6; i++){
        
            printf("%.6f\t", tempos[i]/rpt);
            fprintf(arq, "%.6f\t", tempos[i]/rpt);
            if(i < 5){
            fprintf(csv_sorted, "%.6f,", tempos[i]/rpt);
        }else{
            fprintf(csv_sorted, "%.6f\n", tempos[i]/rpt);
        }
            tempos[i] = 0;
        }
        printf("\n");


        
    }

     printf("\n\n\n"); 

   
    //-***************************************************************************************************************************-//
    //-****************************************************NEARLY SORTED**********************************************************-//
    //-***************************************************************************************************************************-//  

       printf("[[NEARLY SORTED]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");

    fprintf(arq, "[[NEARLY SORTED]]\n");
    fprintf(arq, "n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    fprintf(csv_nearly, "n,Selection,Insertion,Merge,Heap,Quick,Counting\n");
    /*

        

    */

    for(int w = inc; w <= fim; w += stp){
        printf("%d\t", w); // Imprime a quantidade de elementos que estamos passando para o vetor
        fprintf(arq, "%d\t", w); // Imprime a quantidade de elementos que estamos passando para o vetor
        fprintf(csv_nearly, "%d,", w); // Imprime a quantidade de elementos que estamos passando para o vetor


        for(int n = 0; n < rpt; n++){
            // Alimenta o vetor com números Randômicos
            CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &w);
            selectionSort(vetor, w); // Deixa o vetor ordenado
            selectionSort(vetorOriginal, w); // Deixa o vetor ordenado

            semiEmbaralha(vetor, vetorOriginal, w); //Embaralha 10% do vetor com o Randomicamente


            calculoDeTempo = 0;
            //-********** SELECTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[0] = tempos[0] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

            calculoDeTempo = 0;
            //-********** INSERTION-SORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[1] = tempos[1] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc); //RETIRAR DEPOIS
            

            calculoDeTempo = 0;
            //-********** MERGESORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            mergeSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[2] = tempos[2] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
                

            calculoDeTempo = 0;
            //-**********  HEAPSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            heapSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[3] = tempos[3] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
                

            calculoDeTempo = 0;
            //-**********  QUICKSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            quickSort(vetor, 0, w-1);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[4] = tempos[4] + calculoDeTempo;
            CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
                

            calculoDeTempo = 0;
            //-**********  COUNTINGSORT *****************-//
            // Iniciar a contagem de tempo
            start_time = clock();
            countingSort(vetor, w);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            tempos[5] = tempos[5] + calculoDeTempo;

            free(vetor);
            free(vetorOriginal);
            vetor=NULL;
            vetorOriginal=NULL;             

        }

        // Imprime os tempos
        for(int i =0; i < 6; i++){
        
            printf("%.6f\t", tempos[i]/rpt);
            fprintf(arq, "%.6f\t", tempos[i]/rpt);
            if(i < 5){
                fprintf(csv_nearly, "%.6f,", tempos[i]/rpt);
            }else{
                fprintf(csv_nearly, "%.6f\n", tempos[i]/rpt);
            }
            tempos[i] = 0;
        }
        printf("\n");


        
    }



    fclose(arq);
    fclose(csv_random);
    fclose(csv_reverse);
    fclose(csv_sorted);
    fclose(csv_nearly);


    return 0;

}
