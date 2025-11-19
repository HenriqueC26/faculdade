// --- A SUA FUNÇÃO (O motor recursivo) ---
// Descrição: Procurar por um 'valor' em uma fatia de um 'vetor' ORDENADO,
//                      definida por 'inicio' e 'fim'.
// Pré-requisito: O vetor deve estar em ordem crescente.
// Retorno: O índice do valor se encontrado; -1 caso contrário.

int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor) {
    if (inicio > fim)
        return -1;
    }
    // Calcula a posição do meio.
    // Usar 'inicio + fim (fim - inicio) / 2' é mais segura contra overflow
    // em vetores extremamente grandes
    int meio = (inicio + fim) / 2;

    // Se o elemento do meio é o que procuramos, encontramos!
    // Este é o outro CASO BASE (de sucesso).
    if (vetor[meio] == valor) {
        return meio;
    }

    // PASSO RECURSIVO (Delegação):
    // Se o elemento do meio for menor que o valor, delegamos a busca
    // para a metade direita do vetor.
    else if (vetor[meio] < valor){
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor);
    }
    // Caso contrário, delegamos a busca para a metade esquerda.
        else {
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor);
}