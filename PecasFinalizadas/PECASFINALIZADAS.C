/***************************************************************************
*  $MCI Módulo de implementação: Módulo Lista de Peças Finalizadas
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
*    Versão	  Autores	 	   Data           Observações 
*      1		phs	  		29/04/2019     Criação do módulo
*
***************************************************************************/

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "..\Peca\PECA.H"
#include "..\Lista\LISTA.H"

#define FIM_OWN
#include "PECASFINALIZADAS.H"
#undef FIM_OWN


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
		LIS_tppLista Vermelhas;
		LIS_tppLista Pretas;
		/* Ponteiros para as lista de peças finalizada*/

	} tpPecasFinalizadas;


/*****  Dados encapsulados no módulo  *****/

	static tpPecasFinalizadas * FIM = NULL;
		/* Ponteiro para a lista de peças finalizadas */


		
/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: FIM Criar Lista de Peças Finalizadas
*
***************************************************************************/

	FIM_tpCondRet FIM_CriarFinalizadas(void)
	{	
		FIM = (tpPecasFinalizadas *) malloc(sizeof(tpPecasFinalizadas));

		if (FIM == NULL)
		{
			return FIM_CondRetFaltouMemoria;
		} /* if */

		(FIM)->Vermelhas = LIS_CriarLista( PEC_DestruirPeca );
		(FIM)->Pretas = LIS_CriarLista( PEC_DestruirPeca );

		if ((FIM)->Vermelhas == NULL || (FIM)->Pretas == NULL)
		{
			return FIM_CondRetFaltouMemoria;
		} /* if */

		return FIM_CondRetOK;
	}/* Fim função: FIM Criar Lista de Peças Finalizadas */


/***************************************************************************
*
*  Função: FIM Destruir Lista de Peças Finalizadas
*
***************************************************************************/

	void FIM_DestruirFinalizadas(void)
	{
		if ( FIM == NULL )
		{
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
*
***************************************************************************/

	FIM_tpCondRet FIM_FinalizarPeca( CorPecas cor )
	{
		PEC * peca ;

		if ( FIM == NULL ) {
			return FIM_CondRetFimNaoExiste ;
		} /* if */

		PEC_CriarPeca( &peca, cor ) ;
		
		if ( peca == NULL ) {
			return FIM_CondRetFaltouMemoria ;
		} /* if */
		
		if ( cor == Preta )   // peças pretas
		{
			LIS_InserirElementoAntes( FIM->Pretas, peca ) ;
			return FIM_CondRetOK ;
		} /* if */
		else if ( cor == Vermelha )  // peças vermelhas
		{
			LIS_InserirElementoAntes( FIM->Vermelhas, peca ) ;
			return FIM_CondRetOK ;
		} /* else if */

	}/* Fim função: FIM Inserir Peça na Lista de Peças Finalizadas */

/***************************************************************************
*
*  Função: FIM Quantidades de Peças na Lista de Peças Finalizadas
*
***************************************************************************/

	FIM_tpCondRet FIM_QuantidadeFinalizada( CorPecas cor, int * QuantidadeFinalizada )
	{
		if ( FIM == NULL )
		{
			return FIM_CondRetFimNaoExiste ;
		} /* if */
		
		if ( cor == 0 )
		{
			LIS_NumElemenLista( FIM->Pretas, QuantidadeFinalizada ) ;
		} /* if */
		else if ( cor == 1 )
		{
			LIS_NumElemenLista( FIM->Vermelhas, QuantidadeFinalizada ) ;
		} /* else if */

		return FIM_CondRetOK ;

	} /* Fim função: FIM Quantidades de Peças na Lista de Peças Finalizadas */
