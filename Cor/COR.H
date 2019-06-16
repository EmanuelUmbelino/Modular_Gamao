#if ! defined( COR_ )
#define COR_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Cor
*
*  Arquivo gerado:              COR.H
*  Letras identificadoras:      COR
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	2			elu			16/06/2019		Revisão Final
*	1			elu			01/05/2019		Criado Modulo
*
*  $ED Descrição do módulo
*			Este modulo contém um enum para as cores possíveis das peças e  
*			dos respectivos jogadores responsáveis pelas mesmas. 
*			Só existem peças pretas e vermelhas. 
*			O valor neutro serve apenas e exclusivamente para a inicialização do Dado de Pontos. 
*
***************************************************************************/

#if defined( COR_OWN )
	#define COR_EXT
#else
	#define COR_EXT extern
#endif
/***********************************************************************
*
*  $TC Tipo de dados: COR Cores das peças
*
***********************************************************************/

	typedef enum corPecas{

		Neutro = -1 ,

		Preta = 0 ,

		Vermelha = 1

	} CorPecas ;

#undef COR_EXT

/********** Fim do módulo de definição: Módulo Cor **********/

#else
#endif