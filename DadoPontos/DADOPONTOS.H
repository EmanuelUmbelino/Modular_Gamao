#if ! defined( DPT_ )
#define DPT_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Dado de Pontos
*
*  Arquivo gerado:              DADOPONTOS.H
*  Letras identificadoras:      DPT
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	5			elu			16/06/2019		Revisão Final
*	4			jpk			10/06/2019		Adição de setters
*	3			elu			01/05/2019		Revisão das funções
*	2			jpk			17/04/2019		Criação dos protótipos das funções
*	1			elu			17/04/2019		Inicializado projeto
*
*  $ED Descrição do módulo
*			Este módulo contém a estrutura do dado de pontos.
*			Serve para saber o valor da partida, dobra-lo e saber quem pode dobrar
*			o valor da partida.
*			
*
********************************************************************************/

#include "..\Cor\COR.H"
#if defined( DPT_OWN )
   #define DPT_EXT
#else
   #define DPT_EXT extern
#endif

/*************************************************************************
*
*  $TC Tipo de dados: DPT Condições de retorno
*
*
*************************************************************************/

	typedef enum {

		DPT_CondRetOK = 0 ,
			/* Executou correto */

		DPT_NaoPodeDobrar = 1 ,
			/* Jogador escolhido nao pode dobrar */

		DPT_CondRetFaltouMemoria = 2 ,
			/* Faltou memória ao alocar dados */

		DPT_CondRetDPTNaoExiste = 3 ,
			/* DPT não existe */

	} DPT_tpCondRet ;


/*************************************************************************
*
*	$FC Função: DPT Criar dado de pontos
*
*	$EC Descrição: Função que cria o dado de apostas que drobram os 
*	pontos de uma partida.
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetFaltouMemoria
*
*************************************************************************/

	DPT_tpCondRet DPT_CriarDadoPontos ( void ) ;


/*************************************************************************
*
*	$FC Função: DPT Dobra pontos da partida
*
*	$EC Descrição: Função que, ao executada, dobra os pontos
*	da partida em andamento. 
*
*	$EED Assertivas estruturais: Quando um jogador dobra os pontos, ele não 
*	pode fazer uma outra dobra de pontos até que o outro jogador tenha feito.
*
*	$EP Parâmetros:
*     $P jogador - é a cor do jogador que efetuará a dobra
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_NaoPodeDobrar
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	DPT_tpCondRet DPT_DobraPontos ( CorPecas jogador ) ;


/*************************************************************************
*
*	$FC Função: DPT Destruir dado de pontos
*
*	$EC Descrição: Função que destroi o dado de apostas.
*
*************************************************************************/

	void DPT_DestruirDadoPontos ( void ) ;


/*************************************************************************
*
*	$FC Função: DPT Valor da Partida
*
*	$EP Parâmetros:
*     $P valor - é o valor da partida passado por referência
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	DPT_tpCondRet DPT_ValorPartida ( int * valor ) ;

/*************************************************************************
*
*	$FC Função: DPT Quem Pode Dobrar
*
*	$EP Parâmetros:
*     $P jogador - é a cor do jogador que pode efetuar uma dobra
*                    passado por referência
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	DPT_tpCondRet DPT_QuemPodeDobrar ( CorPecas * jogador ) ;


/*************************************************************************
*
*	$FC Função: DPT Carrega Dado Pontos
*
*  $EP Parâmetros
*     $P jogador - cor do jogador atual
*     $P valor - valor atual da partida
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	DPT_tpCondRet DPT_CarregaDadoPontos ( CorPecas jogador, int valor ) ;

#undef DPT_EXT

/********** Fim do módulo de definição: Módulo Dado de Pontos **********/

#else
#endif