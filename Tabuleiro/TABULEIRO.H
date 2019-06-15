#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data					Observações
*	  	 	3    		elu	  	01/05/2019			Implementação de funções e especificações
*	  	 	2   		jpk	  	24/04/2019			Criação do módulo 
*      	1    		elu	  	17/04/2019			Inicializado projeto
*
*  $ED Descrição do módulo
*			Este módulo contém a estrutura do Tabuleiro.
*			Se pode criar o tabuleiro, além de inserir e retirar uma peça de 
*			uma casa. Também é possível saber o número e as cores das peças de uma casa.
*
***************************************************************************/

#include "..\cor\COR.H"
#if defined( TABULEIRO_OWN )
   #define TABULEIRO_EXT
#else
   #define TABULEIRO_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condições de retorno
*
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK = 0 ,
               /* Executou correto */

         TAB_CondRetTabNaoExiste = 1 ,
               /* Tabuleiro não existe */

         TAB_CondRetFaltouMemoria = 2 ,
               /* Faltou memória ao alocar dados */

         TAB_CondRetCasaNaoExiste = 3 ,
               /* Casa fornecida não existe */

         TAB_CondRetCasaVazia = 4 ,
               /* A casa está vazia*/

   } TAB_tpCondRet ;


/***********************************************************************
*
*	$FC Função: TAB Criar tabuleiro
*
*  $ED Descrição da função
*     Cria um novo tabuleiro de gamão, com 24 casas, com peças
*     na posição inicial do jogo de gamão.
*     Caso já exista uma tabuleiro, este será destruído.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetFaltouMemoria
*
*************************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro( void ) ;


/*************************************************************************
*
*	$FC Função: TAB Destruir Tabuleiro
*
*  $ED Descrição da função
*     Remove e destroi as peças, destroi as casas e o tabuleiro corrente.
*     Faz nada caso o tabuleiro corrente não exista.
*
*************************************************************************/

   void TAB_DestruirTabuleiro( void ) ;


/*************************************************************************
*
*	$FC Função: TAB Insere Peça na Casa
*
*  $ED Descrição da função
*     Insere a peça da cor fornecida na casa fornecida.
*	
*	$EP Parâmetros:
*     $P nCasa - é o número da casa escolhida para inserir
*     $P cor - é a cor da peça a ser inserida
*
*  $EAE Assertivas de entradas esperadas
*     Se tiver peças na casa: cor == TAB_CorPecasCasa( nCasa )
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetFaltouMemoria
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_InserePecaCasa( int nCasa, CorPecas cor ) ;


/*************************************************************************
*
*	$FC Função: TAB Remove Peça da Casa
*
*  $ED Descrição da função
*     Remove a peça da casa fornecida.
*     Faz nada se casa estiver vazia.
*	
*	$EP Parâmetros:
*     $P nCasa - é o número da casa escolhida para inserir
*     $P cor - é a cor da peça a ser inserida
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetCasaVazia
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_RemovePecaCasa( int nCasa ) ;


/*************************************************************************
*
*	$FC Função: TAB Num Peças da Casa
*
*  $EP Parâmetros
*     $P casa - é o número da casa escolhida para ver o número de peças
*     $P numPecas - É o parámetro que receberá o número de peças
*                    da casa escolhida.
*                    Este parámetro é passado por referência.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_NumPecasCasa( int nCasa, int * numPecas ) ;


/*************************************************************************
*
*	$FC Função: TAB Cor Peças da Casa
*
*  $EP Parâmetros
*     $P casa - é o número da casa escolhida para ver a cor das peças
*     $P numPecas - É o parámetro que receberá a cor das peças
*                    da casa escolhida.
*                    Este parámetro é passado por referência.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOK
*		- TAB_CondRetTabNaoExiste
*		- TAB_CondRetCasaVazia
*		- TAB_CondRetCasaNaoExiste
*
*************************************************************************/

   TAB_tpCondRet TAB_CorPecasCasa( int nCasa, CorPecas * cor ) ;

#undef TABULEIRO_EXT

/********** Fim do módulo de definição: Módulo Tabuleiro **********/

#else
#endif