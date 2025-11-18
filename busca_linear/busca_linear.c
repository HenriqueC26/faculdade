// --- A SUA FUNÇÃO ---
// Descrição: Procura por um 'valor' em um array 'lista' de um determinado 'tamanho'.
// Retorno:
// - O índice (posição) da primeira ocorrência do valor, se encontrado.
// - -1, se o valor não estiver na lista.

int buscaLinear(int lista[], int tamanho, int valor) {
    // Começamos um loop do início (índice 0) até o fim da lista
    for (int i = 0; i < tamanho; i++) {
        // Em cada passo, comparamos o elemento atual com o valor que buscamos
        if (lista [i] == valor) {
        // Se encontrarmos, retornamos a posição (índice) onde ele está
        return i;
        }   
    }
    // Se o loop terminar e não encontrarmos nada, retornamos -1
    return -1;
}