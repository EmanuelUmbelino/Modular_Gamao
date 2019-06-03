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
*     Versão  Autor    Data      	Observações
*     	2	     elu   02/05/2019 	Feita função de jogar dado
*     	1      phs   18/04/2019 	Início do desenvolvimento
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

DAD_tpCondRet DAD_JogarDado( int * valor )
{
	if ( first ) {
		srand( (unsigned)time(NULL) ) ;
		first = 0 ;
	}
	*valor = ( rand ( ) % NUMBER_OF_FACES ) + 1 ;

	return DAD_CondRetOK ;

} /* Fim função: DAD Jogar Dado */
	

/********** Fim do módulo de implementação: Módulo Dado **********/
