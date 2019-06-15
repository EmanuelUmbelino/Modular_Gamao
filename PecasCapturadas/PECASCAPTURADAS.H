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
*      2    	jpk	  	04/06/2019     Alguns ajustes em comentários
*      1    	jpk	  	28/05/2019     Criação do Módulo
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Peças capturadas(BAR)
*			que é uma lista duplamente encadeada  genérica com cabeça.
*			Se pode criar e destruir uma BAR, além de poder inserir e retirar peças da BAR.
*
***************************************************************************/
#include "../cor/COR.H"
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

		BAR_CondRetListaVazia = 3,
		/* A lista está vazia*/

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
*		- BAR_CondRetBarNaoExiste
*		- BAR_CondRetFaltouMemoria
*		- BAR_CondRetListaNaoExiste
*
*************************************************************************/

	BAR_tpCondRet BAR_InserePeca( CorPecas cor );


/*************************************************************************
*
*	$FC Função: BAR Remove Peça da Barra
*
*  $ED Descrição da função
*     Remove a peça da Barra
*     Faz nada se a barra estiver vazia.
*
*	$EP Parâmetros:
*     $P cor - é a cor da peça a ser removida
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetBarNaoExiste
*		- BAR_CondRetListaVazia
*
*************************************************************************/

	BAR_tpCondRet BAR_RemovePeca( CorPecas cor );

/*************************************************************************
*
*	$FC Função: BAR Número de peças das filas que tem na barra
*
*  $ED Descrição da função
*     Conta o número de peças de cada lista da barra
*
*	$EP Parâmetros:
*     $P numPecas - é onde o número de pecas de cada casa será
*	  retornado.
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetBarNaoExiste
*
*************************************************************************/

	BAR_tpCondRet BAR_NumPecas( CorPecas cor, int * numPecas );

#undef BAR_EXT
#else
#endif
