/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTDAD.C
*  Letras identificadoras:      TDAD
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data        Observações
*      2				elu	  	02/05/2019     Criados casos de teste
*      1				elu	  	02/05/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo dado. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo dado:
*
*     "=jogar"        - chama a função DAD_JogarDados( valorRetornado )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"
#include    "dado.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     JOGAR_DAD_CMD       "=jogar"


/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDAD Efetuar operações de teste específicas para dado
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     dado ir sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

	TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
	{

		DAD_tpCondRet CondRetObtido   = DAD_CondRetOK ;
		DAD_tpCondRet CondRetEsperada = DAD_CondRetOK ;
												  /* inicializa para qualquer coisa */
		int ValorObtido = 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar DAD Jogar Dado */

			if ( strcmp( ComandoTeste , JOGAR_DAD_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = DAD_JogarDado( &ValorObtido ) ;
				printf( "\n Resultado: %d", ValorObtido ) ;
				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao jogar dado." ) ;

			} /* fim ativa: Testar DAD Jogar Dado */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TDAD Efetuar operações de teste específicas para dado */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

