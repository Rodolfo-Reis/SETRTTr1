#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "FIFO.h"
 

 
//Inicializa os parametros do meu fifo
void MyFIFOInit(FIFO *nome, int tam){
	nome->val = (int*) malloc(tam*sizeof(int)); // alocar espaço de memoria para guardar valores
	
	//Colocar todos os elementos com o valor '0'
	for(int i=0;i<tam;i++){
		MyFIFOInsert(nome,0);
	}
	// resetar ponteiros de posiçao para diferentes elementos do espaço de mem
	nome->idxPrim = 0;  // posiçao do elemento inserido há mais tempo
	nome->idxUlt = 0;  // posiçao do elemento inserido há menos tempo	
	// guardar o número de elementos 
	nome->elementos = tam;
	// resetar numero de elementos inserido
	nome->nIns = 0;
	
}

//Funçao para Inserir elemento no FIFO
int MyFIFOInsert(FIFO *nome, int valor){
	 if(FIFOFull(nome->nIns,nome->elementos)){
	 	printf("\nEspaço de Memória Cheio!\n");
		printf("Elemento Não Inserido!");
		return 1;
	 }
	 else {
	 	nome->val[nome->idxUlt] = valor;
	 	// garantir que temos uma memoria circular
	 	// logo idxUlt atinge o tam na seguinte incrementação toma o valor 0
	 	nome->idxUlt = (nome->idxUlt + 1) % (nome->elementos +1);
	 	nome->nIns++;
		return 0;
	 } 
}

// Função para verificar se o espaço de memoria está cheio
// retorna true se estiver cheio
// retorna false se nao estiver
bool FIFOFull(int Ins, int tam){
	return (Ins == tam);
}

// Funçao para retirar elemento que está há mais tempo no FIFO
int MyFIFORemove(FIFO *nome){
	// Verificar se o FIFO está vazio
	if(FIFOEmpty(nome->nIns)){
		printf("\nEspaço de Memória Vazio!\n");
		return 1;
	}
	else{
		// reseta o valor do elemento que está há mais tempo
		nome->val[nome->idxPrim]= 0;
		// atualiza o ponteiro para o primeiro elemento
		nome->idxPrim = (nome->idxPrim + 1) % (nome->elementos +1);
		nome->nIns--;
		printf("\nElemento removido com Sucesso!\n");
		return 0;
	}
	
}

// Função para verificar se o espaço de memoria está vazio
// retorna true se estiver vazio
// retorna false se nao estiver
bool FIFOEmpty(int Ins){
	return (Ins == 0);
}

//Função para dar print do primeiro elemento inserido sem retiralo
int MyFIFOPeep(FIFO nome){
	if(FIFOEmpty(nome.nIns)){
		printf("\nEspaço de Memória Vazio!\n");
		printf("Não foi removido nenhum elemento!\n");
		return 0;
	}
	else{
		printf("O valor do elemento mais antigo do FIFO é: %d\n",nome.val[nome.idxPrim]);
		return(nome.val[nome.idxPrim]);		
	}
}

// Funçao para dar print do Numero de elementos inseridos
int MyFIFOSize(FIFO nome){
	return(nome.nIns);
}

// Funçao para dar print do conteudo do FIFO
int MyFIFOPrint(FIFO nome){
	if(FIFOEmpty(nome.nIns)){
		printf("\nEspaço de Memória Vazio!\n");
		return 1;
	}
	else{
		for(int i = 0;i<nome.nIns;i++){
 				printf("%d\n",nome.val[((nome.idxPrim + i) % (nome.elementos +1))]);
 				}
		return 0;
	}
}

