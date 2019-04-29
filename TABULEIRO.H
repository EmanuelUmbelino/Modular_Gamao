#pragma once
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.H
*  Letras identificadoras:      TAB
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.00    elu	  	17/04/2019     Inicializado projeto
*	   1.00    jpk	  	24/04/2019     Criação do módulo 
*
*  $ED Descrição do módulo
*			Este módulo contém a estrutura do Tabuleiro.
*			Se pode criar e visualizar o tabuleiro, além de 
*			movimentar uma peça entre as casas.
*
***************************************************************************/
 

	typedef struct TAB_Tabuleiro * TAB_tppTabuleiro;


/***********************************************************************
*
*  Tipo de dados: Condições de retorno TAB
*
***********************************************************************/

	typedef enum
	{

		TAB_CondRetOk = 0  /* EXECUÇÃO CORRETA */,

		TAB_CondRetNok = 1 /* OCORREU ERRO NA EXECUÇÃO  */,

		TAB_CondRetMemoryLess = 2 /* NÃO CONSEGUIU ALOCAR MEMÓRIA */,

		TAB_CondRetNonexistent = 3 /* ESTRUTURA NÃO CRIADA */

	} TAB_tpCondRet ;



/*************************************************************************
*
*	$FC Função: TAB Cria tabuleiro
*
*	$EC Descrição: Função que cria o tabuleiro da partida
*	
*	$EP Parâmetros:
*		- Endereço do tabuleiro
*		- ponteiro para a função que processa a
*         exclusão do valor referenciado pelo elemento
*		  a ser excluído.
*
*	$FV Valores de retorno:
*		- TAB_CondRetOk
*		- TAB_CondRetMemoryLess
*
*************************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro( void ( * ExcluirValor ) ( void * valor ), TAB_tppTabuleiro * tabuleiro ) ;


/*************************************************************************
*
*	$FC Função: TAB Destroi Tabuleiro
*
*	$EC Descrição: Função que destroi o tabuleiro da partida
*
*	$FV Valores de retorno:
*		- TAB_CondRetOk
*		- TAB_CondRetNonexistent
*		- TAB_CondRetMemoryLess
*
*************************************************************************/

   TAB_tpCondRet TAB_DestruirTabuleiro( TAB_tppTabuleiro * tab ) ;


/*************************************************************************
*
*	$FC Função: TAB Mover peças do tabuleiro
*
*	$EC Descrição: Função que move as peças existentes no tabuleiro
*
*	$FV Valores de retorno:
*		- TAB_CondRetOk
*		- TAB_CondRetNonexistent
*		- TAB_CondRetNok
*
*************************************************************************/

 TAB_tpCondRet TAB_MovePeca( TAB_tppTabuleiro * tab, int origem, int destino ) ;


