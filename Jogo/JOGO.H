#if ! defined( JOGO_ )
#define JOGO_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Jogo
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
*        4        phs      17/06/2019        Adição de telas de vitória e de opções de aceitar e recusar dobras
*	  	 	3    		elu	  	04/06/2019			
*	  	 	2   		elu	  	03/06/2019			Melhorado impressão do jogo
*      	1    		elu	  	03/06/2019			Criação do módulo 
*
*  $ED Descrição do módulo
*			Este módulo contém o jogo
*
***************************************************************************/

 
#if defined( JOGO_OWN )
   #define JOGO_EXT
#else
   #define JOGO_EXT extern
#endif


/*************************************************************************
*
*	$FC Função: JOG Iniciar Jogo
*
*  $ESE Assertivas de saída esperadas
*     - Execução do jogo finalizada.
*
*
*************************************************************************/

   void JOG_IniciarJogo( void ) ;

#undef JOGO_EXT

/********** Fim do módulo de definição: Jogo **********/

#else
#endif