/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico para Peças Capturadas
*
*  Arquivo gerado:              TESTBAR.C
*  Letras identificadoras:      TBAR
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	2			elu			16/06/2019		Revisão Final
*	1			jpk			03/06/2019		Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo peças capturadas. Ilustra como redigir um interpretador 
*     de comandos de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo peças capturadas:
*
*     "=criar"        - chama a função BAR_CriarBarra( )
*
*     "=insere <Int>"
*                   - chama a função BAR_InserePecaLista( <Int> )
*                     Obs. notação: <Int>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=obternum <CorPecas> <*Int>"
*                   - chama a função BAR_NumPecas( <CorPecas> , <*Int> )
*
*     "=remover <Int> "
*                   - chama a função BAR_RemovePecaLista( <Int> )
*
*     "=destruir"   - chama a função BAR_DestruirBarra( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "..\TST_ESPC.H"

#include    "..\GENERICO.H"
#include    "..\LERPARM.H"
#include    "..\Lista\LISTA.H"
#include    "..\Cor\COR.H"
#include    "PECASCAPTURADAS.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_FIM_CMD       "=criar"
#define     INSERE_CMD         	"=insere"
#define     OBTER_NUM_CMD       "=obternum"
#define     REMOVE_CMD          "=remover"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TBAR Efetuar operações de teste específicas para pecas capturadas
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     pecas capturadas ir sendo testado.
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

		BAR_tpCondRet CondRetObtido = BAR_CondRetOK ;
		BAR_tpCondRet CondRetEsperada = BAR_CondRetListaVazia ;
			/* inicializa com qualquer coisa */

		CorPecas ValorRecebidoCor = Neutro ;
		CorPecas ValorDadoCor = Neutro ;
		CorPecas ValorEsperadoCor = Neutro ;
		int ValorDadoInt = 0 ;
		int ValorRecebidoInt = 0 ;
		int ValorEsperadoInt = 0 ;


		// CorPecas ValorRecebidoCor = Neutro ;
		// int ValorRecebido = 0 ;
		// int ValorEsperadoInt = 0 ;
		// int ValorObtido = 0 ;
		// int * NumPecas = NULL;

		int NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar BAR Criar Barra */

			if ( strcmp( ComandoTeste , CRIAR_FIM_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_CriarBarra( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar a barra de capturadas." ) ;

			} /* fim ativa: Testar BAR Criar Barra */

		/* Testar BAR Insere Peça na Barra */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										&ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_InserePeca( ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça na casa dada." ) ;

			} /* fim ativa: Testar BAR Insere Peça na Lista */

		/* Testar BAR Numero de Peças na Lista */

			else if ( strcmp( ComandoTeste , OBTER_NUM_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										 &ValorDadoCor , &ValorEsperadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_NumPecas( ValorDadoInt , &ValorRecebidoInt ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
											  "Retorno errado ao obter número de peças da barra." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != BAR_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorEsperadoInt , ValorRecebidoInt ,
												 "Quantidade de peças na barra está errada." ) ;

			} /* fim ativa: Testar BAR Numero de Peças na Lista */

		/* Testar BAR Remove Peça da Lista */

			else if ( strcmp( ComandoTeste , REMOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = BAR_RemovePeca( ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
											  "Retorno errado ao remover peça da barra." ) ;
                
			} /* fim ativa: Testar BAR Remove Peça da Lista */

		/* Testar BAR Destruir Barra */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				BAR_DestruirBarra( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar BAR Destruir Barra */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TBAR Efetuar operações de teste específicas para Peças Capturadas */

/********** Fim do módulo de implementação: Módulo de teste específico para Peças Capturadas **********/

