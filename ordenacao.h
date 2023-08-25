#ifndef _ORDENACAO_
#define _ORDENACAO_

#include <time.h>
#include <stdlib.h>

//Protótipo das funções de ordenação:
void insertionSort(int arr[], int n);

void selectionSort(int arr[], int n);

void swap(int *a, int *b);

void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int left, int right);

void heapify(int arr[], int n, int i);

void heapSort(int arr[], int n);

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);


void countingSort(int arr[], int n);


//Funções relativas ao manejo dos vetores

void imprimeVetor(int arr[], int n);

void CriaVetorComElementosRandomicos(int **vetorParaOrdenacao, int **vetorOriginal,int *n);

void CopiarElementosDoVetor(int *vetorOriginal,int **vetorCopia ,int tamanhoDoVetor);


int * inverte(int *vetor, int n);

void revert(int arr[], int n);

void semiEmbaralha(int arrOrig[], int arr[], int n);


#endif
