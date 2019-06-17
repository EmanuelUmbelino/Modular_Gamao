#if ! defined( PECASFINALIZADAS_ )
#define PECASFINALIZADAS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Peças Finalizadas
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
*	Versão		Autores		Data			Observações
*	2			elu			16/06/2019		Revisão Final
*	1			phs			29/05/2019		Criação do Módulo
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Peças Finalizadas, que contém as peças finalizadas
*			pretas e vermelhas.
*			Se pode criar e destruir a FIM, além de poder inserir peças
*			em uma das listas. Por fim também é possível contar a quantidade de peças 
*			em cada lista.
*
***************************************************************************/

#include "..\Cor\COR.H"
#if defined( PECASFINALIZADAS_OWN )
	#define PECASFINALIZADAS_EXT
#else
	#define PECASFINALIZADAS_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: FIM Condições de retorno
*
*
***********************************************************************/

	typedef enum {

		FIM_CondRetOK = 0,
			/* Executou correto */

		FIM_CondRetFimNaoExiste = 1,
			/* FIM não existe */

		FIM_CondRetFaltouMemoria = 2,
			/* Faltou memória ao alocar dados */

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

	FIM_tpCondRet FIM_CriarFinalizadas( void ) ;

/*************************************************************************
*
*	$FC Função: FIM Destruir Lista de Peças Finalizadas
*
*  $ED Descrição da função
*     Remove e destroi as peças que foram finalizadas e a lista de 
*	  peças finalizadas.
*     Faz nada caso o lista corrente não exista.
*
*************************************************************************/

	void FIM_DestruirFinalizadas( void ) ;

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
*		- FIM_CondRetFimNaoExiste
*		- FIM_CondRetFaltouMemoria
*
*************************************************************************/

	FIM_tpCondRet FIM_FinalizarPeca( CorPecas cor ) ;

/*************************************************************************
*
*	$FC Função: FIM Numero de Peças na Lista de Peças Finalizadas
*
*  $ED Descrição da função
*     Conta a quantidade de peças finalizadas da cor fornecida e 
*     passa o valor por referência.
*
*	$EP Parâmetros:
*     $P cor - É a cor da barra escolhida para ver o número de peças
*     $P numPecas - é o parámetro que receberá o numero de peças por referência
*
*	$FV Valores de retorno:
*		- FIM_CondRetOK
*		- FIM_CondRetFimNaoExiste
*
*************************************************************************/

	FIM_tpCondRet FIM_NumPecas( CorPecas cor, int * numPecas ) ;



#undef PECASFINALIZADAS_EXT

/********** Fim do módulo de definição: Módulo Peças Finalizadas **********/

#else
#endif