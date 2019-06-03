/***************************************************************************
*  $MCI Módulo de implementação: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*						jpk - João Pedro Kalil
*						phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data        Observações
*      8				elu			01/05/2019     Especificações
*      7				elu			01/05/2019     Refeitas todas as funcoes, agora so existe um tabuleiro
*      6				elu			01/05/2019     Consertada funcao criar tabuleiro
*      5				elu			01/05/2019     Implementação das funcoes Insere/Remove Peça, numPecas
*																			 e corPeca da casa, alem da IrCasa
*      4			elu/jpk		24/04/2019     Definição das funções Insere/Remove Peça, numPecas
*																			 e corPeca da casa, alem da IrCasa
*      3			elu/jpk		24/04/2019     Implementação das funcoes criar e destruir tabuleiro
*      2				jpk	  	24/04/2019     Criação do módulo
*      1				elu	  	17/04/2019     Inicializado projeto
*
***************************************************************************/

	#include	<malloc.h>
	#include 	<stdio.h>
	#include	<stdlib.h>
	#include "PECA.H"
	#include "LISTA.H"
	#define TABULEIRO_OWN
	#include "TABULEIRO.H"
	#undef TABULEIRO_OWN


/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do tabuleiro
*
*
*  $ED Descrição do tipo
*     Descreve a organização do tabuleiro
*
***********************************************************************/

	typedef struct tgTabuleiro {
			LIS_tppLista Casas ;
					/* Ponteiro para a lista de Casas */

	} tpTabuleiro ;

/*****  Dados encapsulados no módulo  *****/

		static tpTabuleiro * tab = NULL ;
				/* Ponteiro para o tabuleiro */

