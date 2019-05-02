#if ! defined( COR_ )
#define COR_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Cor
*
*  Arquivo gerado:              COR.H
*  Letras identificadoras:      COR
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.00    elu	  	01/05/2019     Criado Modulo
*
*  $ED Descrição do módulo
*			Este módulo contém as cores de peças possiveis no jogo.
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

         Preta = 0 ,

         Vermelha = 1

   } CorPecas ;

#undef COR_EXT

/********** Fim do módulo de definição: Módulo Cor **********/

#else
#endif