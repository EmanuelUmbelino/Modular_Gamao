/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peça
*
*  Arquivo gerado:              PECA.C
*  Letras identificadoras:      PEC
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data         Observações
*      3    		elu	  	01/05/2019     Modulo cor, correcoes em funções
*      2    		elu	  	27/04/2019     Criadas funções de criar, destruir e obter cor
*      1   			elu	  	17/04/2019     Inicializado projeto
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include   <stdlib.h>
#define PECA_OWN
#include   "PECA.H"
#undef PECA_OWN

/***********************************************************************
*
*  $TC Tipo de dados: PEC Descritor de uma peça
*
*
*  $ED Descrição do tipo
*     Descreve uma peça pela sua cor
*
***********************************************************************/

	struct peca {

			CorPecas cor ;
					/* Cor da peça */

	} ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PEC Criar Peça
*  ****/

	PEC_tpCondRet PEC_CriarPeca ( PEC ** peca, CorPecas cor )
	{

		*peca = ( PEC * ) malloc( sizeof( PEC )) ;
		if ( *peca == NULL )
		{
			return PEC_CondRetFaltouMemoria ;
		} /* if */

		(*peca)->cor = cor ;

		return PEC_CondRetOK ;

	} /* Fim função: PEC Criar Peça */

/***************************************************************************
*
*  Função: PEC Destruir Peça
*  ****/

	void PEC_DestruirPeca ( PEC * peca )
	{
		if ( peca == NULL )
		{
			return ;
		} /* if */

		free( peca ) ;
		peca = NULL ;

	} /* Fim função: PEC Destruir Peça */

/***************************************************************************
*
*  Função: PEC Obter Cor
*  ****/

	PEC_tpCondRet PEC_ObterCor ( PEC * peca, CorPecas * cor ) 
	{
		if ( peca == NULL )
		{
			return PEC_CondRetPecNaoExiste ;
		} /* if */
		*cor = peca->cor ;
		return PEC_CondRetOK ;

	} /* Fim função: PEC Obter Cor */
	

/********** Fim do módulo de implementação: Módulo Peça **********/