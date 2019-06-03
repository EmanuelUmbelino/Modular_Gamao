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
*     Versão  Autor    Data      	Observações
*     	2	     elu   02/05/2019 	Feita função de jogar dado
*     	1      phs   18/04/2019 	Início do desenvolvimento
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
*  $TC Tipo de dados: DAD Condições de retorno
*
*
***********************************************************************/

   typedef enum {

         DAD_CondRetOK = 0 ,
               /* Executou correto */

   } DAD_tpCondRet ;

/***********************************************************************
*
*  $FC Função: DAD Jogar Dado
*
*  $ED Descrição da função
*     Sorteia um valor de 1 a 6 e retorna por referencia.
*
*  $EP Parâmetros
*     $P cor - É o parámetro que receberá o valor do dado por referencia
*
*  $FV Valor retornado
*		- PEC_CondRetOK
*		- PEC_CondRetPecNaoExiste
*
***********************************************************************/

DAD_tpCondRet DAD_JogarDado( int * valor ) ;

	 
#undef Dado_EXT

/********** Fim do módulo de definição: Módulo Dado **********/

#else
#endif