/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo BAR
*
*  Arquivo gerado:              BAR.C
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo Gam�o via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - Jo�o Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Hist�rico de evolu��o:
*    Vers�o	  Autores	 	   Data           Observa��es 
*      2		jpk	  		24/04/2019     Cria��o do m�dulo
*      1		jpk	  		24/04/2019     Cria��o do m�dulo
*
***************************************************************************/

#include	<malloc.h>
#include 	<stdio.h>
#include	<stdlib.h>
#include "../../../../../../../Projects/Modular_Gamao/LISTA.H"
#include "../../../../../../../Projects/Modular_Gamao/PECA.H"
#define BAR_OWN
#include "BAR.H"
#undef BAR_OWN


/***********************************************************************
*
*  $TC Tipo de dados: BAR Descritor da Barra de pe�as capturadas
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o da Barra de pe�as capturadas
*
***********************************************************************/

	typedef struct tgBarra {
		LIS_tppLista Vermelhas;
		LIS_tppLista Pretas;
		/* Ponteiros para as lista de pe�as capturadas*/

	} tpBarra;


/*****  Dados encapsulados no m�dulo  *****/

	static tpBarra* bar = NULL;
		/* Ponteiro para o tabuleiro */



		
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: BAR Criar Barra de pe�as capturadas
*
***************************************************************************/

	BAR_tpCondRet BAR_CriarBarra(void)
	{
		int i;
		LIS_tppLista* casa = NULL;
		bar = (tpBarra*)malloc(sizeof(tpBarra));
		if (bar == NULL)
		{
			return BAR_CondRetFaltouMemoria;
		} /* if */

		(bar)->Vermelhas = LIS_CriarLista(LIS_DestruirLista);
		(bar)->Pretas = LIS_CriarLista(LIS_DestruirLista);
		if ((bar)->Vermelhas == NULL || (bar)->Pretas == NULL)
		{
			return BAR_CondRetFaltouMemoria;
		} /* if */

		return BAR_CondRetOK;
	}/* Fim fun��o: BAR Criar Barra de pe�as capturadas */


/***************************************************************************
*
*  Fun��o: BAR Destruir Barra de pe�as capturadas
*
***************************************************************************/

	void BAR_DestruirBarra(void)
	{
		int i , numCasas;
		LIS_tppLista* capturadas;

		if (bar == NULL)
		{
			return;
		} /* if */

		LIS_NumElemenLista(bar->Vermelhas, &numCasas);
		for (i = 0; i < numCasas; i++)
		{
			LIS_EsvaziarLista(bar->Vermelhas);
		} /* for */

		LIS_NumElemenLista(bar->Pretas, &numCasas);
		for (i = 0; i < numCasas; i++)
		{
			LIS_EsvaziarLista(bar->Pretas);
		} /* for */

		LIS_DestruirLista(bar->Vermelhas);
		LIS_DestruirLista(bar->Pretas);
		free(bar);
		bar = NULL;
	} /* Fim fun��o: BAR Destruir Barra de pe�as capturadas */


/***************************************************************************
*
*  Fun��o: BAR Inserir pe�a na Barra de pe�as capturadas
*
***************************************************************************/

	BAR_tpCondRet BAR_InserePecaCasa(CorPecas cor)
	{
		LIS_tppLista* barra ;
		PEC* peca;

		if (bar == NULL) {
			return BAR_CondRetBarNaoExiste;
		} /* if */

		PEC_CriarPeca(&peca, cor);
		
		if (peca == NULL) {
			return BAR_CondRetFaltouMemoria;
		} /* if */
		
		if (cor == 0)   // pe�as pretas
		{
			barra = bar->Pretas;
			LIS_InserirElementoAntes(barra, peca);
			return BAR_CondRetOK;
		} /* if */
		else if (cor == 1)  // pe�as vermelhas
		{
			barra = bar->Vermelhas;
			LIS_InserirElementoAntes(barra, peca);
			return BAR_CondRetOK;
		} /* else if */

	}/* Fim fun��o: BAR Inserir pe�a na Barra de pe�as capturadas */

/***************************************************************************
*
*  Fun��o: BAR Remover pe�a na Barra de pe�as capturadas
*
***************************************************************************/

	BAR_tpCondRet BAR_RemovePecaCasa(CorPecas cor)
	{
		LIS_tppLista* barra;
		int cond;
		
		if (cor == 0)
		{
			barra = bar->Pretas;
		} /* if */
		else if (cor == 1)
		{
			barra = bar->Vermelhas;
		} /* else if */
		
		cond = LIS_ExcluirElemento(barra);			
		
		if (cond == LIS_CondRetListaVazia) {
			return BAR_CondRetCasaVazia;
		} /* if */
		return BAR_CondRetOK;
	} /* Fim fun��o: BAR Remover pe�a da Barra de pe�as capturadas */