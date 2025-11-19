// --- A SUA FUNÇÃO ---
// Descriçao: Procura por um 'valor' em um 'vetor' de um dado 'tamanho'.
//          Funciona para vetores ordenados ou não ordenados.
// Retorno.
// - O índice (posição) do valor, encontrado
// - -1, se o valor não estiver no vetor

int buscaSequencial(int veto[], int tamamnho, int valor) {
    // Percorrre o vetor do início ao fim, um elemento por vez.
    for (int i = 0; i < tamanho; i++) {     // O "ler por linha"

        // Compara o elemento atual com o valor buscado.
        if (vetor[i] == valor) {        // A pergunta "É esse?"

            // Se for igual, a busca termina com sucesso. Retorna o índice.
            return i;

        }

    }

    // Se o laço 'for' terminar, significa que todos os elementos foram verificados
    // e o valor não foi encontrado.
    return -1; // "Cheguei ao fim e não encontrei."
}