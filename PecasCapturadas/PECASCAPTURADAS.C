/***************************************************************************
*  $MCI Módulo de implementação: Módulo BAR
*
*  Arquivo gerado:              BAR.C
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*    Versão	  Autores	 	   Data           Observações 
*      2		jpk	  		04/06/2019     Conserto da função de destruir a barra 
*      1		jpk	  		24/04/2019     Criação do módulo
*
***************************************************************************/

#include	<malloc.h>
#include 	<stdio.h>
#include	<stdlib.h>
#include "Lista/LISTA.H"
#include "Lista/PECA.H"
#define BAR_OWN
#include "PECASCAPTURADAS.H"
#undef BAR_OWN


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
		LIS_tppLista Vermelhas;
		LIS_tppLista Pretas;
		/* Ponteiros para as lista de peças capturadas*/

	} tpBarra;


/*****  Dados encapsulados no módulo  *****/

	static tpBarra* bar = NULL;
		/* Ponteiro para o tabuleiro */



		
/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: BAR Criar Barra de peças capturadas
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
	}/* Fim função: BAR Criar Barra de peças capturadas */


/***************************************************************************
*
*  Função: BAR Destruir Barra de peças capturadas
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

		LIS_EsvaziarLista(bar->Vermelhas);
		LIS_EsvaziarLista(bar->Pretas);

		LIS_DestruirLista(bar->Vermelhas);
		LIS_DestruirLista(bar->Pretas);
		free(bar);
		bar = NULL;
	} /* Fim função: BAR Destruir Barra de peças capturadas */


/***************************************************************************
*
*  Função: BAR Inserir peça na Barra de peças capturadas
*
***************************************************************************/

	BAR_tpCondRet BAR_InserePecaLista(CorPecas cor)
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
		
		if (cor == 0)   // peças pretas
		{
			*barra = bar->Pretas;
			LIS_InserirElementoAntes(*barra, peca);
			return BAR_CondRetOK;
		} /* if */
		else if (cor == 1)  // peças vermelhas
		{
			*barra = bar->Vermelhas;
			LIS_InserirElementoAntes(*barra, peca);
			return BAR_CondRetOK;
		} /* else if */

	}/* Fim função: BAR Inserir peça na Barra de peças capturadas */

/***************************************************************************
*
*  Função: BAR Remover peça na Barra de peças capturadas
*
***************************************************************************/

	BAR_tpCondRet BAR_RemovePecaLista(CorPecas cor)
	{
		LIS_tppLista* barra;
		int cond;
		
		if (cor == 0)
		{
			*barra = bar->Pretas;
		} /* if */
		else if (cor == 1)
		{
			*barra = bar->Vermelhas;
		} /* else if */
		
		cond = LIS_ExcluirElemento(*barra);			
		
		if (cond == LIS_CondRetListaVazia) {
			return BAR_CondRetListaVazia;
		} /* if */
		return BAR_CondRetOK;
	} /* Fim função: BAR Remover peça da Barra de peças capturadas */
