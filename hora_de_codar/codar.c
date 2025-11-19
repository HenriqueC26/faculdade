#include <stdio.h>
#include <string.h> // Essencial para comparar strings (strcmp)
#include <stdlib.h> // Para a função exit (), caso a lista não esteja ordenada para a busca binária

// --- DECLARAÇÃO DAS FUNÇÕES (PROTÓTIPOS) ---
// Isso informa ao compilador que essas funções existem e como elas são,
// mesmo que suas implementações estejam mais abaixo no código.

// 1. Busca Sequencial
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item);
int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice);

// 2. Busca Binária
int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item);
int buscaBinariaRecursiva_aux(const char* lista[], const char* item, int inicio, int fim);

// Função auxiliar para imprimir os resultados de forma organizada
void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado);


// --- FUNÇÃO PRINCIPAL (main) ---
// O programa começa a ser executado aqui.
int main() {
    // IMPORTANTE: Para a Busca Binária funcionar, a lista DEVE estar ordenada alfabeticamente.
    // Nossa lista de compras já está ordenada para o exemplo.
    const char* listaDeCompras[] = {
        "Arroz",
        "Batata",
        "Cebola",
        "Detergente",
        "Feijão",
        "Leite",
        "Macarrão",
        "Oleo",
        "Sal",
        "Tomate",
    };

    // Calcula o número de itens na lista.
    // sizeof(listaDeCompras) -> tamanho total do array em bytes.
    // sizeof(listaDeCompras[0]) -> tamanho de um elemento (um ponteiro char*) em bytes.
    // A divisão nos dá o número de elementos.
    int tamanhoDaLista = sizeof(listaDeCompras) / sizeof(listaDeCompras [0]);

    // Itens que vamos procurar para demonstrar os algoritmos.
    const char* itemExistente = "Leite";
    const char* itemInexistente = "Queijo";

    printf("--- DEMONSTRAÇÃO DE ALGORITMOS DE BUSCA EM LISTA DE TEXTO --- \n");
    printf("Lista utilizada: [Arroz, Batata, Cebola, Detergente, Feijão, Leite, Macarrão, Oleo, Sal, Tomate]\n");
    printf("---------------------------------------------------------------------------------------------------");

    // --- Testando a Busca Sequencial ---
    printf("--- 1. BUSCA SEQUENCIAL ---\n");
    // a) Versão Iterativa
    int res1 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Sequencial Iterativa", itemExistente, res1);

    int res2 = buscaSequencialIterativa(listaDeCompras, tamanhoDaLista,itemInexistente);
    imprimirResultado("Sequencial Iterativa", itemInexistente, res2);
    printf("\n");

    // b) Versão Recursiva
    int res3 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
    imprimirResultado("Sequencial Recursiva", itemExistente, res3);

    int res4 = buscaSequencialRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
    imprimirResultado("Sequencial Recursiva", itemInexistente, res4);
    printf("---------------------------------------------------------------------------------------------------\n\n");


   // --- Testando a Busca Binária ---
   printf("--- 2. BUSCA BINARIA (requer lista ordenada) ---\n");
   // a) Versão Iterativa
   int res5 = buscaBinariaIterativa(listaDeCompras, tamanhoDaLista, itemExistente);
   imprimirResultado("Binaria Iterativa", itemExistente, res5); 

   int res6 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
   imprimirResultado("Busca Iterativa", itemInexistente, res6);
   printf("\n");

   // b) Versão Recursiva
   int res7 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemExistente);
   imprimirResultado("Binaria Recursiva", itemExistente, res7);

   int res8 = buscaBinariaRecursiva(listaDeCompras, tamanhoDaLista, itemInexistente);
   imprimirResultado("Binaria Recursiva", itemInexistente, res8);
   printf("-----------------------------------------------------------------------------------------------------\n");


   return 0; // Indica que o programa terminou com sucesso.

}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

// ===================================================================================================================
// 1. BUSCA SEQUENCIAL
// ===================================================================================================================
// Percorre a lista elemento por elemento, do início ao fim,
// até encontrar o item ou chegar ao final da lista.
// Não requer que a lista esteja ordenada.
// ===================================================================================================================

/**
 * @brief Busca sequencial usando um laço (iteração).
 * @param lista O array de strings onde a busca será feita.
 * @param tamanho O número de elementos na lista.
 * @param item A string que está sendo procurada.
 * @return O indice do item se encontrado, ou -1 caso contrário.
*/
int buscaSequencialIterativa(const char* lista[], int tamanho, const char* item) {
    // Um laço 'for' percorre cada índice da lista, de 0 até 'tamanho - 1'.
    for(int i = 0; i < tamanho; i++) {
        // strcmp(str1, str2) compara duas strings.
        // Retorna 0 se elas forem identicas.
        if (strcmp(lista[i], item) == 0) {
            // Se as strings forem iguais, encontramos o item!
            return i; // Retorna o índice atual.
        }
    }
    // Se o laço terminar e não tivermos retornado nada,
    // significa que o item não está na lista.
    return -1;
}

/**
 * @brief Função "invólucro" (wrapper) para a busca sequencial recursiva.
 *        Ela esconde a complexidade do parâmetro 'indice' do usuário.
 */
 int buscaSequencialRecursiva(const char* lista[], int tamanho, const char* item) {
    // A lógica recursiva real está na função auxiliar.
    // Começamos a busca a partir do índice 0
    return buscaSequencialRecursiva_aux(lista, tamanho, item, 0);
 }

