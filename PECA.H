
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Peça
*
*  Arquivo gerado:              PECA.H
*  Letras identificadoras:      PEC
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores	  Data           Observações
*      1.05    elu	  	27/04/2019     Criadas funções de criar, destruir e obter cor
*      1.00    elu	  	17/04/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*			Este módulo contém o tipo abstrato de dados da estrutura Peça.
*			Se pode criar e destruir uma peça, além de obter a cor da peça.
*
***************************************************************************/
 

/***********************************************************************
*
*  $TC Tipo de dados: PEC Descritor da peça
*
*
*  $ED Descrição do tipo
*     Descreve uma peça
*
***********************************************************************/

typedef struct peca PEC ;

/***********************************************************************
*
*  $TC Tipo de dados: PEC Cores das peças
*
***********************************************************************/

   typedef enum {

         Vazio = -1 ,

         Preta = 0 ,

         Vermelha = 1

   } PEC_cor ;

/***********************************************************************
*
*  $FC Função: PEC Criar Peça
*
*  $ED Descrição da função
*     Cria uma nova peça com a cor escolhida.
*
*  $FV Valor retornado
*     PEC
*
***********************************************************************/

   PEC * PEC_CriarPeca( PEC_cor cor ) ;


/***********************************************************************
*
*  $FC Função: PEC Obter Cor
*
*  $ED Descrição da função
*     Obtem a cor de uma peça.
*
*  $EP Parâmetros
*     $P peca - É o ponteiro para a peça que quer obter cor
*
*  $FV Valor retornado
*     PEC_cor
*
***********************************************************************/

   PEC_cor PEC_ObterCor( PEC * peca )  ;


/***********************************************************************
*
*  $FC Função: PEC Destruir Peça
*
*  $ED Descrição da função
*     Destrói peça.
*
*  $EP Parâmetros
*     $P peca - É o ponteiro para a peça que quer destruir
*
***********************************************************************/

   void PEC_DestruirPeca( PEC * peca ) ;

	 
/********** Fim do módulo de definição: Módulo Peça **********/