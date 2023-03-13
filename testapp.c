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
	int num,elem;
		printf("\nMenu de opçoes: \n");
 		printf("Press 1 - Inserir elemento\n");
		printf("Press 2 - Remover elemento\n");
		printf("Press 3 - Print do Elemento inserido há mais tempo\n");
		printf("Press 4 - Print do Número de Elementos do FIFO\n");
		printf("Press 5 - Print do Conteúdo do FIFO\n");
		
	while(1){
		printf("\nNova açao: ");
		scanf("%c",&c);
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
				//printf("O valor do elemento mais antigo do FIFO é: %d\n",elem);
				break;
			case '4':
				printf("O FIFO tem %d Elelemtos Inseridos!\n",MyFIFOSize(s1));
				break;
			case '5':	// Print do Conteúdo do FIFO
				MyFIFOPrint(s1);
 		}
		
 	}
}

