/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTTAB.C
*  Letras identificadoras:      TTAB
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data        Observações
*      2				elu	  	01/05/2019     Criados casos de teste
*      1				elu	  	01/05/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo tabuleiro. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo tabuleiro:
*
*     "=criar"        - chama a função TAB_CriarTabuleiro( )
*     "=insere <Int> <Int>"
*                   - chama a função TAB_InserePecaCasa( <Int> , <Int> )
*                     Obs. notação: <Int>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=remove <Int>"
*                   - chama a função TAB_RemovePecaCasa( <Int> )
*     "=obternum <Int> <*Int>"
*                   - chama a função TAB_NumPecasCasa( <Int> , <*Int> )
*     "=obtercor <Int> <*CorPecas>"
*                   - chama a função TAB_CorPecasCasa( <Int> , <*CorPecas> )
*     "=destruir"   - chama a função TAB_DestruirTabuleiro( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"
#include    "lista/LISTA.H"
#include    "cor.h"
#include    "lista/LISTA.H"
#include    "tabuleiro.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_TAB_CMD       "=criar"
#define     INSERE_CMD         	"=insere"
#define     REMOVE_CMD         	"=remove"
#define     OBTER_NUM_CMD       "=obternum"
#define     OBTER_COR_CMD       "=obtercor"
#define     DESTROI_CMD         "=destruir"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TTAB Efetuar operações de teste específicas para tabuleiro
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     tabuleiro ir sendo testado.
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

		TAB_tpCondRet CondRetObtido   = TAB_CondRetOK ;
		TAB_tpCondRet CondRetEsperada = TAB_CondRetCasaVazia ;
												  /* inicializa para qualquer coisa */

		CorPecas ValorRecebidoCor	= Neutro ;
		CorPecas ValorDadoCor			= Neutro ;
		CorPecas ValorEsperadoCor	= Neutro ;
		int ValorDadoInt					= 0 ;
		int ValorRecebidoInt			= 0 ;
		int ValorEsperadoInt			= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar TAB Criar tabuleiro */

			if ( strcmp( ComandoTeste , CRIAR_TAB_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "i" ,
										 &CondRetEsperada ) ;
				if ( NumLidos != 1 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_CriarTabuleiro( ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar o tabuleiro." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

		/* Testar TAB Insere Peça na Casa */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										 &ValorDadoInt , &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_InserePecaCasa( ValorDadoInt , ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça na casa dada." ) ;

			} /* fim ativa: Testar TAB Insere Peça na Casa */

		/* Testar TAB Remove Peça na Casa */

			else if ( strcmp( ComandoTeste , REMOVE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_RemovePecaCasa( ValorDadoInt ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao remover peça na casa dada." ) ;

			} /* fim ativa: Testar TAB Remove Peça na Casa */

		/* Testar TAB Num Peças da Casa */

			else if ( strcmp( ComandoTeste , OBTER_NUM_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										 &ValorDadoInt , &ValorEsperadoInt , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_NumPecasCasa( ValorDadoInt , &ValorRecebidoInt ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
											  "Retorno errado ao obter número de peças da casa." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != TAB_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorEsperadoInt , ValorRecebidoInt ,
												 "Quantidade de peças na casa está errada." ) ;

			} /* fim ativa: Testar TAB Num Peças da Casa */

		/* Testar TAB Cor Peças da Casa */

			else if ( strcmp( ComandoTeste , OBTER_COR_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										 &ValorDadoInt , &ValorEsperadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = TAB_CorPecasCasa( ValorDadoInt , &ValorRecebidoCor ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
											  "Retorno errado ao obter número de peças da casa." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != TAB_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorEsperadoCor , ValorRecebidoCor ,
												 "Cor das peças na casa está errada." ) ;

			} /* fim ativa: Testar TAB Cor Peças da Casa */


		/* Testar TAB Destruir Tabuleiro */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				TAB_DestruirTabuleiro( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir Tabuleiro */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TTAB Efetuar operações de teste específicas para tabuleiro */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

