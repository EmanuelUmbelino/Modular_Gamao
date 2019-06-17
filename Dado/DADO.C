/***************************************************************************
*  $MCI Módulo de implementação: Módulo Dado
*
*  Arquivo gerado:              DADO.C
*  Letras identificadoras:      DAD
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	3			elu			16/06/2019		Revisão Final
*	2			elu			02/05/2019		Feita função de jogar dado
*	1			phs			18/04/2019		Início do desenvolvimento
*
***************************************************************************/

	#include <stdlib.h>
	#include <time.h>
	#define DADO_OWN
	#include "DADO.H"
	#undef DADO_OWN

	#define NUMBER_OF_FACES	6

/*****  Dados encapsulados no módulo  *****/

	static int first = 1 ;
		/* Verifica se é a primeira vez que joga o dado */

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: DAD Jogar Dado
*  ****/

	void DAD_JogarDado( int * valor )
	{
		if ( first ) {
			srand( (unsigned)time(NULL) ) ;
			first = 0 ;
		} /* if */

		*valor = ( rand( ) % NUMBER_OF_FACES ) + 1 ;
	} /* Fim função: DAD Jogar Dado */
	

/********** Fim do módulo de implementação: Módulo Dado **********/
