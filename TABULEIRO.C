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
*      1.05    elu/jpk	24/04/2019     Implementação da funcao criar tabuleiro
*      1.01    jpk	  	24/04/2019     Criação do módulo
*      1.00    elu	  	17/04/2019     Inicializado projeto
*
***************************************************************************/

	#include "PECA.H"
	#include "LISTA.H"
	#include "TABULEIRO.H"
	#include <stdio.h>
	#include <stdlib.h>

	struct TAB_Tabuleiro
	{
		LIS_tppLista Casas ;

	} TAB_tpTabuleiro ;


	TAB_tpCondRet TAB_CriarTabuleiro( void ( * ExcluirValor ) ( void * valor ), TAB_tppTabuleiro * tabuleiro ) 
	{
		int numBrancas, numPretas, i ;
		LIS_tppLista * aux ;

		numBrancas = 15 ;
		numPretas = 15 ;

		tabuleiro = ( TAB_tppTabuleiro * ) malloc ( sizeof ( TAB_tppTabuleiro ) ) ;
		( *tabuleiro )->Casas = LIS_CriarLista( ExcluirValor ) ;

		for (i = 0; i < 24; i++) 
		{
			LIS_InserirElementoApos( ( *tabuleiro )->Casas, LIS_CriarLista( ExcluirValor ) ) ;
		}
		printf("\nCRIADAS TODAS AS CASAS\n");
		IrInicioLista( ( *tabuleiro )->Casas ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 2; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 5 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 2 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 3; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 4 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 1 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 4 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 3; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 2 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		}
		
		LIS_AvancarElementoCorrente( ( *tabuleiro )->Casas , 5 ) ;
		aux = LIS_ObterValor( ( *tabuleiro )->Casas ) ;
		for (i = 0; i < 2; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		}
		printf("\nINSERIDAS AS PEÇAS\n");

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
