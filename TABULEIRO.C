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
*    Versão	  Autores		 	 Data        Observações
*      4			elu/jpk		24/04/2019     Funcoes Insere/Remove Peça, numPecas e corPeca da
*																			 casa, alem da IrCasa
*      3			elu/jpk		24/04/2019     Implementação das funcoes criar e destruir tabuleiro
*      2				jpk	  	24/04/2019     Criação do módulo
*      1				elu	  	17/04/2019     Inicializado projeto
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


	TAB_tpCondRet TAB_CriarTabuleiro( void ( * ExcluirValor ) ( void * valor ), TAB_tppTabuleiro * tab ) 
	{
		int numBrancas, numPretas, i ;
		

		*tab = ( TAB_tppTabuleiro * ) malloc ( sizeof ( TAB_tppTabuleiro ) ) ;
		( *tab )->Casas = LIS_CriarLista( ExcluirValor ) ; //Cria a cabeça da lista de casas

		for (i = 0; i < 24; i++) 
		{
			LIS_InserirElementoApos( ( *tab )->Casas, LIS_CriarLista( ExcluirValor ) ) ; //Cria as casas
		} /* for */
		printf("\nCRIADAS TODAS AS CASAS\n");
		
		IrInicioLista( ( *tab )->Casas ) ;
		TAB_InserePeca( tab );

	}

	void TAB_DestruirTabuleiro( TAB_tppTabuleiro * tab ) 
	{
		int numBrancas, numPretas, i ;
		LIS_tppLista * aux ;
		PEC * pecaAux ;

		if ( *tab == NULL )
		{
			return ;
		} /* if */

		while ( LIS_ObterValor( ( *tab )->Casas ) != NULL )
		{
			aux = LIS_ObterValor( ( *tab )->Casas ) ;
			while(LIS_ObterValor( aux ) != NULL) 
			{
				PEC_DestruirPeca( LIS_ObterValor( aux ) ) ;
				LIS_ExcluirElemento( aux ) ;
			} /* while */
			LIS_DestruirLista( aux ) ;
			
			LIS_ExcluirElemento( ( *tab )->Casas ) ;
		} /* while */
		LIS_DestruirLista( ( *tab )->Casas ) ;

		free( *tab ) ;
	}

	TAB_tpCondRet TAB_InserePeca( TAB_tppTabuleiro * tab ) 
	{
		LIS_tppLista * aux ;
		PEC * pecAux;
		int i;

		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 2; i++) 
		{
			pecAux = PEC_CriarPeca(Preta);
			LIS_InserirElementoApos( aux, pecAux );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 5 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 2 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 3; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 4 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 1 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 4 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 3; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 2 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 5; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Preta) );
		} /* for */
		
		LIS_AvancarElementoCorrente( ( *tab )->Casas , 5 ) ;
		aux = LIS_ObterValor( ( *tab )->Casas ) ;
		for (i = 0; i < 2; i++) 
		{
			LIS_InserirElementoApos( aux, PEC_CriarPeca(Vermelha) );
		} /* for */

		printf("\nINSERIDAS AS PEÇAS\n");
	}

	TAB_tpCondRet TAB_RemovePeca( TAB_tppTabuleiro * tab ) 
	{
		
	}

	TAB_tpCondRet TAB_NumPecas( TAB_tppTabuleiro * tab ) 
	{
		
	}

	TAB_tpCondRet TAB_CorPecas( TAB_tppTabuleiro * tab ) 
	{
		
	}

	TAB_tpCondRet TAB_IrCasa( TAB_tppTabuleiro * tab, int casa ) 
	{
		
	}

	//void ExcluirValor(void* pValor)
	//{
	//	free(pValor);
	//}
