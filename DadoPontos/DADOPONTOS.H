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
*     Versão   Autores	  Data           Observações
*		 4		jpk		10/06/2019	   Adição de setters
*	   	 3    	elu	  	01/05/2019     Revisão das funções
*	   	 2    	jpk	  	17/04/2019     Criação dos protótipos das funções
*		 1   	elu	  	17/04/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*			Este módulo contém a estrutura do dado de pontos.
*			Serve para saber o valor da partida, dobra-lo e saber quem pode dobrar
*			o valor da partida.
*			
*
********************************************************************************/

#include "COR.H"
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
* $EED Assertivas estruturais: Quando um jogador dobra os pontos, ele não 
* pode fazer uma outra dobra de pontos até que o outro jogador tenha feito.
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
*	$EC Descrição: Função que exibe o atual valor da partida
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
*	$EC Descrição: Função que exibe o jogador que pode dobrar
*	os pontos da atual partida
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	 DPT_tpCondRet DPT_QuemPodeDobrar ( CorPecas * jogador );


/*************************************************************************
*
*	$FC Função: DPT Set Quem Pode Dobrar
*
*	$EC Descrição: Função que seta o jogador que pode dobrar
*	os pontos da atual partida
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	 DPT_tpCondRet DPT_SetQuemPodeDobrar ( CorPecas * jogador );

/*************************************************************************
*
*	$FC Função: DPT Set Valor da Partida
*
*	$EC Descrição: Função que Seta o atual valor da partida
*
*	$FV Valores de retorno:
*		- DPT_CondRetOK
*		- DPT_CondRetDPTNaoExiste
*
*************************************************************************/

	 DPT_tpCondRet DPT_SetValorPartida ( int * valor ) ;

#undef DPT_EXT

/********** Fim do módulo de definição: Módulo Dado de Pontos **********/

#else
#endif