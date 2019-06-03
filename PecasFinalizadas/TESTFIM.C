/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTFIM.C
*  Letras identificadoras:      FIM
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*           jpk - João Pedro Kalil
*           phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*    Versão	  Autores		 	 Data        Observações
*      1		phs	  	29/05/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo lista de peças finalizadas. Ilustra como redigir um interpretador 
*     de comandos de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo tabuleiro:
*
*     "=criar"        - chama a função FIM_CriarFinalizadas( )
*     "=insere <Int>"
*                   - chama a função FIM_FinalizarPeca( <Int> )
*                     Obs. notação: <Int>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*     "=obternum <Int> <*Int>"
*                   - chama a função FIM_QuantidadeFinalizada( <Int> , <*Int> )
*     "=destruir"   - chama a função FIM_DestruirFinalizadas( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"
#include    "LISTA.H"
#include    "COR.H"
#include    "PECA.H"
#include    "PECASFINALIZADAS.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_FIM_CMD       "=criar"
#define     INSERE_CMD         	"=insere"
#define     OBTER_NUM_CMD       "=obternum"
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

		CorPecas ValorRecebidoCor	= 0 ;
		int ValorDadoCor			= 0 ;
		int ValorEsperadoInt		= 0 ;
		int ValorObtido				= 0 ;
		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar TAB Criar tabuleiro */

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
												"Retorno errado ao criar o tabuleiro." ) ;

			} /* fim ativa: Testar TAB Criar tabuleiro */

		/* Testar TAB Insere Peça na Casa */

			else if ( strcmp( ComandoTeste , INSERE_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										&ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 3 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = FIM_FinalizarPeca( ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao inserir peça na casa dada." ) ;

			} /* fim ativa: Testar TAB Insere Peça na Casa */

		/* Testar TAB Remove Peça na Casa */

			else if ( strcmp( ComandoTeste , OBTER_NUM_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "iii" ,
										 &ValorEsperadoInt, &ValorDadoCor, &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = FIM_QuantidadeFinalizada( ValorDadoCor, &ValorObtido) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
											  "Retorno errado ao obter número de peças da casa." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != TAB_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorEsperadoInt , ValorObtido ,
												"Quantidade de peças finalizadas está errada." ) ;

			} /* fim ativa: Testar TAB Remove Peça na Casa */

		/* Testar TAB Destruir Tabuleiro */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				FIM_DestruirPecasFinalizadas( ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar TAB Destruir Tabuleiro */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TTAB Efetuar operações de teste específicas para tabuleiro */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

