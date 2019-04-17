#pragma once
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Dado Pontos
*
*  Arquivo gerado:              DADOPONTOS.H
*  Letras identificadoras:      DDPnt
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.00    elu	  	17/04/2019     Inicializado projeto
*	   1.00    jpk	  	17/04/2019     Criação dos protótipos das funções
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Dado Pontos.
*			Serve para saber o valor da partida, dobra-lo e saber quem pode dobrar
*			o valor da partida.
*			
*
********************************************************************************/


typedef struct tgDadoPontos * tppDadoPontos;


/*************************************************************************
*
*	Tipo de dados: Condições de retorno DDPnt 
*
*************************************************************************/

typedef enum
{

	DDPnt_CondRetOk = 0  /* EXECUÇÃO CORRETA */,
	DDPnt_CondRetNok = 1 /* OCORREU ERRO NA EXECUÇÃO  */,
	DDPnt_CondRetMemoryLess = 2 /* NÃO CONSEGUIU ALOCAR MEMÓRIA */,
	DDPnt_CondRetNonexistent = 3 /* ESTRUTURA NÃO CRIADA */

}DDPnt_tpCondRet;
 


/*************************************************************************
*
*	$FC Função: DDPnt Cria dado de pontos
*
*	$EC Descrição: Função que cria o dado de apostas que drobram os 
*	pontos de uma partida.
*
*	$FV Valores de retorno:
*		- DDPnt_CondRetOk
*		- DDPnt_CondRetMemoryLess
*
*************************************************************************/

DDPnt_tpCondRet CriaDadoPontos (tppDadoPontos * dado);


/*************************************************************************
*
*
*
*
*
*************************************************************************/

DDPnt_tpCondRet DobraPontos (tppDadoPontos * dado);


/*************************************************************************
*
*
*
*
*
*************************************************************************/

DDPnt_tpCondRet DestroiDadoPontos (tppDadoPontos * dado);