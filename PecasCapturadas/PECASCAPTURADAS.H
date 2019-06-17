#if ! defined( PECASCAPTURADAS_ )
#define PECASCAPTURADAS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Peças Capturadas
*
*  Arquivo gerado:              PECASCAPTURADAS.H
*  Letras identificadoras:      BAR
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	3			elu			16/06/2019		Revisão Final
*	2			jpk			04/06/2019		Alguns ajustes em comentários
*	1			jpk			28/05/2019		Criação do Módulo
*
*  $ED Descrição do módulo
*			Este módulo contém a estrutura Peças Capturadas, que contém as peças capturadas
*			pretas e vermelhas.
*			Se pode criar e destruir a BAR, além de poder inserir e retirar peças
*			de uma das barras. Por fim também é possível contar a quantidade de peças 
*			em cada barra.
*
***************************************************************************/

#include "..\Cor\COR.H"
#if defined( PECASCAPTURADAS_OWN )
	#define PECASCAPTURADAS_EXT
#else
	#define PECASCAPTURADAS_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condições de retorno
*
*
***********************************************************************/

	typedef enum {

		BAR_CondRetOK = 0 ,
			/* Executou correto */

		BAR_CondRetBarNaoExiste = 1 ,
			/* BAR não existe */

		BAR_CondRetFaltouMemoria = 2 ,
			/* Faltou memória ao alocar dados */

		BAR_CondRetListaVazia = 3 ,
			/* A lista está vazia*/

	} BAR_tpCondRet ;


/***********************************************************************
*
*	$FC Função: BAR Criar Barra
*
*  $ED Descrição da função
*     Cria a barra de peças, que contém a barra preta e vermelha, para as
*     peças capturadas no jogo.
*     Caso já exista uma Barra, esta será destruída.
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetFaltouMemoria
*
*************************************************************************/

	BAR_tpCondRet BAR_CriarBarra( void ) ;


/*************************************************************************
*
*	$FC Função: BAR Destruir Barra
*
*  $ED Descrição da função
*     Remove e destroi as peças que foram capturadas e a Barra de 
*	  peças capturadas.
*     Faz nada caso a barra corrente não exista.
*
*************************************************************************/

	void BAR_DestruirBarra( void ) ;

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
*
*************************************************************************/

	BAR_tpCondRet BAR_InserePeca( CorPecas cor ) ;


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

	BAR_tpCondRet BAR_RemovePeca( CorPecas cor ) ;

/*************************************************************************
*
*	$FC Função: BAR Número de peças da barra
*
*  $ED Descrição da função
*     Pega o número de peças da barra da cor escolhida.
*
*	$EP Parâmetros:
*     $P cor - É a cor da barra escolhida para ver o número de peças
*     $P numPecas - é o parámetro que receberá o numero de peças por referência
*
*	$FV Valores de retorno:
*		- BAR_CondRetOK
*		- BAR_CondRetBarNaoExiste
*
*************************************************************************/

	BAR_tpCondRet BAR_NumPecas( CorPecas cor, int * numPecas );

#undef PECASCAPTURADAS_EXT

/********** Fim do módulo de definição: Módulo Peças Capturadas **********/

#else
#endif
