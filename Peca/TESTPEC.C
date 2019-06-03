/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTPEC.C
*  Letras identificadoras:      TPEC
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
*     módulo peça. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo peça:
*
*     "=criar <CorPecas>"        - chama a função PEC_CriarPeca( pecaRetornada , <CorPecas> )
*                     Obs. notação: <CorPecas>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*     "=obtercor"   - chama a função PEC_ObterCor( pecaAtual , corRetornada )
*     "=destruir"   - chama a função PEC_DestruirPeca( pecaAtual )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"
#include    "cor.h"
#include    "peca.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_PEC_CMD       "=criar"
#define     OBTER_COR_CMD       "=obtercor"
#define     DESTROI_CMD         "=destruir"

/* Variavel Global para efetuar teste */

	PEC * peca	= NULL ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPEC Efetuar operações de teste específicas para peça
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     peça ir sendo testado.
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

		PEC_tpCondRet CondRetObtido   = PEC_CondRetOK ;
		PEC_tpCondRet CondRetEsperada = PEC_CondRetFaltouMemoria ;
												  /* inicializa para qualquer coisa */
		CorPecas ValorDadoCor			= 0 ;
		CorPecas ValorEsperadoCor	= 0 ;

		int  NumLidos = -1 ;

		TST_tpCondRet Ret ;

		/* Testar PEC Criar peça */

			if ( strcmp( ComandoTeste , CRIAR_PEC_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorDadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = PEC_CriarPeca( &peca,  ValorDadoCor ) ;

				return TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao criar a peça." ) ;

			} /* fim ativa: Testar PEC Criar peça */

		/* Testar PEC Obter Cor */

			else if ( strcmp( ComandoTeste , OBTER_COR_CMD ) == 0 )
			{

				NumLidos = LER_LerParametros( "ii" ,
										 &ValorEsperadoCor , &CondRetEsperada ) ;
				if ( NumLidos != 2 )
				{
					return TST_CondRetParm ;
				} /* if */

				CondRetObtido = PEC_ObterCor( peca , &ValorDadoCor ) ;

				Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
												"Retorno errado ao obter cor." ) ;

				if ( Ret != TST_CondRetOK || CondRetObtido != PEC_CondRetOK )
				{
					return Ret ;
				} /* if */

				return TST_CompararInt( ValorDadoCor , ValorEsperadoCor ,
												 "A cor da peça está errada." ) ;

			} /* fim ativa: Testar PEC Obter Cor */


		/* Testar PEC Destruir Peça */

			else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
			{

				PEC_DestruirPeca( peca ) ;

				return TST_CondRetOK ;

			} /* fim ativa: Testar PEC Destruir Peça */

		return TST_CondRetNaoConhec ;

	} /* Fim função: TPEC Efetuar operações de teste específicas para peça */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

