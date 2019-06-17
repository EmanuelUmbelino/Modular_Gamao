/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peças Capturadas
*
*  Arquivo gerado:              PECASCAPTURADAS.C
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	3			elu			16/06/2019		Revisão Final
*	2			jpk			04/06/2019		-Conserto da função de destruir a barra 
*											-Subtituição dos valores 0 e 1 por "Preta" e "Vermelha"
*											-Implementação da função de contar número de peças das listas da barra
*	1			jpk			24/04/2019		Criação do módulo
*
***************************************************************************/

	#include	<malloc.h>
	#include 	<stdio.h>
	#include	<stdlib.h>
	#include	"..\Peca\PECA.H"
	#include	"..\Lista\LISTA.H"
	#define PECASCAPTURADAS_OWN
	#include "PECASCAPTURADAS.H"
	#undef PECASCAPTURADAS_OWN

/***********************************************************************
*
*  $TC Tipo de dados: BAR Descritor da Barra de peças capturadas
*
*
*  $ED Descrição do tipo
*     Descreve a organização da Barra de peças capturadas
*
***********************************************************************/

	typedef struct tgBarra {
		LIS_tppLista Vermelhas ;
		LIS_tppLista Pretas ;
		/* Ponteiros para as lista de peças capturadas*/

	} tpBarra ;

/*****  Dados encapsulados no módulo  *****/

	static tpBarra* bar = NULL ;
		/* Ponteiro para a barra de peças capturadas */
		
/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR Criar Barra de peças capturadas
*  ****/

	BAR_tpCondRet BAR_CriarBarra( void )
	{
		LIS_tppLista* casa = NULL ;
		int i ;

		if ( bar != NULL ) {
			BAR_DestruirBarra( ) ;
		} /* if */

		bar = ( tpBarra * ) malloc( sizeof( tpBarra ) ) ;
		if ( bar == NULL ) {
			return BAR_CondRetFaltouMemoria ;
		} /* if */
		
		( bar )->Vermelhas = LIS_CriarLista(PEC_DestruirPeca) ;
		( bar )->Pretas = LIS_CriarLista(PEC_DestruirPeca) ;
		if ( ( bar )->Vermelhas == NULL || ( bar )->Pretas == NULL ) {
			return BAR_CondRetFaltouMemoria ;
		} /* if */

		return BAR_CondRetOK ;
	}/* Fim função: BAR Criar Barra de peças capturadas */

/***************************************************************************
*
*  Função: BAR Destruir Barra de peças capturadas
*  ****/

	void BAR_DestruirBarra( void )
	{
		LIS_tppLista * capturadas ;
		int i, numCasas ;

		if (bar == NULL) {
			return ;
		} /* if */

		LIS_EsvaziarLista( bar->Vermelhas ) ;
		LIS_DestruirLista( bar->Vermelhas ) ;

		LIS_EsvaziarLista( bar->Pretas ) ;
		LIS_DestruirLista( bar->Pretas ) ;

		free( bar ) ;
		bar = NULL ;
	} /* Fim função: BAR Destruir Barra de peças capturadas */


/***************************************************************************
*
*  Função: BAR Inserir peça na Barra de peças capturadas
*  ****/

	BAR_tpCondRet BAR_InserePeca( CorPecas cor )
	{
		LIS_tpCondRet cond ;
		PEC* peca ;

		if ( bar == NULL ) {
			return BAR_CondRetBarNaoExiste ;
		} /* if */

		PEC_CriarPeca( &peca, cor ) ;
		if ( peca == NULL ) {
			return BAR_CondRetFaltouMemoria;
		} /* if */
		
		if (cor == Preta) {
			cond = LIS_InserirElementoAntes( ( bar )->Pretas, peca ) ;
		} /* if */
		else {
			cond = LIS_InserirElementoAntes( ( bar )->Vermelhas, peca ) ;
		} /* else if */

		if ( cond == LIS_CondRetFaltouMemoria ) {
			return BAR_CondRetFaltouMemoria ;
		} /* if */

		return BAR_CondRetOK ;

	}/* Fim função: BAR Inserir peça na Barra de peças capturadas */

/***************************************************************************
*
*  Função: BAR Remover peça na Barra de peças capturadas
*  ****/

	BAR_tpCondRet BAR_RemovePeca( CorPecas cor )
	{
		int cond = 0;
		
		if ( bar == NULL ) {
			return BAR_CondRetBarNaoExiste ;
		} /* if */

		if ( cor == Preta ) {
			cond = LIS_ExcluirElemento( ( bar )->Pretas ) ;
		} /* if */
		else if ( cor == Vermelha ) {
			cond = LIS_ExcluirElemento( ( bar )->Vermelhas ) ;
		} /* else if */
		
		if ( cond == LIS_CondRetListaVazia ) {
			return BAR_CondRetListaVazia ;
		} /* if */

		return BAR_CondRetOK ;
	} /* Fim função: BAR Remover peça da Barra de peças capturadas */

/***************************************************************************
*
*  Função: BAR Numero de peças da barra
*  ****/

	BAR_tpCondRet BAR_NumPecas( CorPecas cor, int * numPecas )
	{
		if ( bar == NULL ) {
			return BAR_CondRetBarNaoExiste ;
		} /* if */

		if ( cor == Vermelha ) {
			if ( bar->Vermelhas == NULL ) {
				return BAR_CondRetListaVazia ;
			} /* if */
			LIS_NumElemenLista( bar->Vermelhas, numPecas ) ;
		} /* if */
		else {
			if ( bar->Pretas == NULL ) {
				return BAR_CondRetListaVazia ;
			} /* if */
			LIS_NumElemenLista( bar->Pretas, numPecas ) ;
		} /* else */

		return BAR_CondRetOK;
	} /* Fim função: BAR Numero de peças da barra */

/********** Fim do módulo de implementação: Módulo Tabuleiro **********/