/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico para Peças Finalizadas
*
*  Arquivo gerado:              TESTFIM.C
*  Letras identificadoras:      TFIM
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	2			elu			17/06/2019		Revisão Final
*	1			phs			29/05/2019		Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo peças finalizadas. Ilustra como redigir um interpretador 
*     de comandos de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo Peças Finalizadas:
*
*     "=criar"        - chama a função FIM_CriarFinalizadas( )
*
*     "=insere <Int>"
*                   - chama a função FIM_FinalizarPeca( <Int> )
*                     Obs. notação: <Int>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=obternumpec <CorPecas> <*Int>"
*                   - chama a função FIM_QuantidadeFinalizada( <CorPecas> , <*Int> )
*
*     "=destruir"   - chama a função FIM_DestruirFinalizadas( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "..\TST_ESPC.H"

#include    "..\GENERICO.H"
#include    "..\LERPARM.H"
#include    "..\Lista\LISTA.H"
#include    "..\Cor\COR.H"
#include    "PECASFINALIZADAS.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_FIM_CMD       "=criar"
#define     INSERE_CMD         	"=insere"
#define     OBTER_NUM_CMD       "=obternum"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: FIM Efetuar operações de teste específicas para pecas finalizadas
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     pecas finalizadas ir sendo testado.
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

		FIM_tpCondRet CondRetObtido = FIM_CondRetOK ;
		FIM_tpCondRet CondRetEsperada = FIM_CondRetFimNaoExiste;
			/* inicializa com qualquer coisa */

		CorPecas ValorDadoCor = Neutro ;
		int ValorEsperadoInt = 0 ;
		int ValorObtidoInt = 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar FIM Criar Lista de Peças Finalizadas */

			if ( strcmp( ComandoTeste , CRIAR_FIM_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = FIM_CriarFinalizadas( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar a lista." ) ;

			} /* fim ativa: Testar FIM Criar Lista de Peças Finalizadas */

		/* Testar FIM Insere Peça na Lista de Peças Finalizadas */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										&ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = FIM_FinalizarPeca( ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao finaliza peça de determinada cor." ) ;

			} /* fim ativa: Testar FIM Insere Peça na Lista de Peças Finalizadas */

		/* Testar FIM Numero de Peças na Lista de Peças Finalizadas */

			else if ( strcmp( ComandoTeste , OBTER_NUM_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										&ValorDadoCor , &ValorEsperadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = FIM_NumPecas( ValorDadoCor , &ValorObtidoInt ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao contar numero de pecas finalizadas." ) ;

				if (Ret != TST_CondRetOK || CondRetObtido != FIM_CondRetOK)
				{
					return Ret;
				}

				return TST_CompararInt( ValorEsperadoInt , ValorObtidoInt ,
												"Quantidade de pecas finalizadas está errada." ) ;


			} /* fim ativa: Testar FIM Numero de Peças na Lista de Peças Finalizadas */


		/* Testar FIM Destruir Lista de Peças Finalizadas */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				FIM_DestruirFinalizadas( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar FIM Destruir Lista de Peças Finalizadas */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TFIM Efetuar operações de teste específicas para lista de peças finalizadas */

/********** Fim do módulo de implementação: Módulo de teste específico para Peças Finalizadas **********/

