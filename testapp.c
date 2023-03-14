
/**
 * @file testapp.c
 * @brief Aplicação para teste das funcionalidades do FIFO 
 * 
 * Neste aplicação temos um menu de opções a que o utilizador pode recorrer para 
 * verificar o funcionamento do FIFO.
 * 
 * @author Rodolfo Oliveira, NºMec: 88919
 * @date 14 Março 2023
 * @bug Imprime no terminal "Nova ação: ERRO" logo após ser executada uma ação e sem que 
 * se tenha clicado em alguma tecla para definar uma ação.
 * 
 * 
*/
/* Includes */
#include <stdio.h>
#include "FIFO.h"

/**
 * @brief Função que propõe opções de ações que o utilizador pode efetuar para testar o FIFO
 * 
 * Menu de opçoes a que o utilizador pode recorrer para a testagem das funcionalidades
 * implementadas para o FIFO. Por exemplo, Inserção de elementos, remoção de elementos,
 * Print do elemento inserido há mais tempo, Número total de elementos e print do conteúdo do FIFO.
 * 
 * @return sempre retorna strings
 * 
*/

void main(){
 	/* Inicializaçao de variaveis*/
	struct FIFO s1;
 	int numEle = 10;
 	MyFIFOInit(&s1, numEle);
 	
 	char c;
	int num,elem;
	/*Menu de opçoes de açoes*/
		printf("\nMenu de opçoes: \n");
 		printf("Press 1 - Inserir elemento\n");
		printf("Press 2 - Remover elemento\n");
		printf("Press 3 - Print do Elemento inserido há mais tempo\n");
		printf("Press 4 - Print do Número de Elementos do FIFO\n");
		printf("Press 5 - Print do Conteúdo do FIFO\n");
		
	while(1){
		printf("\nNova açao: ");
		scanf("%c",&c);
		/*decisao de qual opçao escoolhida pelo utilizador*/
 		switch(c){
 			case '1':
				printf("\nValor a Inserir: ");
				scanf("%d",&num);
				MyFIFOInsert(&s1,num);
				break;
			case '2':	//Remover elemento
				MyFIFORemove(&s1);
				break;
			case '3':	//Print do Elemento inserido há mais tempo
				elem = MyFIFOPeep(s1);
				printf("%d\n",elem);
				//printf("O valor do elemento mais antigo do FIFO é: %d\n",elem);
				break;
			case '4':
				printf("O FIFO tem %d Elelemtos Inseridos!\n",MyFIFOSize(s1));
				break;
			case '5':	// Print do Conteúdo do FIFO
				MyFIFOPrint(s1);
				break;
			default:
				printf("ERRO");
				break;
 		}
		
 	}
}

