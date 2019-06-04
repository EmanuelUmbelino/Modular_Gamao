#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Peça
*
*  Arquivo gerado:              PECA.H
*  Letras identificadoras:      PEC
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      3    		elu	  	01/05/2019     Adaptacoes modulo cor e condicoes de retorno
*      2    		elu	  	27/04/2019     Criadas funções de criar, destruir e obter cor
*      1    		elu	  	17/04/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Peça.
*			Se pode criar e destruir uma peça, além de obter a cor da peça.
*
***************************************************************************/

#include   "COR.H"
#if defined( PECA_OWN )
   #define PECA_EXT
#else
   #define PECA_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: PEC Condições de retorno
*
*
***********************************************************************/

   typedef enum {

         PEC_CondRetOK = 0 ,
               /* Executou correto */

         PEC_CondRetPecNaoExiste = 1 ,
               /* Peça não existe */

         PEC_CondRetFaltouMemoria = 2 ,
               /* Faltou memória ao alocar dados */

   } PEC_tpCondRet ;
	

/***********************************************************************
*
*  $TC Tipo de dados: PEC Descritor da peça
*
*
*  $ED Descrição do tipo
*     Descreve uma peça
*
***********************************************************************/

		 typedef struct peca PEC ;

/***********************************************************************
*
*  $FC Função: PEC Criar Peça
*
*  $ED Descrição da função
*     Cria uma nova peça com a cor escolhida.
*	
*	$EP Parâmetros:
*     $P peça - É o parámetro que receberá a peça criada por referencia
*     $P cor - É a cor escolhida para criar a peça
*
*  $FV Valor retornado
*		- PEC_CondRetOK
*		- PEC_CondRetFaltouMemoria
*
***********************************************************************/

   PEC_tpCondRet PEC_CriarPeca( PEC ** peca, CorPecas cor ) ;


/***********************************************************************
*
*  $FC Função: PEC Obter Cor
*
*  $ED Descrição da função
*     Obtem a cor de uma peça.
*
*  $EP Parâmetros
*     $P peca - É o ponteiro para a peça que quer obter cor
*     $P cor - É o parámetro que receberá a cor da peça por referencia
*
*  $FV Valor retornado
*		- PEC_CondRetOK
*		- PEC_CondRetPecNaoExiste
*
***********************************************************************/

   PEC_tpCondRet PEC_ObterCor( PEC * peca, CorPecas * cor )  ;


/***********************************************************************
*
*  $FC Função: PEC Destruir Peça
*
*  $ED Descrição da função
*     Destrói peça.
*
*  $EP Parâmetros
*     $P peca - É o ponteiro para a peça que quer destruir
*
***********************************************************************/

   void PEC_DestruirPeca( PEC * peca ) ;

	 
#undef PECA_EXT

/********** Fim do módulo de definição: Módulo Peça **********/

#else
#endif