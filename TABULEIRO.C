#pragma once
/***************************************************************************
*  $MCI Módulo de implementação: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Projeto: Disciplina INF 1301
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.00    elu	  	17/04/2019     Inicializado projeto
*
***************************************************************************/

	#include "LISTA.H"
	#include "TABULEIRO.H"
	#include <stdio.h>
	#include <stdlib.h>

	struct TAB_Tabuleiro
	{
		LIS_tppLista Casas;

	} TAB_tpTabuleiro;


	TAB_tpCondRet TAB_CriarTabuleiro( void ( * ExcluirValor ) ( void * valor ), TAB_tppTabuleiro * tabuleiro ) 
	{

	}

	TAB_tpCondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro * tab ) 
	{

	}

	TAB_tpCondRet TAB_MovePeca( TAB_tppTabuleiro * tab, int origem, int destino ) 
	{

	}

	void ExcluirValor(void* pValor)
	{

		free(pValor);
	}
