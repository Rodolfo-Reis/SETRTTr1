
#ifndef FIFOInit_H
#define FIFOInit_H

typedef struct FIFO{
 	int idxPrim;
 	int idxUlt;
 	int elementos;
 	int nIns;
 	int *val;
 }FIFO;
 
void MyFIFOInit(FIFO *nome, int tam);
void MyFIFOInsert(FIFO *nome, int valor);
bool FIFOFull(int Ins, int tam);
bool FIFOEmpty(int Ins);
int MyFIFOPeep(FIFO nome);
int MyFIFOSize(FIFO nome);
#endif



