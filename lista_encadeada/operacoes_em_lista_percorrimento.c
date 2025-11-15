// --- A SUA FUNÇÃO ---
// Percorre a lista a partir do nó inicial e imprime o dado de cada nó.
void listar(struct No* inicio) {
    // 1. Criamos um ponteiro "viajante" que começa no inicio
    struct No* atual = inicio;

    // Se a lista estiver vazia, informamos ao usuário.
    if (atual == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    printf("Elementos na lista:\n");
    // 2. Enquanto nosso viajante não chegar ao fim (NULL)...
    while (atual != NULL) {
        // 3. Mostramos o dado do nó onde ele está...
        printf("%d", atual ->dado);

        // 4. E fazemos ele pular para o próximo nó!
        atual = atual ->proximo;
    }
}