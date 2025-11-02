#include <stdio.h>

// função criada para o usuario informar qual numero deseja buscar.
 
int numero_buscar(int *valor){
	
    printf("informe o numero que deseja ser buscado >: ");
    scanf("%i", valor);
    
 return(*valor); // a função retorna um valor que sera utilizado posteriormente. 
}

// função criada para mostrar onde o numero se encontra no vetor (posição).
void mostrar_posicao(int *posicao){
	
	if(*posicao == -1){
        printf("\nValor nao encontrado\n\n");
    }
	else{
        printf("\nValor encontrado na posicao %d\n\n", *posicao);
    }
}

//função criada para fazer a busca.
int busca_Interpolada(int *vetor, int valor){
	
    int inicio = 0;// inicio = primeira posição do vetor
    int fim = 19;// fim = tamanho do vetor que é igual a (20) menos 1 = (19)
    int meio;// variavel criada para receber o resultado da conta 
    
    //laço de repetição criada para fazer o calculo do valor alvo
    while(inicio <= fim){ 
    	
        meio = inicio + ((valor - vetor[inicio]) * (fim - inicio)) / (vetor[fim] - vetor[inicio]);
        // meio recebe = inicio == (0) + 
		// valor == (valor inserido pelo usuario) - vetor[inicio] == (1) *
		// fim == (19) - inicio == (0) /
		// vetor[fim] == (20) - vetor[inicio] == (1).
		
		// formula e seus determinados valores... {exemplo: se valor = 15}.
		
		// 0 + (15 - 1) * (19 - 0)   14 * 19   266
		// ----------------------- = ------- = ---- =  14
		//        (20 - 1)              19      19     
		
        if(vetor[meio] == valor){ // if criado com o intuito de verifeicar
			return (meio);        // se o vetor[meio] == valor -> (15)	
        } 						  // se essa condição for verdadeira o programa retorna meio 
        
		else if(vetor[meio] < valor){ // else if criado com o intuito de verificar 
			inicio = meio + 1;        // se o vetor[meio] é menor que o valor -> (15)
        }							  // se essa condição for verdadeira inicio recebe a
			 	 	 	 	 	 	  // soma do valor de meio mais 1. 
		else{
			fim = meio - 1; // else criado com o intuito de caso 
        }                   // todas as instruções a cima forem falsas
    }						// diante disso fim recebe meio - 1.
return (-1);
}

int main(void){
	// criação do vetor com 20 numeros e 19 posições
    int vetor[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    
    // for criado com o intuido de criar um laço de repetição infinito... :)
    for(;;){ 
    	// variavel criada para receber o tamnaho da função. 
    	// foi utilizado o sizeof para não especificar o tamanho do vetor
		 
	    int valor; // variavel criada para receber o valor inseridopelo usuario 
	    
	    numero_buscar(&valor); // chamada da função para o usuario informar o número
	    
	    // cração da variavel posição e a chama da função para calcular a posição do valor destino 
	    int posicao = busca_Interpolada(vetor, valor);
	    
	    // chamda da função para mostrar a posição do valor inserido pelo usuari...
	    mostrar_posicao(&posicao);
    }
 return (0);
}