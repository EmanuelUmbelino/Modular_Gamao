#if ! defined( FIM_ )
#define FIM_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista de Peças Finalizadas
*
*  Arquivo gerado:              PECASFINALIZADAS.H
*  Letras identificadoras:      FIM
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1    	phs	  	29/05/2019     Criação do Módulo
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Peças Finalizadas(FIM)
*			que é uma lista duplamente encadeada genérica com cabeça.
*			Se pode criar e destruir uma FIM, além de poder inserir peças e contar-las em FIM.
*
***************************************************************************/
#include "..\Cor\COR.H"
#if defined( FIM_OWN )
#define FIM_EXT
#else
#define FIM_EXT extern
#endif

	typedef enum {

		FIM_CondRetOK = 0,
		/* Executou correto */

		FIM_CondRetFimNaoExiste = 1,
		/* FIM não existe */

		FIM_CondRetFaltouMemoria = 2,
		/* Faltou memória ao alocar dados */

		FIM_CondRetCasaNaoExiste = 3,
		/* Casa fornecida não existe */

	} FIM_tpCondRet;


/***********************************************************************
*
*	$FC Função: FIM Criar Lista de Peças Finalizadas
*
*  $ED Descrição da função
*     Cria a lista de peças que foram finalizadas durante 
*	  o jogo de gamão.
*     Caso já exista uma lista de peças finalizadas, esta será destruída.
*
*	$FV Valores de retorno:
*		- FIM_CondRetOK
*		- FIM_CondRetFaltouMemoria
*
*************************************************************************/

	FIM_tpCondRet FIM_CriarFinalizadas(void);


/*************************************************************************
*
*	$FC Função: FIM Destruir Lista de Peças Finalizadas
*
*  $ED Descrição da função
*     Remove e destroi as peças que foram finalizadas e a lista de 
*	  peças finalizadas.
*     Faz nada caso o tabuleiro corrente não exista.
*
*************************************************************************/

	void FIM_DestruirFinalizadas(void);

/*************************************************************************
*
*	$FC Função: FIM Insere Peça na Lista de Peças Finalizadas
*
*  $ED Descrição da função
*     Insere a peça da cor fornecida .
*
*	$EP Parâmetros:
*     $P cor - é a cor da peça a ser inserida
*
*	$FV Valores de retorno:
*		- FIM_CondRetOK
*		- FIM_CondRetTabNaoExiste
*		- FIM_CondRetFaltouMemoria
*
*************************************************************************/

	FIM_tpCondRet FIM_FinalizarPeca( CorPecas cor );

/*************************************************************************
*
*	$FC Função: FIM Quantidades de Peças na Lista de Peças Finalizadas
*
*  $ED Descrição da função
*     Conta a quantidade de peças finalizadas da cor fornecida e 
*     passa o valor por referência.
*
*	$EP Parâmetros:
*     $P cor - é a cor da peça a ser contada
*     $P QuantidadeFinalizada - número de peças
*
*	$FV Valores de retorno:
*		- FIM_CondRetOK
*		- FIM_CondRetFimNaoExiste
*
*************************************************************************/

	FIM_tpCondRet FIM_QuantidadeFinalizada( CorPecas cor, int * QuantidadeFinalizada );



#undef FIM_EXT
#else
#endif