/**
  * @brief Função auxiliar que implementa a lógica recursiva da busca sequencial.
  * @param indice O índice do elemento atual a ser verificado.
  * @return O índice do item se encontrado, ou -1 no caso contrário.
  */
  int buscaSequencialRecursiva_aux(const char* lista[], int tamanho, const char* item, int indice) {
    // CASO BASE 1: FALHA (Fim da lista)
    // Se o índice atual for igual ou maior que o tamanho da lista,
    // significa que já percorremos todos os elementos sem sucesso.
    if (indice >= tamanho) {
        return -1; // Item não encontrado.
    }

    // CASO BASE 2: SUCESSO
    // Compara o item na posição 'indice' atual com o item procurado.
    if (strcmp(lista [indice], item) == 0) {
        return indice; // Item encontrado! Retorna o indice.
    }

    // PASSO RECURSIVO
    // Se não for nenhum dos casos base, o item ainda pode estar no resto da lista.
    // Chamamos a função novamente, mas agora para o próximo índice (indice + 1).
    // O retorno desta chamada será propagado para a chamada anterior.
    return buscaSequencialRecursiva_aux(lista, tamanho, item, indice + 1);
  }


  // ===================================================================================================================
  // 2. BUSCA BINÁRIA
  // ===================================================================================================================
  // Algoritmo de "dividir para conquistar".
  // A cada passo, ele olha para o elemento do meio da lista (ou sub-lista).
  // Se o item do meio for o procurado, a busca termina.
  // Se o item procurado for menor, ele descarta a metade direita e busca na esquerda.
  // Se for maior, descarta a metade esquerda e busca na direita.
  // Requer que a lista esteja ORDENADA.
  // ===================================================================================================================

  /**
   * @brief Busca binária usando um laço (iteração).
   * @return O índice do item se encontrado, ou -1 caso contrário.
   */
  int buscaBinariaIterativa(const char* lista[], int tamanho, const char* item) {
      int inicio = 0;
      int fim = tamanho - 1;
      int meio;

      // O laço continua enquanto a sub-lista for válida (inicio não ultrapassou o fim).
      while (inicio <= fim) {
        // Calcula o índice do meio
        // Usar inicio + (fim - inicio) / 2 evita overflow para listas muito grandes.
        meio = inicio + (fim - inicio) /2;

        // Compara a string do meio com o item procurado.
        int comparacao = strcmp(lista[meio], item);

        if (comparacao == 0) { // Encontrou!
            return meio;
        }
        else if (comparacao > 0) {
            // O item do meio vem DEPOIS do item procurado (ex: "leite" > "feijao").
            // Portanto, o item só pode estar na metade da esquerda.
            // Descartamos a metade direita, ajustando o 'fim'.
            fim = meio -1;
        }
        else { // comparacao < 0
            // O item do meio vem ANTES do item procurado (ex: "leite" < "sal").
            // Portanto, o item só pode estar na metade direita.
            // Descartamos a metade esquerda, ajustando o 'inicio'.
            inicio = meio + 1;
        }
    }

    // Se o laço 'while' terminar, significa que 'inicio' ultrapassou 'fim',
    // o espaço de busca se esgotou e o item não foi encontrado.
    return -1;
}


  /**
   * @brief Função "invólucro" (wrapper) para a busca binária recursiva.
   */
   int buscaBinariaRecursiva(const char* lista[], int tamanho, const char* item) {
    // Indica a busca recursiva em toda a lista, do índice 0 até 'tamanho -1'.
    return buscaBinariaRecursiva_aux(lista, item, 0, tamanho -1);
}


/**
 * @brief Função auxiliar que implementa a lógica recursiva da busca binária.
 * @param inicio O índice inicial da sub-lista atual.
 * @param fim O índice final da sub-lista atual.
 * @return O índice do item se encontrado, ou -1 caso contrário.
 */
 int buscaSequencialRecursiva_aux(const char* lista[], const char* item, int inicio, int fim) {
    // CASO BASE 1: FALHA (Espaço de busca inválido)
    // Se o 'inicio' ultrapassar o 'fim', a sub-lista é vazia, o item não está aqui.
    if (inicio > fim) {
        return -1;
    }

    // PASSO RECURSIVO E CASO BASE DE SUCESSO
    int meio = inicio + (fim - inicio) /2;
    int comparacao = strcmp(lista [meio], item);

    if (comparacao == 0) {
        // CASO BASE 2: SUCESSO
        retun meio; // Encontramos o item!
    }
    else if (comparacao > 0) {
        // O item está na metade da esquerda.
        // Chamamos a função novamente, mas com um novo 'fim'.
        return buscaBinariaRecursiva_aux(lista, item, inicio, meio - 1);
    }
    else { // comparacao < 0
        // O item está na metade direita.
        // Chamamos a função novamente, mas com um novo 'inicio'.
        return buscaBinariaRecursiva_aux(lista, item, meio + 1, fim);
    }
 }


 // ===================================================================================================================
 // FUNÇÃO AUXILIAR DE IMPRESSÃO
 // ===================================================================================================================

 /**
 * @brief Formata e imprime o resultado de uma busca.
 * @param nomeDaBusca O nome do algoritimo utilizado.
 * @param item O item que foi procurado.
 * @param resultado O resultado da busca (indice ou -1).
 */
 void imprimirResultado(const char* nomeDaBusca, const char* item, int resultado) {
    printf("[%s] Buscando por \"%s\"...\n", nomeDaBusca, item);
    if (resultado != -1) {
        printf ("   -> Resultado: Item encontrado no indice %d.\n", resultado);
    } else {
        printf("    -> Resultado: Item não encontrado na lista.\n");
    }
}