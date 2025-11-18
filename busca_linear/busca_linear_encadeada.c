// --- A SUA FUNÇÃO ---
// Descrição: Procura por um 'valor' em uma lista ligada a partir do 'inicio'.
// Retorno:
// - A posição (índice baseado em zero) do valor, se encontrado.
// - 1, se o valor não estiver na lista.

int buscaLinearLista(struct No* inicio, int valor) {
    int pos = 0; // Um contador para sabermos a posição (índice 0, 1, 2, ...)
    struct No* atual = inicio; // Nosso "ponteiro viajante"

    // Enquanto não chegamos ao fim da lista (NULL)...
    while (atual != NULL){
        // Verificamos se o dado do nó atual é o que procuramos
        if (atual ->dado == valor) {
            // Encontramos! Retornamos a posição.
            return pos;
        }
        // Se não for, pulamos para o próximo nó...
        atual = atual->proximo;
        // ... e incrementamos nosso contador de posição.
        pos++;
    }
    // Se while acabar, significa que percorremos toda a lista e não encontramos.
    return -1;
}