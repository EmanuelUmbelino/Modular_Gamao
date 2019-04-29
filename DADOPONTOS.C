	#pragma once
/***************************************************************************
*  $MCI Módulo de implementação: Módulo Dado Pontos
*
*  Arquivo gerado:              DADOPONTOS.C
*  Letras identificadoras:      DDPnt
*
*  Projeto: Disciplina INF 1301
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.00    elu	  	17/04/2019     Inicializado projeto
*	   1.00    jpk	  	17/04/2019     Criação dos escopos das funções
*	   1.00    jpk	  	22/04/2019     Finalização parcial do módulo 
*
***************************************************************************/

	#include "DADOPONTOS.H"
	#include <stdlib.h>
	#include <stdio.h>

	typedef struct tgDadoPontos
	{
		int valor;
			/* valor da partida atual */
	} tpDadoPontos ;

/***** Protótipos das funções encapsuladas no módulo *****/

	
	DDPnt_tpCondRet CriaDadoPontos ( tpDadoPontos ** dado );

	DDPnt_tpCondRet DestroiDadoPontos ( tpDadoPontos ** dado );

	DDPnt_tpCondRet DobraPontos ( tpDadoPontos * dado );

	void ExibeValorPartida ( tpDadoPontos * dado );

		
/******  Código das funções exportadas pelo módulo  ******/

/***************************************************************************
*
*  Função: DDPnt Criar Dado de Pontos
*
****************************************************************************/
	
	DDPnt_tpCondRet CriaDadoPontos( tpDadoPontos ** dado )
	{
		*dado = (tpDadoPontos*)malloc(sizeof(tpDadoPontos));

		if( dado == NULL )
		{
			return DDPnt_CondRetMemoryLess;
		} /* if */
	
		(*dado)->valor = 2;
		return DDPnt_CondRetOk;

	} /* Fim função: DDPnt Criar Dado de Pontos */

/***************************************************************************
*
*  Função: DDPnt Detroi Dado de Pontos
*
****************************************************************************/

	DDPnt_tpCondRet DestroiDadoPontos ( tpDadoPontos ** dado )
	{

		if ( dado == NULL )
		{
			return DDPnt_CondRetNonexistent;
		} /* if */

		free(*dado);
		printf("Dado de Pontos destruido com sucesso!\n");
		return DDPnt_CondRetOk;

	} /* Fim função: DDPnt Destroi Dado de Pontos */

/***************************************************************************
*
*  Função: DDPnt Dobra Pontos da Partida
*
****************************************************************************/

	DDPnt_tpCondRet DobraPontos ( tpDadoPontos * dado )
	{
	
		if ( dado == NULL )
		{
			return DDPnt_CondRetNonexistent;
		} /* if */

		dado->valor *= 2;

		return DDPnt_CondRetOk;
	
	} /* Fim função: DDPnt Dobra Pontos da Partida */


/***************************************************************************
*
*  Função: DDPnt Exibir valor da partida
*
****************************************************************************/

	void ExibeValorPartida (tpDadoPontos* dado)
	{
		printf("Valor da partida: %d\n", dado->valor);
	}