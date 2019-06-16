/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico para dado
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
*	Versão		Autores		Data			Observações
*	3			elu			16/06/2019		Revisão Final
*	2			elu			02/05/2019		Criados casos de teste
*	1			elu			02/05/2019		Inicializado projeto
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

#include    "..\TST_ESPC.H"

#include    "..\GENERICO.H"
#include    "..\LERPARM.H"
#include    "..\Dado\DADO.H"

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
		int ValorObtido = 0 ;

		/* Testar DAD Jogar Dado */

			if ( strcmp( ComandoTeste , JOGAR_DAD_CMD ) == 0 )
			{

				DAD_JogarDado( &ValorObtido ) ;
				printf( "\n Resultado: %d", ValorObtido ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar DAD Jogar Dado */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TDAD Efetuar operações de teste específicas para dado */

/********** Fim do módulo de implementação: Módulo de teste específico para dado **********/

