/** @file module1.h
 * @brief Módulo de Implementação de um FIFO
 * 
 * Este módulo contém uma implementação simples de uma memória FIFO de inteiros.
 * Nesta implementação temos acesso a 7 funcionalidades de aceeso ao FIFO, uma delas
 * inicializa os parametros internos do FIFO e aloca espaço para os dados do mesmo
 * perante o tamanho que o utilizador define e inicializa esses espaços a zero.
 * Temos também uma função de inserção de um elemento no FIFO, função de 
 * eleminação do elemento inserido há mais tempo, funções de verificação de se
 * o FIFO está vazio e cheio, bem como o número de elementos inseridos até ao momento.
 * E por fim uma função que retorna o elemento inserdio há mais tempo e outra função
 * que imprime o conteúdo inserido no FIFO.
 * 
 * 
 *  @author Rodolfo Oliveira, Nº Mec: 88919
 *  @date 14 Março 2023
 *  @bug Nenhum bug conhecido
 * 
*/


#include <stdbool.h>
#ifndef FIFOInit_H
#define FIFOInit_H
/**
 * @brief Definição de uma estrutura de dados
 * 
 * 
 * Definição de uma estrutura de dados com elementos necessários para a execução 
 * das funcionalidades implementadas para o FIFO.
 * 
*/
typedef struct FIFO{
 	int idxPrim;	/**< Elemento que aponta para a posição do FIFO em que foi inserido o primeiro dado.*/
 	int idxUlt;		/**< Elemento que aponta para a posição do FIFO em que foi inserido o último dado.*/
 	int elementos;  /**< Número de elementos total que o FIFO pode ter.*/
 	int nIns;		/**< Número de elemtos inseridos.*/
 	int *val;		/**< Ponteiro para o endereço inicial do espaço de memório reservado para o FIFO*/
 }FIFO;

/**
 * @brief Função de Inicialização dos parâmetros da Estrutura de dados referente ao FIFO
 * 
 * Nesta função inicializa-se o FIFO que o utulizador pretende usar e predefine-se os valores internos 
 * da estrutura de dados. Começa-se por alocar espaço de memória para o número de parâmetros que o 
 * utilizador necessita e necessários para guardar elementos do tipo inteiro.
 * De seguida, preenchemos os espaços de memória com o valor zero, e reseta-se os valores dos ponteiro
 * para o primeiro e último elemento inserido, bem como o número de elementos inseridos. 
 * Guarda-se o número total de elementos definido pelo utilizador.
 * 
 * @param <b>*nome</b> endereço que contém a estrutura FIFO criada pelo utilizador
 * @param <b>tam</b> Número total de elementos do FIFO inserido pelo utilizador
*/
void MyFIFOInit(FIFO *nome, int tam);

/**
 * @brief Função de inserção de elementos no FIFO
 * 
 * Nesta função efetua-se a inserção de números inteiros inseridos pelo utilizador 
 * e é feita a verificação de se o FIFO já está cheio e então o número não é inserido.
 * Também é necessária a atualização do idxUlt que aponta para a posição do último elemento inserido, caso
 * tenha sido inserido um elemento, esta atualizaçáo é feita com uma máscara que força o valor do
 * idxUlt a se encontrar entre 0 e elementos(número total de elementos do FIFO). Por último, incrementa-se
 * nIns que indica o número de elementos inseridos. 
 * 
 * @param <b>*nome</b> ponteiro para o endereço que contém a estrutura FIFO criada pelo utilizador
 * 
 *  
*/
void MyFIFOInsert(FIFO *nome, int valor);

/**
 * @brief Função de remover o elemento há mais tempo inserido
 * 
 * Nesta função efetua-se a remoção do número inteiro inserido há mais tempo e verifica-se
 * se o FIFO está vazio e caso esteja então, não é feita nenhuma remoção. Também atualiza-se o idxPrim que aponta para a posição do primeiro elemento do FIFO, caso seja efetuada a remoção,
 * esta atualizaçáo é feita com uma máscara que força o valor do
 * idxPrim a se encontrar entre 0 e elementos(número total de elementos do FIFO). Por último, incrementa-se
 * nIns que indica o número de elementos inseridos.
 * 
 * @param <b>*nome</b> pendereço que contém a estrutura FIFO criada pelo utilizador
 * 
*/
void MyFIFORemove(FIFO *nome);

/**
 * @brief Função que verifica-se o FIFO está cheio
 * 
 * Nesta função verifica-se se FIFO tem todo o seu espaço de dados preenchido
 * 
 * @param <b>Ins</b> Número de elementos inseridos
 * @param <b>tam</b> Número total de elementos do FIFO 
 * 
 * @return true se o FIFO estiver cheio, false se o FIFO não estiver cheio
*/
bool FIFOFull(int Ins, int tam);

/**
 * @brief Função que verifica-se o FIFO está vazio
 * 
 * Nesta função verifica-se se FIFO tem todo o seu espaço de dados vazio
 * 
 * @param <b>Ins</b> Número de elementos inseridos
 * 
 * @return true se o FIFO estiver vazio, false se o FIFO não estiver vazio
*/

bool FIFOEmpty(int Ins);

/**
 * @brief Retorna o elemento inserido há mais tempo sem o remover
 * 
 * Nesta função é retornado o valor do elemento para o qual o idxPrim aponta,
 * a qual contém o elemento inserido há mais tempo. Verifica-se se o FIFO está vazio
 * e neste caso retorna o valor 0, caso tenho valores inserido retorna o valor pretendido.
 * 
 * @param <b>nome</b> Estrutura de dados inicializada pelo utilizador
 * 
 * @return 0 caso o FIFO esteja vazio, ou caso tenha algum elemento inserido o valor do elemento inserido há mais tempo 
*/
int MyFIFOPeep(FIFO nome);

/** 
 * @brief Tamanho do FIFO
 * 
 * Número total de elementos que podem ser inseridos no FIFO. 
 * 
 * @param <b>nome</b> Estrutura de dados inicializada pelo utilizador
 * 
 * @return Número total de elementos 
 * 
*/

int MyFIFOSize(FIFO nome);

/**
 * @brief Imprime o conteúdo do FIFO
 * 
 * Imprime o conteúdo do FIFO deste o elemento inserido há mais tempo(idxPrim) até 
 * ao elemento inserido por último(idxUlt).
 * 
 * @param <b>nome</b> Estrutura de dados inicializada pelo utilizador
 * 
 * @return Print dos valores inserido no FIFO
*/
void MyFIFOPrint(FIFO nome);
#endif



