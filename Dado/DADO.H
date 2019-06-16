#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*  $MCI Módulo de definição: Dado
*
*  Arquivo gerado:              DADO.H
*  Letras identificadoras:      DAD
*
*  Projeto: INF 1301 	Projeto jogo gamão via terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	3			elu			16/06/2019		Revisão Final
*	2			elu			02/05/2019		Feita função de jogar dado
*	1			elu			18/04/2019		Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa a função do dado, que é sortear um 
*     valor de 1 a 6. 
*
***************************************************************************/

#if defined( DADO_OWN )
	#define DADO_EXT
#else
	#define DADO_EXT extern
#endif

/***********************************************************************
*
*  $FC Função: DAD Jogar Dado
*
*  $ED Descrição da função
*     Sorteia um valor de 1 a 6 e retorna por referência.
*
*  $EP Parâmetros
*     $P valor - É o parámetro que receberá o valor do dado por referência
*
***********************************************************************/

	void DAD_JogarDado( int * valor ) ;

#undef DADO_EXT

/********** Fim do módulo de definição: Módulo Dado **********/

#else
#endif