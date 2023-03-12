#include <stdio.h>
#include "FIFO.c"



void main(void){
	// struct FIFO s1;
 	/*
 	MyFIFOInit(&s1, 20);
 	for(int i = 0;i<20;i++){
 		printf("nada: %d\n",s1.val[i]);
 	}
 	MyFIFOInsert(&s1, 200000);
 
 	for(int i = 0;i<22;i++){
 		printf("\nnada: %d\n",s1.val[i]);
 		MyFIFOInsert(&s1, 20000);
 	}*/
 	struct FIFO s1;
 	int numEle = 10;
 	MyFIFOInit(&s1, numEle);
 	
 	char c;
	int num;
		printf("\nMenu de opçoes: \n");
 		printf("Press 1 - Inserir elemento\n");
		printf("Press 2 - Remover elemento\n");
		printf("Press 3 - Verificar se a Memória está Cheia\n");
		printf("Press 4 - Verificar se a Memória está Vazio\n");
		printf("Press 5 - Print do Conteúdo do FIFO\n");
		
		
	while(1){
		printf("\nNova açao: ");
		scanf("%c",&c);
 		switch(c){
 			case '1':
 				//Verificar se FIFO está cheia
				if(FIFOFull(&s1)){
					printf("\n Espaço de Memória Cheio!\n");
				}
				else{
					printf("\nValor a Inserir: ");
					scanf("%d",&num);
					MyFIFOInsert(&s1,num);
				}
				break;
			case '2':	//Remover elemento
				MyFIFORemove(&s1);
				break;
			case '3':	//Verificar se a Memória está Cheia
				if(FIFOFull(&s1)){
					printf("\nEspaço de Memória Cheio!\n");
				}
				else{
					printf("\nExiste Espaço Livre no Espaço de Memória !\n");
				}
				break;
			case '4':	//Verificar se a Memória está Vazio
				if(FIFOEmpty(&s1)){
					printf("\nEspaço de Memória Vazio!\n");
				}
				else{
					printf("\nJá foram Inseridos Elementos ao FIFO\n");
				}
				break;	
			case '5':	// Print do Conteúdo do FIFO
				for(int i = 0;i<numEle;i++){
 				printf("%d\n",s1.val[i]);
 				}
 		}
		
 	}
}

