/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico para dado de pontos
*
*  Arquivo gerado:              TESTDPT.C
*  Letras identificadoras:      TDPT
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	3			elu			16/06/2019		Revisão Final
*	2			elu			01/05/2019		Criados casos de teste
*	1			elu			01/05/2019		Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo dado de pontos. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo dado de pontos:
*
*     "=criar"        - chama a função DPT_CriarDadoPontos(  )
*     "=dobra <CorPecas> "
*                     - chama a função DPT_DobraPontos( <CorPecas> )
*                     Obs. notação: <CorPecas>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*     "=obtervalor"   - chama a função DPT_ValorPartida( valorRetornado )
*     "=atual"   - chama a função DPT_QuemPodeDobrar( corRetornada )
*     "=carrega <CorPecas> <Int>"
*                     - chama a função DPT_CarregaDadoPontos( <CorPecas>, <Int> )
*     "=destruir"   - chama a função DPT_DestruirDadoPontos( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "..\TST_ESPC.H"

#include    "..\GENERICO.H"
#include    "..\LERPARM.H"
#include    "..\Cor\COR.H"
#include    "DADOPONTOS.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_DPT_CMD       "=criar"
#define     DOBRA_DPT_CMD       "=dobra"
#define     OBTER_VALOR_CMD       "=obtervalor"
#define     JOGADOR_ATUAL_CMD       "=atual"
#define     CARREGA_DPT_CMD       "=carrega"
#define     DESTROI_CMD         "=destruir"


/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDPT Efetuar operações de teste específicas para dado de pontos
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     dado de pontos ir sendo testado.
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

		DPT_tpCondRet CondRetObtido = DPT_CondRetOK ;
		DPT_tpCondRet CondRetEsperada = DPT_CondRetFaltouMemoria ;
			/* inicializa com qualquer coisa */

		CorPecas ValorDadoCor = 0 ;
		CorPecas ValorEsperadoCor = 0 ;
		int ValorDado = 0;
		int ValorEsperado = 0;
		int ValorObtido = 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar DPT Criar dado de pontos */

			if ( strcmp( ComandoTeste , CRIAR_DPT_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = DPT_CriarDadoPontos( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o dado de pontos." ) ;

			} /* fim ativa: Testar DPT Criar dado de pontos */

		/* Testar DPT Dobra pontos da partida */

			else if ( strcmp( ComandoTeste , DOBRA_DPT_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = DPT_DobraPontos( ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao dobrar pontos." ) ;

			} /* fim ativa: Testar DPT Dobra pontos da partida */

		/* Testar DPT Valor da Partida */

			else if ( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorEsperado , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = DPT_ValorPartida( &ValorObtido ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao obter valor da partida." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != DPT_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorObtido , ValorEsperado ,
												 "O valor da partida está errado." ) ;

			} /* fim ativa: Testar DPT Valor da Partida */

		/* Testar DPT Quem Pode Dobrar */

			else if ( strcmp( ComandoTeste , JOGADOR_ATUAL_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorEsperadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = DPT_QuemPodeDobrar( &ValorDadoCor ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao ver quem é o jogador atual a dobrar." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != DPT_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorDadoCor , ValorEsperadoCor ,
												 "O jogador atual está errado." ) ;

			} /* fim ativa: Testar DPT Quem Pode Dobrar */

		/* Testar DPT Carrega Dado Pontos */

			else if ( strcmp( ComandoTeste , CARREGA_DPT_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										 &ValorDadoCor , &ValorDado , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = DPT_CarregaDadoPontos( ValorDadoCor , ValorDado ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao carregar dado de pontos." ) ;

			} /* fim ativa: Testar DPT Carrega Dado Pontos */

		/* Testar DPT Destruir dado de pontos */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				DPT_DestruirDadoPontos( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar DPT Destruir dado de pontos */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TDPT Efetuar operações de teste específicas para dado de pontos */

/********** Fim do módulo de implementação: Módulo de teste específico para dado de pontos **********/

