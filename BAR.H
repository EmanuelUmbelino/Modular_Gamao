#if ! defined( BAR_ )
#define BAR_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo BAR
*
*  Arquivo gerado:              BAR.H
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1    	jpk	  	28/05/2019     Criação do Módulo
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Peças capturadas(BAR)
*			que é uma lista duplamente encadeada  genérica com cabeça.
*			Se pode criar e destruir uma BAR, além de poder inserir e retirar peças da BAR.
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
		/* BAR não existe */

		BAR_CondRetFaltouMemoria = 2,
		/* Faltou memória ao alocar dados */

		BAR_CondRetCasaNaoExiste = 3,
		/* Casa fornecida não existe */

		BAR_CondRetCasaVazia = 4,
		/* A casa está vazia*/

	} BAR_tpCondRet;


/***********************************************************************
*
*	$FC Função: BAR Criar Barra
*
*  $ED Descrição da função
*     Cria a barra de peças que podem ser capturadas durante 
*	  o jogo de gamão.
*     Caso já exista uma Barra, esta será destruída.
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetFaltouMemoria
*
*************************************************************************/

	BAR_tpCondRet BAR_CriarBarra(void);


/*************************************************************************
*
*	$FC Função: BAR Destruir Barra
*
*  $ED Descrição da função
*     Remove e destroi as peças que foram capturadas e a Barra de 
*	  peças capturadas.
*     Faz nada caso o tabuleiro corrente não exista.
*
*************************************************************************/

	void BAR_DestruirBarra(void);

/*************************************************************************
*
*	$FC Função: BAR Insere Peça na Barra
*
*  $ED Descrição da função
*     Insere a peça da cor fornecida .
*
*	$EP Parâmetros:
*     $P cor - é a cor da peça a ser inserida
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
*	$FC Função: BAR Remove Peça da Barra
*
*  $ED Descrição da função
*     Remove a peça da Barra
*     Faz nada se a barra estiver vazia.
*
*	$EP Parâmetros:
*     $P cor - é a cor da peça a ser inserida
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