//Repetir o Processo
    printf("[[RANDOM]]\n");
    printf("n\tSelection\tInsertion\tMerge\t\tHeap\t\tQuick\t\tCounting\n");
    inc = 1000;
   //inc = inc;
    for(int w = 0; w < rpt; w++ ){
        printf("%d\t", inc);
        // Alimenta o vetor com números Randômicos
        CriaVetorComElementosRandomicos(&vetor, &vetorOriginal, &inc);
        inc += stp; // Incrementa a quantidade de elementos que será para a próxima iteração

        // DEIXAR O VETOR ORDENADO
        insertionSort(vetor, inc);

        //**************************** INSERTION-SORT *************************************************//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            insertionSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        calculoDeTempo = 0;
        //**************************** SELECTION-SORT *************************************************//
        for(int k = 0; k < 10; k++){
            // Iniciar a contagem de tempo
            start_time = clock();
            selectionSort(vetor, inc);
            // Parar a contagem de tempo
            end_time = clock();
            // Calcular o tempo decorrido em segundos
            elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
            calculoDeTempo += elapsed_time;
            //CopiarElementosDoVetor(vetorOriginal, &vetor, inc);
            

        }
        printf("%.6f\t", calculoDeTempo/10);
        calculoDeTempo = 0;
       //**************************** MERGESORT *************************************************//
        for(int k = 0; k < 10; k++){
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
        calculoDeTempo = 0;
       //****************************  HEAPSORT *************************************************//
        for(int k = 0; k < 10; k++){
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
        calculoDeTempo = 0;
        
       //****************************  QUICKSORT *************************************************//
        for(int k = 0; k < 10; k++){
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
        calculoDeTempo = 0;
        
       //****************************  COUNTINGSORT *************************************************//
       for(int k = 0; k < 10; k++){
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
        calculoDeTempo = 0;
        
        printf("\n\n\n");
        free(vetor);
        free(vetorOriginal);
    }