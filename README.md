# Busca por Interpolação em C

## Descrição do Projeto

Este programa implementa o **algoritmo de busca por interpolação** em
linguagem C.\
O objetivo é localizar um valor dentro de um vetor **ordenado** de forma
**eficiente**, estimando a posição provável do elemento com base em uma
interpolação linear ou seja, levando em conta a **distribuição dos
valores no vetor**.

A busca por interpolação é uma melhoria da busca binária, especialmente
eficiente quando os dados são **uniformemente distribuídos**.

---
## Funcionamento do Programa

O programa realiza as seguintes etapas:

1.  **Criação de um vetor ordenado** de 20 elementos inteiros (de 1 a
    20).
2.  **Solicita ao usuário** que informe um número para ser buscado no
    vetor.
3.  **Executa a busca interpolada**, calculando uma estimativa de
    posição com base nos valores inicial e final do vetor.
4.  **Exibe o resultado**, informando se o número foi encontrado e em
    qual posição.
5.  **Repete o processo** indefinidamente, permitindo múltiplas buscas
    sem reiniciar o programa.

---
## Estrutura do Código

### 1. Função `numero_buscar(int *valor)`

Solicita ao usuário o número que ele deseja buscar.\
Lê o valor digitado e o retorna via ponteiro.

``` c
int numero_buscar(int *valor) {
    printf("informe o numero que deseja ser buscado >: ");
    scanf("%i", valor);
    return *valor;
}
```

### 2. Função `mostrar_posicao(int *posicao)`

Exibe o resultado da busca.\
Se o valor não for encontrado (`posicao == -1`), informa ao usuário.

``` c
void mostrar_posicao(int *posicao) {
    if (*posicao == -1)
        printf("\nValor nao encontrado\n\n");
    else
        printf("\nValor encontrado na posicao %d\n\n", *posicao);
}
```

### 3. Função `busca_Interpolada(int *vetor, int valor)`

Implementa o **algoritmo de busca por interpolação**.\
Calcula uma posição provável (`meio`) usando a fórmula:

    meio = inicio + ((valor - vetor[inicio]) * (fim - inicio)) / (vetor[fim] - vetor[inicio])

Compara o valor no índice `meio`: - Se for igual ao valor procurado,
retorna a posição. - Se for menor, move o início da busca para
`meio + 1`. - Se for maior, move o fim da busca para `meio - 1`. - Caso
o valor não seja encontrado, retorna `-1`.

``` c
int busca_Interpolada(int *vetor, int valor) {
    int inicio = 0;
    int fim = 19;
    int meio;

    while (inicio <= fim) {
        meio = inicio + ((valor - vetor[inicio]) * (fim - inicio)) / (vetor[fim] - vetor[inicio]);

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}
```

### 4. Função `main(void)`

Cria o vetor ordenado.\
Entra em um **loop infinito** (`for(;;)`), executando as funções de
entrada, busca e exibição.\
O programa permanece ativo até ser interrompido manualmente.

``` c
int main(void) {
    int vetor[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for (;;) {
        int valor;
        numero_buscar(&valor);
        int posicao = busca_Interpolada(vetor, valor);
        mostrar_posicao(&posicao);
    }

    return 0;
}
```

---
## Exemplo de Execução

**Entrada:**

    informe o numero que deseja ser buscado >: 15

**Saída:**

    Valor encontrado na posicao 14

**Outro caso:**

    informe o numero que deseja ser buscado >: 25

    Valor nao encontrado

---
## Requisitos

-   Compilador C (como `gcc`)
-   Sistema operacional compatível com terminal (Linux, macOS ou
    Windows)

---

## Como Compilar e Executar

### Compilar

``` bash
gcc busca\ por\ interpolação.c -o busca_interpolada
```

### Executar

``` bash
./busca_interpolada
```

---
## Observações Importantes

-   O vetor precisa estar **ordenado** para que o algoritmo funcione
    corretamente.
-   O programa utiliza **ponteiros** para passagem de parâmetros por
    referência.
-   O **loop infinito** (`for(;;)`) pode ser interrompido com
    `Ctrl + C`.
-   Ideal para fins **educacionais**, para estudar o funcionamento da
    busca interpolada e o uso de ponteiros em C.

---
## Autor

**Roberto F. Rocha**\
Projeto acadêmico desenvolvido em C para demonstração do algoritmo de
**Busca por Interpolação**.
