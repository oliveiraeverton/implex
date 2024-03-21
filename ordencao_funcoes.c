#include <stdio.h>
#include"ordenacao.h"


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] >= key) {
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


void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right){
        if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

//TROCAR PELA DO TAKASHI
void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}



void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

//QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//Counting

void countingSort(int arr[], int n) {
    // Encontra o maior elemento no array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Cria um array temporário para contar a ocorrência de cada elemento
    int *count = (int *)calloc(max + 1, sizeof(int));

    // Conta as ocorrências de cada elemento no array original
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Atualiza o array original com os elementos ordenados
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }

    // Libera a memória alocada para o array de contagem
    free(count);
}

//Função para imprimir o vetor
void imprimeVetor(int arr[], int n){

    int count=0;
    for(int i = 0; i < n; i++){
        if(count == 10){
            count =0;
             printf("\n");
        }
        printf("%d ", arr[i]);
        count++;
    }
    
    printf("\n\n");

}
void revert(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Troca o elemento máximo encontrado com o elemento atual
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}


//Função para criar os números aleatórios
void CriaVetorComElementosRandomicos(int **vetorParaOrdenacao, int **vetorOriginal,int *n){
    
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

void CopiarElementosDoVetor(int *vetorOriginal,int **vetorCopia ,int inc){
    // vetorCopia é o vetor que vai receber os elementos originais do vetorOriginal
    for(int *i = *vetorCopia; i < *vetorCopia + inc; i++){
        *i = *vetorOriginal++;
    
    }
}

int * inverte(int *vetor, int n){

    int pos=0;

    int *vet = (int *) malloc(n *sizeof(int));

    for(int i = n-1; i >=0; i--){

        vet[pos] = vetor[i];
        pos++;

    }
    
    return vet;
}

void semiEmbaralha(int arrOrig[], int arr[], int n){

    int porcentagem_embaralha = n*0.10;

    srand(time(NULL));

    for( int i =0; i < porcentagem_embaralha; i++){

        
        int w = rand() % 1000;
        arrOrig[i] = w;
        arr[i] = w;
    }

}