/***** Protótipos das funções encapuladas no módulo *****/

	static TAB_tpCondRet ConfigInicial( ) ;

	static TAB_tpCondRet InsereNPecasCasa( int n, CorPecas cor, int nCasa ) ;

	static LIS_tppLista * PegarCasa( int nCasa ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: TAB Criar Tabuleiro
*  ****/

	TAB_tpCondRet TAB_CriarTabuleiro( void ) 
	{
		int cond, i ;
		LIS_tppLista * casa = NULL;
		if ( tab != NULL )
		{
			TAB_DestruirTabuleiro( ) ;
		} /* if */

		tab = ( tpTabuleiro * ) malloc ( sizeof ( tpTabuleiro ) ) ;
		if ( tab == NULL )
		{
			return TAB_CondRetFaltouMemoria ;
		} /* if */
		
		( tab )->Casas = LIS_CriarLista( LIS_DestruirLista ) ;
		if ( ( tab )->Casas == NULL )
		{
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		for ( i = 0; i < 24; i++ ) 
		{
			casa = LIS_CriarLista( PEC_DestruirPeca ) ;
			if ( casa == NULL )
			{
				return TAB_CondRetFaltouMemoria ;
			} /* if */

			LIS_InserirElementoApos( tab->Casas, casa ) ;
		} /* for */

		cond = ConfigInicial( ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		return TAB_CondRetOK ;
	} /* Fim função: TAB Criar Tabuleiro */

/***************************************************************************
*
*  Função: TAB Destruir Tabuleiro
*  ****/

	void TAB_DestruirTabuleiro( void ) 
	{
		LIS_tppLista * casa ;
		int numCasas, i ;

		if ( tab == NULL )
		{
			return ;
		} /* if */
		LIS_NumElemenLista( tab->Casas, &numCasas );
		for ( i = 0; i < numCasas; i ++ )
		{
			casa = PegarCasa ( i+1 ) ;
			LIS_EsvaziarLista ( casa ) ;
		} /* printf */
		LIS_EsvaziarLista( tab->Casas ) ;
		LIS_DestruirLista( tab->Casas ) ;

		free( tab ) ;
		tab = NULL ;
	} /* Fim função: TAB Destruir Tabuleiro */

/***************************************************************************
*
*  Função: TAB Insere Peça na Casa
*  ****/

	TAB_tpCondRet TAB_InserePecaCasa( int nCasa, CorPecas cor ) 
	{
		LIS_tppLista * casa ;
		PEC * peca ;

		if ( tab == NULL ) {
			return TAB_CondRetTabNaoExiste ;
		} /* if */
		PEC_CriarPeca( &peca, cor ) ;
		if ( peca == NULL ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		casa = PegarCasa ( nCasa ) ;
		if ( casa == NULL ) {
			return TAB_CondRetCasaNaoExiste ;
		} /* if */
		LIS_InserirElementoApos( casa, peca );
		return TAB_CondRetOK ;
	} /* Fim função: TAB Insere Peça na Casa */

/***************************************************************************
*
*  Função: TAB Remove Peça da Casa
*  ****/

	TAB_tpCondRet TAB_RemovePecaCasa( int nCasa ) 
	{
		LIS_tppLista * casa ;
		int cond ;

		if ( tab == NULL ) {
			return TAB_CondRetTabNaoExiste ;
		} /* if */

		casa = PegarCasa ( nCasa ) ;
		if ( casa == NULL ) {
			return TAB_CondRetCasaNaoExiste ;
		} /* if */
		cond = LIS_ExcluirElemento( casa ) ;

		if ( cond == LIS_CondRetListaVazia ) {
			return TAB_CondRetCasaVazia ;
		} /* if */
		return TAB_CondRetOK ;
	} /* Fim função: TAB Remove Peça da Casa */

/***************************************************************************
*
*  Função: TAB Num Peças da Casa
*  ****/

	TAB_tpCondRet TAB_NumPecasCasa( int nCasa, int * numPecas ) 
	{
		LIS_tppLista * casa ;

		if ( tab == NULL ) {
			return TAB_CondRetTabNaoExiste ;
		} /* if */

		casa = PegarCasa ( nCasa ) ;
		if ( casa == NULL ) {
			return TAB_CondRetCasaNaoExiste ;
		} /* if */

		LIS_NumElemenLista( casa, numPecas );
		return TAB_CondRetOK ;
	} /* Fim função: TAB Num Peças da Casa */

/***************************************************************************
*
*  Função: TAB Cor Peças da Casa
*  ****/

	TAB_tpCondRet TAB_CorPecasCasa( int nCasa, CorPecas * cor ) 
	{
		LIS_tppLista * casa ;
		PEC * peca ;
		int nPecas, cond ;

		if ( tab == NULL ) {
			return TAB_CondRetTabNaoExiste ;
		} /* if */

		casa = PegarCasa ( nCasa ) ;
		if ( casa == NULL ) {
			return TAB_CondRetCasaNaoExiste ;
		} /* if */

		peca = LIS_ObterValor( casa ) ;

		cond = PEC_ObterCor( peca, cor );
		if ( cond == PEC_CondRetPecNaoExiste ) {
			return TAB_CondRetCasaVazia ;
		} /* if */

		return TAB_CondRetOK ;
	} /* Fim função: TAB Cor Peças da Casa */


/*****  Código das funções encapsuladas no módulo  *****/

	
/***************************************************************************
*
*  $FC Função: TAB Configuração Inicial
*
*  $ED Descrição da função
*     Insere peças na configuração inicial de um tabuleiro de gamão.
*
*  $FV Valor retornado
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*  ****/
	
	TAB_tpCondRet ConfigInicial( void ) 
	{
		int cond ;

		if ( tab == NULL ) {
			return TAB_CondRetTabNaoExiste ;
		} /* if */
		cond = InsereNPecasCasa( 2, Preta, 1 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 5, Vermelha, 6 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 3, Vermelha, 8 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 5, Preta, 12 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 5, Vermelha, 13 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 3, Preta, 17 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 5, Preta, 19 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		cond = InsereNPecasCasa( 2, Vermelha, 24 ) ;
		if ( cond == TAB_CondRetFaltouMemoria ) {
			return TAB_CondRetFaltouMemoria ;
		} /* if */

		return TAB_CondRetOK ;
	} /* Fim função: TAB Configuração Inicial */

	
/***************************************************************************
*
*	$FC Função: TAB Insere N Peças na Casa
*
*  $ED Descrição da função
*     Insere n peças da cor fornecida na casa fornecida.
*	
*	 $EP Parâmetros:
*     $P n - é o número da peças para inserir
*     $P nCasa - é o número da casa escolhida para inserir
*     $P cor - é a cor da peça a ser inserida
*
*	 $FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*  ****/

	TAB_tpCondRet InsereNPecasCasa( int n, CorPecas cor, int nCasa ) 
	{
		int i, cond ;

		if ( tab == NULL ) {
			return TAB_CondRetTabNaoExiste ;
		} /* if */
		for ( i = 0; i < n; i++ ) 
		{
			cond = TAB_InserePecaCasa( nCasa, cor );
			if ( cond == TAB_CondRetFaltouMemoria ) {
				return TAB_CondRetFaltouMemoria ;
			} /* if */
			else if (cond == TAB_CondRetCasaNaoExiste ) {
				return TAB_CondRetCasaNaoExiste ;
			} /* else if */
		} /* for */
		return TAB_CondRetOK ;
	} /* Fim função: TAB Insere N Pecas na Casa */

	
/***************************************************************************
*
*  $FC Função: TAB Pegar Casa
*	
* $EAE Assertivas de entradas esperadas
*     tab != NULL
*
*	$EP Parâmetros:
*     $P nCasa - é o número da casa escolhida para pegar
*
*  $FV Valor retornado
*			Ponteiro para a casa escolhida.
*     Será NULL caso a casa não exista ( nCasa < 1 ou nCasa > 24 ).
*  ****/

	LIS_tppLista * PegarCasa( int nCasa ) 
	{
		if ( nCasa < 1 || nCasa > 24 ) {
			return NULL ;
		} /* if */

		IrInicioLista( tab->Casas ) ;
		LIS_AvancarElementoCorrente( tab->Casas , nCasa-1 ) ;

		return LIS_ObterValor( tab->Casas ) ;
	} /* Fim função: TAB Pegar Casa */
 

/********** Fim do módulo de implementação: Módulo Tabuleiro **********/