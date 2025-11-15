// --- A SUA FUNÇÃO ---
// Insere um novo nó no inicio da lista.
void inserirNoInicio(struct No** inicio, int valor) {
    // 1. Criamos nosso "novo nó" alocando memória para ele.
    struct No* novo = (struct No*) malloc(sizeof(struct No));

// Verificação para o caso de falha na alocação de memória.
if (novo == NULL) {
    printf("Erro: Falha ao alocar memória.\n");
}

// 2. Colocamos o valor dentro dele.
novo->dado = valor;

// 3. O "próximo" do nosso novo nó será o antigo inicío da lista.
// O ponteiro 'inicio' é um ponteiro para o ponteiro, então '*inicio' nos dá o ponteiro para o primeiro nó atual.
novo->proximo = *inicio;

// 4. Agora, o inicío da lista passa a ser o nosso novo nó
// Modificamos o ponteiro original para que ele aponte para o novo nó.
*inicio = novo;
}