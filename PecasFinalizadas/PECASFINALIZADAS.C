/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peças Finalizadas
*
*  Arquivo gerado:              PECASFINALIZADAS.C
*  Letras identificadoras:      FIM
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	2			elu			17/06/2019		Revisão Final
*	1			phs			29/04/2019		Criação do módulo
*
***************************************************************************/

	#include <malloc.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include "..\Peca\PECA.H"
	#include "..\Lista\LISTA.H"
	#define PECASFINALIZADAS_OWN
	#include "PECASFINALIZADAS.H"
	#undef PECASFINALIZADAS_OWN


/***********************************************************************
*
*  $TC Tipo de dados: FIM Descritor da lista de peças finalizadas
*
*
*  $ED Descrição do tipo
*     Descreve a organização da lista de peças finalizadas
*
***********************************************************************/

	typedef struct tgPecasFinalizadas {
		LIS_tppLista Vermelhas ;
		LIS_tppLista Pretas ;
		/* Ponteiros para as lista de peças finalizadas*/

	} tpPecasFinalizadas ;


/*****  Dados encapsulados no módulo  *****/

	static tpPecasFinalizadas * FIM = NULL ;
		/* Ponteiro para a lista de peças finalizadas */

		
/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: FIM Criar Lista de Peças Finalizadas
*  ****/

	FIM_tpCondRet FIM_CriarFinalizadas( void )
	{	
		if ( FIM != NULL ) {
			FIM_DestruirFinalizadas( ) ;
		} /* if */

		FIM = ( tpPecasFinalizadas * ) malloc( sizeof( tpPecasFinalizadas ) ) ;
		if ( FIM == NULL ) {
			return FIM_CondRetFaltouMemoria ;
		} /* if */

		( FIM )->Vermelhas = LIS_CriarLista( PEC_DestruirPeca ) ;
		( FIM )->Pretas = LIS_CriarLista( PEC_DestruirPeca ) ;
		if ( ( FIM )->Vermelhas == NULL || ( FIM )->Pretas == NULL ) {
			return FIM_CondRetFaltouMemoria ;
		} /* if */

		return FIM_CondRetOK ;
	}/* Fim função: FIM Criar Lista de Peças Finalizadas */


/***************************************************************************
*
*  Função: FIM Destruir Lista de Peças Finalizadas
*  ****/

	void FIM_DestruirFinalizadas( void )
	{
		if ( FIM == NULL ) {
			return ;
		} /* if */

		LIS_EsvaziarLista( FIM->Pretas ) ;
		LIS_EsvaziarLista( FIM->Vermelhas ) ;

		LIS_DestruirLista( FIM->Vermelhas ) ;
		LIS_DestruirLista( FIM->Pretas ) ;

		free( FIM ) ;
		FIM = NULL ;
	} /* Fim função: Destruir Lista de Peças Finalizadas */


/***************************************************************************
*
*  Função: FIM Inserir Peça na Lista de Peças Finalizadas
*  ****/

	FIM_tpCondRet FIM_FinalizarPeca( CorPecas cor )
	{
		LIS_tpCondRet cond ;
		PEC * peca ;

		if ( FIM == NULL ) {
			return FIM_CondRetFimNaoExiste ;
		} /* if */

		PEC_CriarPeca( &peca, cor ) ;
		if ( peca == NULL ) {
			return FIM_CondRetFaltouMemoria ;
		} /* if */
		
		if ( cor == Preta ) {
			cond = LIS_InserirElementoAntes( FIM->Pretas, peca ) ;
		} /* if */
		else {
			cond = LIS_InserirElementoAntes( FIM->Vermelhas, peca ) ;
		} /* else */

		if ( cond == LIS_CondRetFaltouMemoria ) {
			return FIM_CondRetFaltouMemoria ;
		} /* if */

		return FIM_CondRetOK ;

	}/* Fim função: FIM Inserir Peça na Lista de Peças Finalizadas */

/***************************************************************************
*
*  Função: FIM Numero de Peças na Lista de Peças Finalizadas
*  ****/

	FIM_tpCondRet FIM_NumPecas( CorPecas cor, int * numPecas )
	{
		if ( FIM == NULL ) {
			return FIM_CondRetFimNaoExiste ;
		} /* if */
		
		if ( cor == Vermelha ) {
			LIS_NumElemenLista( FIM->Vermelhas, numPecas ) ;
		} /* if */
		else {
			LIS_NumElemenLista( FIM->Pretas, numPecas ) ;
		} /* else */

		return FIM_CondRetOK ;

	} /* Fim função: FIM Numero de Peças na Lista de Peças Finalizadas */

/********** Fim do módulo de implementação: Módulo Peças Finalizadas **********/