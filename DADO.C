/***************************************************************************
*  $MCI Módulo de implementação: Dado
*
*  Arquivo gerado:              DADO.C
*  Letras identificadoras:      DAD
*
*  Projeto: INF 1301 	Projeto jogo gamão via terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*     1.00     phs   18/abr/2019 Início do desenvolvimento
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define NUMBER_OF_FACES	6

/***********************************************************************
*
*  $TC Tipo de dados: DAD conjunto de dois dados
*
***********************************************************************/

typedef struct dados
{

	int dado1;
		/* Valor do dado */

	int dado2;
		/* Valor do dado */

} tpDados;

/*****  Dados encapsulados no módulo  *****/

tpDados dados;
	/* Conjunto único de dados manipuláveis */

/***** Protótipos das funções encapuladas no módulo *****/

static void IniciarAleatorio( void ) ;

static int Aleatorio( int min , int max ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: DAD  Joga os dados
*  ****/

void DAD_JogarDados(void)
{

	IniciarAleatorio();

	dados.dado1 = Aleatorio(1, NUMBER_OF_FACES);
	dados.dado2 = Aleatorio(1, NUMBER_OF_FACES);

} /* Fim função: DAD  Joga os dados */

/***************************************************************************
*
*  Função: DAD 	Obtem valor do dado1
*  ****/

int DAD_obtemDado1()
{

	return dados.dado1;

} /* Fim função: DAD  Obtem valor do dado1 */

/***************************************************************************
*
*  Função: DAD 	Obtem valor do dado2
*  ****/

int DAD_obtemDado2()
{

	return dados.dado2;

} /* Fim função: DAD  Obtem valor do dado2 */

/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: DAD Inicializa a aleatoriedade
*
*  $FD Descrição da função
*		Aumenta a aleatoriedade a partir da chamada a srand com o 
*		retorno da chamada time.
*
***********************************************************************/

static void IniciarAleatorio( void )
{

	srand( (unsigned int) time( NULL ) );
	rand();
	rand();
	rand();

} /* Fim função: DAD  Obtem valor do dado2 */

/***********************************************************************
*
*  $FC Função: DAD Gera um número aleatório em um intervalo entre dois 
*		números
*
***********************************************************************/

static int Aleatorio( int min , int max )
{

	double r;

	r = (double) rand()/RAND_MAX;

	return (int)(min + r*(max-min));

} /* Fim função: DAD  Obtem valor do dado2 */
