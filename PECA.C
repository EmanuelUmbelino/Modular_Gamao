/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peça
*
*  Arquivo gerado:              PECA.C
*  Letras identificadoras:      PEC
*
*  Projeto: Disciplina INF 1301
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.05    elu	  	27/04/2019     Criadas funções de criar, destruir e obter cor
*      1.00    elu	  	17/04/2019     Inicializado projeto
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include "PECA.H"

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

			PEC_cor cor ;
					/* Cor da peça */

	} ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PEC Criar Peça
*  ****/

	PEC * PEC_CriarPeca( PEC_cor cor )
	{
		PEC *nova ;

		nova = ( PEC * ) malloc( sizeof( PEC )) ;
		if ( nova == NULL )
		{
			printf("\nErro na alocação de memória para a peça\n") ;
			return ;
		} /* if */

		nova->cor = cor ;

		return nova ;

	} /* Fim função: PEC Criar Peça */

/***************************************************************************
*
*  Função: PEC Destruir Peça
*  ****/

	void PEC_DestruirPeca( PEC * peca )
	{
		if ( peca != NULL )
		{
			free( peca ) ;
		} /* if */

	} /* Fim função: PEC Destruir Peça */

/***************************************************************************
*
*  Função: PEC Obter Cor
*  ****/

	PEC_cor PEC_ObterCor( PEC * peca ) 
	{
		if ( peca == NULL )
		{
			printf("\nErro peça nula ou não criada\n") ;
			return ;
		} /* if */
		return peca->cor ;

	} /* Fim função: PEC Obter Cor */