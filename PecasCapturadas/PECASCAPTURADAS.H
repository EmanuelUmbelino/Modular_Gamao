#if ! defined( BAR_ )
#define BAR_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo BAR
*
*  Arquivo gerado:              BAR.H
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo Gam�o via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - Jo�o Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Hist�rico de evolu��o:
*     Vers�o   Autores	  Data           Observa��es
*      1    	jpk	  	28/05/2019     Cria��o do M�dulo
*
*  $ED Descri��o do m�dulo
*			Este m�dulo cont�m o tipo abstrato de dados da estrutura Pe�as capturadas(BAR)
*			que � uma lista duplamente encadeada  gen�rica com cabe�a.
*			Se pode criar e destruir uma BAR, al�m de poder inserir e retirar pe�as da BAR.
*
***************************************************************************/
#include "../../../../../../../Projects/Modular_Gamao/COR.H"
#if defined( BAR_OWN )
#define BAR_EXT
#else
#define BAR_EXT extern
#endif

	typedef enum {

		BAR_CondRetOK = 0,
		/* Executou correto */

		BAR_CondRetBarNaoExiste = 1,
		/* BAR n�o existe */

		BAR_CondRetFaltouMemoria = 2,
		/* Faltou mem�ria ao alocar dados */

		BAR_CondRetCasaNaoExiste = 3,
		/* Casa fornecida n�o existe */

		BAR_CondRetCasaVazia = 4,
		/* A casa est� vazia*/

	} BAR_tpCondRet;


/***********************************************************************
*
*	$FC Fun��o: BAR Criar Barra
*
*  $ED Descri��o da fun��o
*     Cria a barra de pe�as que podem ser capturadas durante 
*	  o jogo de gam�o.
*     Caso j� exista uma Barra, esta ser� destru�da.
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetFaltouMemoria
*
*************************************************************************/

	BAR_tpCondRet BAR_CriarBarra(void);


/*************************************************************************
*
*	$FC Fun��o: BAR Destruir Barra
*
*  $ED Descri��o da fun��o
*     Remove e destroi as pe�as que foram capturadas e a Barra de 
*	  pe�as capturadas.
*     Faz nada caso o tabuleiro corrente n�o exista.
*
*************************************************************************/

	void BAR_DestruirBarra(void);

/*************************************************************************
*
*	$FC Fun��o: BAR Insere Pe�a na Barra
*
*  $ED Descri��o da fun��o
*     Insere a pe�a da cor fornecida .
*
*	$EP Par�metros:
*     $P cor - � a cor da pe�a a ser inserida
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetTabNaoExiste
*		- BAR_CondRetFaltouMemoria
*		- BAR_CondRetCasaNaoExiste
*
*************************************************************************/

	BAR_tpCondRet BAR_InserePecaCasa( CorPecas cor );


/*************************************************************************
*
*	$FC Fun��o: BAR Remove Pe�a da Barra
*
*  $ED Descri��o da fun��o
*     Remove a pe�a da Barra
*     Faz nada se a barra estiver vazia.
*
*	$EP Par�metros:
*     $P cor - � a cor da pe�a a ser inserida
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetTabNaoExiste
*		- BAR_CondRetCasaVazia
*		- BAR_CondRetCasaNaoExiste
*
*************************************************************************/

	BAR_tpCondRet BAR_RemovePecaCasa( CorPecas cor );


#undef BAR_EXT
#else
#endif