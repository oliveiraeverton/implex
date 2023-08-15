//Essa função não está sendo utilizada
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

void CopiarElementosDoVetor(int *vetor,int *vetorC ,int tamanhoDoVetor){
    for(int i = 0; i < tamanhoDoVetor; i++){
        vetorC[i] = vetor[i];
    }
}