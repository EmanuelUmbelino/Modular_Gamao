/***************************************************************************
*  $MCI Módulo de implementação: Módulo Dado de Pontos
*
*  Arquivo gerado:              DADOPONTOS.C
*  Letras identificadoras:      DPT
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data          Observações
*				5				elu			01/05/2019	   Revisão e reimplementação completa do módulo
*				4				jpk			01/05/2019	   Finalização parcial do módulo
*	    	3    		jpk	  	22/04/2019     Finalização parcial do módulo 
*	    	2   		jpk	  	17/04/2019     Criação dos escopos das funções
*       1	   	  elu	  	17/04/2019     Inicializado projeto
*
***************************************************************************/

	#include	<malloc.h>
	#include 	<stdio.h>
	#include	<stdlib.h>
	#define DPT_OWN
	#include "DADOPONTOS.H"
	#undef DPT_OWN


/***********************************************************************
*
*  $TC Tipo de dados: DPT Descritor do dado de pontos
*
*
*  $ED Descrição do tipo
*     Descreve a organização do dados de pontos
*
***********************************************************************/

	typedef struct tgDadoPontos
	{
		int valor;
			/* Valor da partida atual */
		CorPecas podeDobrar;
			/*	Cor do jogador que pode Dobrar 
			*
			*$EED Assertivas estruturais
			*   Começa com NULL, os dois podem dobrar
			*   Depois vai revezando entre os jogadores */
	} tpDadoPontos ;

/*****  Dados encapsulados no módulo  *****/

		static tpDadoPontos * dpt = NULL ;
				/* Ponteiro para o dado de pontos */


/******  Código das funções exportadas pelo módulo  ******/

/***************************************************************************
*
*  Função:  DPT Criar Dado de Pontos
*  ****/
	
	DPT_tpCondRet DPT_CriarDadoPontos( void )
	{
		dpt = ( tpDadoPontos* ) malloc ( sizeof( tpDadoPontos ) ) ;

		if ( dpt == NULL ) {
			return DPT_CondRetFaltouMemoria ;
		} /* if */
	
		dpt->valor = 1 ;
		dpt->podeDobrar =  Neutro ;
		return DPT_CondRetOK ;

	} /* Fim função: DPT Criar Dado de Pontos */

/***************************************************************************
*
*  Função: DPT Detruir Dado de Pontos
*  ****/

	void DPT_DestruirDadoPontos ( void )
	{
		if ( dpt == NULL )
		{
			return ;
		} /* if */

		free(dpt) ;
		dpt = NULL ;

	} /* Fim função: DPT Detruir Dado de Pontos */

/***************************************************************************
*
*  Função: DPT Dobra Pontos da Partida
*  ****/

	DPT_tpCondRet DPT_DobraPontos ( CorPecas jogador )
	{
		if ( dpt == NULL ) {
			return DPT_CondRetDPTNaoExiste ;
		} /* if */

		if ( dpt->podeDobrar != Neutro && dpt->podeDobrar != jogador ) {
			return DPT_NaoPodeDobrar;
		} /* if */

		dpt->valor *= 2 ;
		dpt->podeDobrar = !jogador ;
		return DPT_CondRetOK ;
	
	} /* Fim função: DPT Dobra Pontos da Partida */


/***************************************************************************
*
*  Função: DPT Valor da Partida
*
****************************************************************************/

	DPT_tpCondRet DPT_ValorPartida ( int * valor )
	{
		if ( dpt == NULL ) {
			return DPT_CondRetDPTNaoExiste ;
		} /* if */

		*valor = dpt->valor ;
		return DPT_CondRetOK ;
	} /* Fim função: DPT Valor da Partida */


/***************************************************************************
*
*  Função: DPT Quem Pode Dobrar
*
****************************************************************************/

	DPT_tpCondRet DPT_QuemPodeDobrar ( CorPecas * jogador )
	{
		if ( dpt == NULL ) {
			return DPT_CondRetDPTNaoExiste ;
		} /* if */

		*jogador = dpt->podeDobrar ;
		return DPT_CondRetOK ;
	} /* Fim função: DPT Quem Pode Dobrar */
 

/********** Fim do módulo de implementação: Módulo Dado de Pontos **********/