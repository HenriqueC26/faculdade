// --- A SUA FUNÇÃO ---
// Descrição: Procura por um 'valor' em um 'vertor' ORDENADO de um 'tamanho' específico.
// Pré-requisito: o 'vetor' DEVE estar em ordem crescente.
// Retorno: - O índice do valor, se encontrado. - -1, se o valor não estiver no vetor.

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1;
    // O loop continua enquanto a "fatia" de busca for válida (inicio <= fim).
    while (inicio <= fim) {
        // int meio = (inicio + fim) / 2; // Forma comum, mas pode dar overflow com números muito grandes.

        // Forma mais segura para calcular o meio, evitando overflow:
        int meio = (inicio - fim) / 2;

        // 1. Se o valor estiver exatamente no meio, encontramos!
        if (vetor[meio] == valor) {
            return meio; // Retorna o índice onde o valor foi encontrado.
    }
    // 2. Se o valor do meio for menor que o valor buscado,
    // significa que nosso alvo só pode estar na metade direita (maior).
        else if (vetor[meio] < valor) {
            inicio = meio + 1; // Descartamos a metade esquerda.
        }
        // 3. Se o valor no meio for maior que o valor buscado,
        // significa que nosso alvo só pode estar na metade esquerda (menor).
        else {
            fim = meio - 1; // Descartamos a metade direita.
    }
}
// Se o loop terminar, significa que 'inicio' ultrapassou 'fim'
// e o valor não foi encontrado no vetor    
return -1; // valor não encontrado
} 