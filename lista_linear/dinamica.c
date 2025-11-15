//  Armazena elementos em sequência, mas tem a incrível capacidade de
//  aumentar ou diminuir o tamanho enquanto o programa está rodando.

// Passo 1: Alocando a memória inicial
int* numeros = (int*) malloc(3 * sizeof(int));

// Passo 2: Preenchendo a lista
numeros [0] = 10;
numeros [1] = 20;
numeros [2] = 30;

// Passo 3: Realocando a memória para expandir a lista
numeros = (int*) realloc(numeros, 5 * sizeof(int));

// Passo 4: Adicionando os novos valores
numeros [3] = 40;
numeros [4] = 50;