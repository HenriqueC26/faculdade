// --- A SUA FUNÇÃO ---
// Remove o primeiro nó da lista.
void removerDoInicio(struct No** inicio); {
    // 1. Primeiro, checamos se a lista não está vazia!
    // Se 'inicio' for NULL ou apontar para NULL, não há nada a remover.
    if (inicio == NULL || *inicio == NULL) {
        printf("A lista está vazia. Nada a remover.\n");
        return;
    }

    // 2. Guardamos o endereço do nó que vamos remover (o primeiro nó)
    struct No* noParaRemover = *inicio;

    // 3. O inicio da lista agora passa a ser segundo nó
    // O ponteiro 'inicio' passa a apontar para o nó seguinte ao que será removido.
    *inicio = (*inicio)->proximo;

    // 4. Liberamos a memória do nó que foi guardado e removido da lista
    free(noParaRemover);
}