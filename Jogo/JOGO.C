/***************************************************************************
*  $MCI Módulo de implementação: Módulo Jogo
*
*  Arquivo gerado:              JOGO.C
*  Letras identificadoras:      JOG
*
*  Projeto: INF 1301 Jogo Gamão via Terminal
*  Autores: elu - Emanuel Lima Umbelino
*			jpk - João Pedro Kalil
*			phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*	Versão		Autores		Data			Observações
*	12			elu			17/06/2019		Melhorada movimentação e ajustes nas cores
*	11			phs			17/06/2019		Aceitar / Recusar dobra de pontos e tela de vitória
*	10			elu			15/06/2019		Finalizar peças e remover da barra
*	9			jpk			11/06/2019		opção de sair do jogo e dobrar pontos
*	8			jpk			11/06/2019		Carregar / Salvar jogo
*	7			elu			08/06/2019		Movimentacao Basica
*	6			elu			07/06/2019		Regra de dados iguais
*	5			elu			07/06/2019		Mudança de jogador, sorteio de dados e possibilidades de jogadas
*	4			elu			05/06/2019		Sistema de cores melhorado, sorteio de quem começa
*	3			elu			04/06/2019		Menus
*	2			elu			04/06/2019		Impressão básica tabuleiro
*	1			elu			04/06/2019		Inicializado projeto
*
***************************************************************************/
	#include <conio.h>
	#include <stdio.h>
	#include <string.h>
	#include <windows.h>

	#include "..\Tabuleiro\TABULEIRO.H"
	#include "..\PecasCapturadas\PECASCAPTURADAS.H"
	#include "..\PecasFinalizadas\PECASFINALIZADAS.H"
	#include "..\Dado\DADO.H"
	#include "..\DadoPontos\DADOPONTOS.H"
	#include "..\Cor\COR.H"
	#define JOGO_OWN
	#include "JOGO.H"
	#undef JOGO_OWN

	#ifdef _WIN32
	# define CLEAR_SCREEN system ("cls")
	#else
	# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
	#endif

	#define VERMELHO "[1;31m"
	#define PRETO "[1;32m"
	#define PRIMARIO "[1;36m"
	#define SECUNDARIO "[0;34m"
	#define TERCIARIO "[1;33m"

/*****  Dados encapsulados no módulo  *****/

	static char *cores[2] ;

	typedef enum passo {

		JogarDado = 0 ,

		EscolherPeca = 1 ,

		EscolherDado = 2

	} Passo ;

/***** Protótipos das funções encapuladas no módulo *****/

	static void MenuInicial ( void ) ;

	static void NovoJogo ( void ) ;

	static void CarregarJogo ( char * nomeJogo ) ;
 
	static void SalvarJogo ( char * nomeJogo, CorPecas jogadorAtual ) ;

	static void Jogo ( CorPecas jogadorAtual ) ;

	static int Movimentar ( int posInicio, int posFinal, CorPecas jogadorAtual ) ;

	static int PodeFinalizar ( CorPecas jogadorAtual ) ;

	static int ProxDado ( int *dados, int dAtual ) ;

	static int AntCasaComPeca ( int casaSelecionada, CorPecas cor ) ;

	static int ProxCasaComPeca ( int casaSelecionada, CorPecas cor ) ;

	static void ImprimirJogo ( CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void ImprimePeca ( int totalCasa, CorPecas cor, int posicao ) ;

	static int CasaApontadaPorDado ( int numeroCasa, CorPecas jogadorAtual, int casaFixada, int dados[4] ) ;

	static void ImprimeNumeroCasa ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void ImprimeSetaSelecao ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void FimDeJogo ( CorPecas jogadorVencedor, int valorPartida ) ;

	static void VerificaCondicaoVitoriaEspecial( int * valorPartida, CorPecas jogadorVencedor ) ;

	static int TrocarOpcao( int opcaoSelecionada, int numOpcoes ) ;

	static int CasaSelecionada( CorPecas jogadorAtual, int casaFixada, int dadoAtual ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: JOG Iniciar Jogo
*  ****/

	void JOG_IniciarJogo( void ) 
	{
		cores[Preta] = PRETO ;
		cores[Vermelha] = VERMELHO ;

		MenuInicial( ) ;
	} /* Fim função: JOG Iniciar Jogo */


/*****  Código das funções encapsuladas no módulo  *****/
	
/***************************************************************************
*
*  $FC Função: JOG Menu Inicial
*
*  $ED Descrição da função
*     Imprime e gerencia o menu inicial.
*     Vai para a função escolhida ou sai do jogo dependendo da escolha do jogador. 
*
*  ****/

	void MenuInicial ( void )
	{
		int i, ch, opcaoSelecionada = 0 ;
		char *opcoes[3], nomeJogo[15] ;
		HWND wh ;
		opcoes[0] = "Novo Jogo" ;
		opcoes[1] = "Carregar Jogo" ;
		opcoes[2] = "Sair" ;

		wh = GetConsoleWindow( ) ;
		MoveWindow( wh, 100, 50, 1000, 550, TRUE ) ;
		CLEAR_SCREEN ;
		while ( 1 ) {
			puts( "   _____              __  __               ____  " ) ;
			puts( "  / ____|     /\\     |  \\/  |     /\\      / __ \\ " ) ;
			puts( " | |  __     /  \\    | \\  / |    /  \\    | |  | |" ) ;
			puts( " | | |_ |   / /\\ \\   | |\\/| |   / /\\ \\   | |  | |" ) ;
			puts( " | |__| |  / ____ \\  | |  | |  / ____ \\  | |__| |" ) ;
			puts( "  \\_____| /_/    \\_\\ |_|  |_| /_/    \\_\\  \\____/ " ) ;

			for ( i = 0; i < 3; i++ ) {
				printf( "\n  \n  \t\t" ) ;
				if ( opcaoSelecionada == i )
					printf( "\033%s>", PRIMARIO ) ;
				printf( " %s\033[0m", opcoes[i] ) ;
			} /* for */
			printf( "\n\n\n" ) ;

			ch = getch( ) ;
			CLEAR_SCREEN ;
			if ( ch == 0xE0 ) /* alguma seta */
				opcaoSelecionada = TrocarOpcao( opcaoSelecionada, 2 ) ;
			else if ( ch == 13 ) /* enter */
				break ;
		} /* while */
		if ( opcaoSelecionada == 2)
			return ;
		
		TAB_CriarTabuleiro( ) ;
		FIM_CriarFinalizadas( ) ;
		DPT_CriarDadoPontos( ) ;
		BAR_CriarBarra( ) ;
		if ( opcaoSelecionada == 0 ) {
			NovoJogo( ) ;
		} /* if */
		else if ( opcaoSelecionada == 1 ) {
			CLEAR_SCREEN ;
			printf( "Insira o nome do jogo que deseja carregar.\n  " ) ;
			scanf( "%s", nomeJogo ) ;
			CarregarJogo( nomeJogo ) ;
		} /* else if */
	} /* Fim função: JOG Menu Inicial */

/***************************************************************************
*
*  $FC Função: JOG Novo Jogo
*
*  ****/

	void NovoJogo( void )
	{
		int dados[2] ;
		CorPecas jogadorInicial ;
		dados[0]=0 ; dados[1]=0 ;

		CLEAR_SCREEN ;
		printf( "\n   Sortear os 2 dados pra ver quem comeca\n  \n  " ) ;
		printf( "\n   Escolha quem sera o \033%sVERMELHO\033[0m", cores[Vermelha] ) ;
		printf( " e quem sera o \033%sVERDE\033[0m\n  \n  ", cores[Preta] ) ;
		printf( "\n   Pressione qualquer tecla para sortear quem comeca\n  \n  " ) ;
		
		while ( 1 ) {
			getch( ) ;
			DAD_JogarDado( &dados[0] ) ;
			DAD_JogarDado( &dados[1] ) ;
			
			CLEAR_SCREEN ;
			printf( "\n   Sortear os 2 dados pra ver quem comeca\n  " ) ;
			printf( "\n   \033%sVERMELHO\033[0m:  %d", cores[Vermelha], dados[0] ) ;
			printf( "\n   \033%sVERDE\033[0m:  %d", cores[Preta], dados[1] ) ;
			
			if ( dados[0] == dados[1] ) {
				printf( "\n  \n   Empatou..." ) ;
				printf( "\n  \n   Pressione qualquer tecla para sortear novamente\n  \n  " ) ;
			} /* if */
			else {
				if ( dados[0] > dados[1] ) {
					jogadorInicial = Vermelha ;
					printf( "\n  \n   \033%sVERMELHO\033[0m comeca!", cores[jogadorInicial] ) ;
				}  /* if */
				else {
					jogadorInicial = Preta ;
					printf( "\n  \n   \033%sVERDE\033[0m comeca!", cores[jogadorInicial] ) ;
				} /* else */
				break ;
			} /* else */
		} /* while */
		
		printf( "\n  \n   Pressione qualquer tecla para comecar o jogo\n  \n  " ) ;
		getch( ) ;
		Jogo( jogadorInicial ) ;
	} /* Fim função: JOG Novo Jogo */

/***************************************************************************
*
*  Função: JOG Carregar Jogo
*
*  ****/

	void CarregarJogo ( char * nomeJogo ) 
	{
		FILE * fp ;
		int i, j, casa, numPecas, numPecasAux, valorPartida ;
		CorPecas corPec = Neutro ;
		CorPecas jogadorAtual = Neutro ;
		char jogo;

		fp = fopen( nomeJogo, "r" ) ;
		if ( fp == NULL ) {
			CLEAR_SCREEN ;
			printf( " Nao foi possivel carregar o jogo %s!\n  ", nomeJogo ) ;
			printf( "\n  \n   Pressione qualquer tecla para voltar ao menu\n  \n  " ) ;
			getch( ) ;
			MenuInicial( ) ;
		} /* if */
		else {
			while ( fscanf( fp, "%c\n", &jogo )!=EOF ) {
				if ( jogo == 'T' ) {
					for ( i=0 ; i<24 ; i++ ) {
						fscanf( fp, "%d %d %d\n  ", &casa, &numPecas, &corPec ) ;
						TAB_NumPecasCasa( casa, &numPecasAux ) ;
						for ( j=0 ; j<numPecasAux ; j++ )
							TAB_RemovePecaCasa( casa ) ; 
						for ( j=0 ; j<numPecas ; j++ )
							TAB_InserePecaCasa( casa, corPec ) ; 
					} /* for */
				} /* if */
				else if ( jogo == 'B' || jogo == 'F' ) {
					for ( i=0 ; i<2 ; i++ ) {
						fscanf( fp, "%d %d\n  ", &corPec, &numPecas ) ;
						for ( j=0 ; j<numPecas ; j++ ) {
							if ( jogo == 'B' )
								BAR_InserePeca( corPec ) ;
							else
								FIM_FinalizarPeca( corPec ) ;
						} /* for */
					} /* for */
				} /* else if */
				else if ( jogo == 'V' )
					fscanf( fp, "%d\n  ", &valorPartida ) ;
				else if ( jogo == 'J' )
					fscanf( fp, "%d\n  ", &jogadorAtual ) ;
				else
					fscanf( fp, "%d\n  ", &corPec ) ;
			} /* while */
			DPT_CarregaDadoPontos( corPec, valorPartida ) ;
			Jogo( jogadorAtual ) ;
		} /* else */
	} /* Fim função: JOG Carregar Jogo */

/***************************************************************************
*
*  Função: JOG Salvar Jogo
*
*  ****/

	void SalvarJogo ( char * nomeJogo, CorPecas jogadorAtual )
	{
		FILE * fp ;
		int i, num ;
		CorPecas  podeDobrar, corPec ;
		fp = fopen( nomeJogo, "w" ) ;
		if ( fp == NULL ) {
			printf( "Nao foi possivel salvar o jogo!\n  " ) ;
		} /* if */
		else {	
			corPec = podeDobrar = Preta ;
			fprintf( fp, "T\n" ) ;
			for ( i=1 ; i<25 ; i++ ) {
				TAB_NumPecasCasa( i, &num ) ;
				TAB_CorPecasCasa( i, &corPec ) ;
				fprintf( fp, "%d %d %d\n", i, num, corPec ) ;
			} /* for */
			fprintf( fp, "B\n" ) ;
			BAR_NumPecas( Vermelha, &num ) ;
			fprintf( fp, "%d %d\n", 1, num ) ;
			BAR_NumPecas( Preta, &num ) ;
			fprintf( fp, "%d %d\n", 0, num ) ;
			
			fprintf( fp, "F\n" ) ;
			FIM_NumPecas( Vermelha, &num ) ;
			fprintf( fp, "%d %d\n", 1, num ) ;
			FIM_NumPecas( Preta, &num ) ;
			fprintf( fp, "%d %d\n", 0, num ) ;

			DPT_ValorPartida( &num ) ;
			fprintf( fp, "V\n%d\n", num ) ;
			DPT_QuemPodeDobrar( &podeDobrar ) ;
			fprintf( fp, "D\n%d\n", podeDobrar ) ;

			fprintf( fp, "J\n%d\n", jogadorAtual ) ;
			fclose( fp ) ;
		} /* else */
	} /* Fim função: JOG Salvar Jogo */

/***************************************************************************
*
*  Função: JOG Jogo
*
*  ****/

	void Jogo ( CorPecas jogadorAtual )
	{
		int casaSelecionada, casaFixada, dAtual = 0, ch, i, valorPartida, opcaoSelecionada = 0 ;
		CorPecas podeDobrar ;
		Passo passo = JogarDado ;
		char nomeJogo[15] ;
		int dados[4] ;

		for ( i = 0 ; i < 4 ; i ++ )
			dados[i] = 0 ;

		DPT_ValorPartida( &valorPartida ) ;
		DPT_QuemPodeDobrar( &podeDobrar ) ;

		if ( jogadorAtual == Vermelha )
			casaSelecionada = AntCasaComPeca( 0, jogadorAtual ) ;
		else
			casaSelecionada = ProxCasaComPeca( 0, jogadorAtual ) ;
		casaFixada = casaSelecionada ;

		while ( 1 ) {
			CLEAR_SCREEN ;
			if ( jogadorAtual == Vermelha )
				printf( "\n  Vez do \033%sVERMELHO\033[0m", cores[jogadorAtual] ) ;
			else
				printf( "\n  Vez do \033%sVERDE\033[0m", cores[jogadorAtual] ) ;
			printf( "\n  Valor da partida: %d", valorPartida ) ;
			ImprimirJogo( jogadorAtual, casaSelecionada, casaFixada, dados ) ;
			if ( passo != JogarDado ) {
				printf( "\n  Jogadas Disponiveis:" ) ;
				for ( i = 0 ; i < 4 ; i ++ ) {
					if ( dados[i] > 0 )
						printf( " %d ", dados[i] ) ;
				} /* for */
			} /* if */

			if ( passo == JogarDado ) {
				printf( "\n  Espaco - jogar dados" ) ;
				printf( "\n  D - Dobrar pontos" ) ;
				printf( "\n  S - Salvar jogo" ) ;
			} /* if */
			else if ( passo == EscolherPeca ) {
				printf( "\n  Z e X - mover a seta" ) ;
				printf( "\n  P - Passa jogada" ) ;
				printf( "\n  Espaco - selecionar peca" ) ;
			} /* else if */
			else if ( passo == EscolherDado ) {
				printf( "\n  Z e X - trocar dado" ) ;
				printf( "\n  Espaco - confirmar jogada" ) ;
				printf( "\n  P - Passa jogada" ) ;
				printf( "\n  Esc - voltar para selecao de peca" ) ;
			} /* else if */
			
			if ( passo != EscolherDado ) {
				printf( "\n  Esc - Fechar jogo" ) ;
			} /* if */
			
			ch = getch( ) ;
			if ( ch == 'z' || ch == 'Z' || ch == 'x' || ch == 'X' ) {
				if ( passo == EscolherPeca ) {
					if ( ch == 'z' || ch == 'Z' )
						casaSelecionada = ProxCasaComPeca( casaSelecionada, jogadorAtual ) ;
					else
						casaSelecionada = AntCasaComPeca( casaSelecionada, jogadorAtual ) ;
					casaFixada = casaSelecionada ;
				}  /* if */
				else if ( passo == EscolherDado ) {
					dAtual = ProxDado ( dados, dAtual ) ;
					casaSelecionada = CasaSelecionada( jogadorAtual, casaFixada, dados[dAtual] ) ;
				} /* else if */
			} /* if */
			else if ( ch == 32 ) { /* barra de espaço */
				if ( passo == JogarDado ) {
					DAD_JogarDado( &dados[0] ) ; 
					DAD_JogarDado( &dados[1] ) ;
					if ( dados[0] == dados[1] ) {
						dados[2] = dados[0] ;
						dados[3] = dados[0] ;
					} /* if */

					passo = EscolherPeca ;
					if ( casaFixada < 1 || casaFixada > 24 ) {
						passo = EscolherDado ;
						casaSelecionada = CasaSelecionada( jogadorAtual, casaFixada, dados[dAtual] ) ;
					} /* if */
				} /* if */
				else if ( passo == EscolherPeca ) {
					if ( dados[dAtual] == 0 )
						dAtual = ProxDado ( dados, dAtual ) ;
					casaSelecionada = CasaSelecionada( jogadorAtual, casaFixada, dados[dAtual] ) ;
					passo = EscolherDado ;
				} /* else if */
				else if ( passo == EscolherDado ) {
					if ( Movimentar( casaFixada, casaSelecionada, jogadorAtual ) == 1 ) {
						dados[dAtual] = 0 ;
						dAtual = ProxDado ( dados, dAtual ) ;

						if ( dados[dAtual] == 0 ) {
							jogadorAtual = !jogadorAtual ;
							passo = JogarDado ;
						} /* if */
						else
							passo = EscolherPeca ;
						if ( jogadorAtual == Vermelha )
							casaSelecionada = AntCasaComPeca( 0, jogadorAtual ) ;
						else
							casaSelecionada = ProxCasaComPeca( 0, jogadorAtual ) ;
						casaFixada = casaSelecionada ;
					} /* if */
				} /* else if */
			} /* else if */
			else if ( ch == 27 ) { /* esc */
				if ( passo == EscolherDado ) {
					dAtual = 0 ;
					casaSelecionada = casaFixada ;
					passo = EscolherPeca ;
				} /* if */
				else {
					CLEAR_SCREEN ;
					printf( "\n  Se o jogo nao foi salvo ele nao podera ser continuado de onde parou.\n  Deseja realmente deseja sair?[S / N]\n  " ) ;
					ch = getch( ) ;
					if ( ch == 's' || ch == 'S' ) {
						TAB_DestruirTabuleiro( ) ;
						FIM_DestruirFinalizadas( ) ;
						DPT_DestruirDadoPontos( ) ;
						BAR_DestruirBarra( ) ;
						break ;
					} /* if */
				} /* else */
			} /* else if */
			else if ( ch == 's' || ch == 'S' ) {
				if ( passo == JogarDado ) {
					CLEAR_SCREEN ;
					printf( "\n Insira o nome do jogo para ser salvo ( Max de 15 caracteres )..\n  " ) ;
					scanf( "%s", nomeJogo ) ;
					SalvarJogo( nomeJogo, jogadorAtual ) ;
				} /* if */
			} /* else if */
			else if ( ch == 'd' || ch == 'D' ) {
				if ( passo == JogarDado ) {
					if ( jogadorAtual == podeDobrar || podeDobrar == Neutro ) {
						CLEAR_SCREEN ;

						while ( 1 ) {
							if ( jogadorAtual == Vermelha )
								printf( "O jogador \033%sVERMELHO\033[0m te desafiou a dobrar os pontos\n  ", cores[Vermelha] ) ;
							else if ( jogadorAtual == Preta )
								printf( "O jogador \033%sVERDE\033[0m te desafiou a dobrar os pontos\n  ", cores[Preta] ) ;
							
							if ( opcaoSelecionada == 0 )
								printf( "\033%s>", PRIMARIO ) ; 
							else
								printf( " " ) ; 
							printf( " Aceitar\033[0m\n  " ) ;
							if ( opcaoSelecionada == 1 )
								printf( "\033%s>", PRIMARIO ) ;
							else
								printf( " " ) ;
							printf( " Recusar\033[0m\n  " ) ;
							ch = getch( ) ;
							CLEAR_SCREEN ;
							if ( ch == 0xE0 ) /* alguma seta */
								opcaoSelecionada = TrocarOpcao( opcaoSelecionada, 1 ) ;
							else if ( ch == 13 ) /* enter */
								break ;
						} /* while */
						if ( opcaoSelecionada == 0 ) {
							DPT_DobraPontos( jogadorAtual ) ;
							DPT_QuemPodeDobrar( &podeDobrar ) ;
							DPT_ValorPartida( &valorPartida ) ;
						} /* if */
						else if ( opcaoSelecionada == 1 ) {
							DPT_ValorPartida( &valorPartida ) ;
							FimDeJogo( jogadorAtual, valorPartida ) ;
							MenuInicial( ) ;
						} /* else if */
					} /* if */
					else {
						CLEAR_SCREEN ;
						printf( "Voce nao pode dobrar os pontos dessa partida.\n  Pressione qualquer tecla para continuar...\n  " ) ;
						getch( ) ;
					} /* else */
				} /* if */
			} /* else if */
			else if ( ch == 'p' || ch == 'P' ) {
				if ( passo != JogarDado ) {
					CLEAR_SCREEN ;
					printf( "\n  So deve pular a jogada se nao houver mais movimentos possiveis.\n  Deseja realmente deseja pular a jogada?[S / N]\n  " ) ;
					ch = getch( ) ;
					if ( ch == 's' || ch == 'S' ) {
						dados[0] = 0 ;
						dados[1] = 0 ;
						dados[2] = 0 ;
						dados[3] = 0 ;
						jogadorAtual = !jogadorAtual ;
						passo = JogarDado ;
						casaSelecionada = ProxCasaComPeca( 0, jogadorAtual ) ;
						casaFixada = casaSelecionada ;
					} /* if */
				} /* if */
			} /* else if */
			else
				printf( "\n  \n  %c", ch ) ;
		} /* while */
	} /* Fim função: JOG Jogo */

/***************************************************************************
*
*  Função: JOG Movimentar peça
*
*  ****/

	int Movimentar ( int posInicio, int posFinal, CorPecas jogadorAtual )
	{
		int numPecasFinal, numPecasFinalizadas, valorPartida ;
		CorPecas corFinal ;

		if ( jogadorAtual == Vermelha && posFinal < 1 && !PodeFinalizar( jogadorAtual ) )
			return 0 ;
		if ( jogadorAtual == Preta && posFinal > 24 && !PodeFinalizar( jogadorAtual ) )
			return 0 ;
		
		if ( posFinal >= 1 && posFinal <= 24 ) {
			TAB_NumPecasCasa( posFinal, &numPecasFinal ) ;
			
			if ( numPecasFinal > 0 ) {
				TAB_CorPecasCasa( posFinal, &corFinal ) ;
				if ( corFinal != jogadorAtual ) {
					if ( numPecasFinal > 1 )
						return 0 ;
					TAB_RemovePecaCasa( posFinal ) ;
					BAR_InserePeca( corFinal ) ;
				} /* if */
			} /* if */

			TAB_InserePecaCasa( posFinal, jogadorAtual ) ;
		} /* if */
		else {
			FIM_FinalizarPeca( jogadorAtual ) ;
			FIM_NumPecas( jogadorAtual, &numPecasFinalizadas ) ;

			if ( numPecasFinalizadas == 15 ) { /* condição de vitória */
				DPT_ValorPartida( &valorPartida ) ;
				VerificaCondicaoVitoriaEspecial( &valorPartida, jogadorAtual ) ;
				FimDeJogo( jogadorAtual, valorPartida ) ;
				MenuInicial( ) ;
			} /* if */
		} /* else */

		if ( posInicio < 1 || posInicio > 24 )
			BAR_RemovePeca( jogadorAtual ) ;
		else
			TAB_RemovePecaCasa( posInicio ) ;

		return 1 ;
	} /* Fim função: JOG Movimentar peça */

/***************************************************************************
*
*  Função: JOG Verifica se Jogador Pode Finalizar
*
*  ****/

	int PodeFinalizar ( CorPecas jogadorAtual )
	{
		int i = 1, a, n ;
		CorPecas c ;

		BAR_NumPecas ( jogadorAtual, &n ) ;
		
		if ( n > 0 )
			return 0 ;

		if ( jogadorAtual == Vermelha )
			i = 7 ;
		
		for ( a = 0 ; a < 18 ; i++, a++ ) {
			TAB_NumPecasCasa( i, &n ) ;
			if ( n > 0 ) {
				TAB_CorPecasCasa( i, &c ) ;
				if ( c == jogadorAtual )
					return 0 ;
			} /* if */
		} /* for */
		return 1 ;
	} /* Fim função: JOG Verifica se Jogador Pode Finalizar */

/***************************************************************************
*
*  Função: JOG Proximo Dado a ser Utilizado
*
*  ****/

	int ProxDado ( int *dados, int dAtual )
	{
		int i = 0 ;
		do {
			dAtual ++ ;
			i++ ;
			if ( dAtual > 3 )
				dAtual = 0 ;
		} /* do */ 
		while ( dados[dAtual] == 0 && i < 4 ) ;
		return dAtual ;
	} /* Fim função: JOG Proximo Dado a ser Utilizado */

/***************************************************************************
*
*  Função: JOG Casa Anterior Com Pecas
*
*  ****/

	int AntCasaComPeca ( int casaSelecionada, CorPecas cor )
	{
		int i, qtdPecasCasas, bar ;
		CorPecas coresPecasCasa ;
		BAR_NumPecas ( cor, &bar ) ;

		if ( bar > 0 ) {
			if ( cor == Vermelha )
				return 25 ;
			else 
				return 0 ;
		} /* if */
		for ( i = casaSelecionada-1 ; i > 0 ; i-- ) {
			TAB_NumPecasCasa( i, &qtdPecasCasas ) ;
			if ( qtdPecasCasas > 0 ) {
				// Se tiver peça na casa, ve a cor da peça
				TAB_CorPecasCasa( i, &coresPecasCasa ) ;
				if ( coresPecasCasa == cor )
					return i ;
			} /* if */
		} /* for */
		for ( i = 24 ; i >= casaSelecionada ; i-- ) {
			TAB_NumPecasCasa( i, &qtdPecasCasas ) ;
			if ( qtdPecasCasas > 0 ) {
				// Se tiver peça na casa, ve a cor da peça
				TAB_CorPecasCasa( i, &coresPecasCasa ) ;
				if ( coresPecasCasa == cor )
					return i ;
			} /* if */
		}  /* for */
	} /* Fim função: JOG Casa Anterior Com Pecas */

/***************************************************************************
*
*  Função: JOG Próxima Casa Com Pecas
*
*  ****/

	int ProxCasaComPeca ( int casaSelecionada, CorPecas cor )
	{
		int i, qtdPecasCasas, bar ;
		CorPecas coresPecasCasa ;
		BAR_NumPecas ( cor, &bar ) ;

		if ( bar > 0 ) {
			if ( cor == Vermelha )
				return 25 ;
			else 
				return 0 ;
		} /* if */

		for ( i = casaSelecionada ; i < 24 ; i++ ) {
			TAB_NumPecasCasa( i+1, &qtdPecasCasas ) ;
			if ( qtdPecasCasas > 0 ) {
				// Se tiver peça na casa, ve a cor da peça
				TAB_CorPecasCasa( i+1, &coresPecasCasa ) ;
				
				if ( coresPecasCasa == cor )
					return i+1 ;
			} /* if */
		} /* for */

		for ( i = 0 ; i < casaSelecionada ; i++ ) {
			TAB_NumPecasCasa( i+1, &qtdPecasCasas ) ;
			if ( qtdPecasCasas > 0 ) {
				// Se tiver peça na casa, ve a cor da peça
				TAB_CorPecasCasa( i+1, &coresPecasCasa ) ;
				if ( coresPecasCasa == cor )
					return i+1 ;
			} /* if */
		} /* for */
	} /* Fim função: JOG Próxima Casa Com Pecas */

/***************************************************************************
*
*  Função: JOG Imprimir Jogo
*
*  ****/

	void ImprimirJogo ( CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) 
	{
		int i, f ;
		int qtdPecasCasas[24], qtdPecasBarras[2], qtdPecasFinalizadas[2] ;
		CorPecas coresPecasCasas[24] ;

		// Salvar o tipo de peça da casa
		for ( i = 0 ; i < 24 ; i++ ) {
			TAB_NumPecasCasa( i+1, &qtdPecasCasas[i] ) ;
			if ( qtdPecasCasas[i] > 0 ) {
				// Se tiver peça na casa, ve a cor da peça
				TAB_CorPecasCasa( i+1, &coresPecasCasas[i] ) ;
			} /* if */
		} /* for */

		BAR_NumPecas ( Preta, &qtdPecasBarras[0] ) ;
		BAR_NumPecas ( Vermelha, &qtdPecasBarras[1] ) ;
		FIM_NumPecas ( Preta, &qtdPecasFinalizadas[0] ) ;
		FIM_NumPecas ( Vermelha, &qtdPecasFinalizadas[1] ) ;

		printf( "\n    " ) ;
		for ( i = 12 ; i > 6 ; i-- )
			ImprimeSetaSelecao( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "    " ) ;
		for ( ; i > 0 ; i-- )
			ImprimeSetaSelecao( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "\n  " ) ;
		printf( "/-----------------------------------------\\\n  " ) ;
		printf( "| " ) ;
		for ( i = 12 ; i > 6 ; i-- )
			ImprimeNumeroCasa( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "| | " ) ;
		for ( ; i > 0 ; i-- )
			ImprimeNumeroCasa( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "|\n  " ) ;
		printf( "|-------------------| |-------------------|\n  " ) ;

		for ( f = 1 ; f < 6 ; f ++ ) {
			printf( "| " ) ;
			for ( i = 12 ; i > 6 ; i-- ) {
				ImprimePeca( qtdPecasCasas[i-1], coresPecasCasas[i-1], f ) ;
				printf( "  " ) ;
			} /* for */
			printf( "|" ) ;
			ImprimePeca( qtdPecasBarras[0], Preta, f ) ;
			printf( "| " ) ;
			for ( ; i > 0 ; i-- ) {
				printf( " " ) ;
				ImprimePeca( qtdPecasCasas[i-1], coresPecasCasas[i-1], f ) ;
				printf( " " ) ;
			} /* for */
			printf( "|    " ) ;
			ImprimePeca( qtdPecasFinalizadas[1], Vermelha, f ) ;
			printf( "\n  " ) ;
		} /* for */

		printf( "|                   | |                   |\n  " ) ;
		printf( "|                   | |                   |\n  " ) ;

		for ( f = 5 ; f > 0 ; f -- ) {
			printf( "| " ) ;
			for ( i = 13 ; i < 19 ; i++ ) {
				ImprimePeca( qtdPecasCasas[i-1], coresPecasCasas[i-1], f ) ;
				printf( "  " ) ;
			} /* for */
			printf( "|" ) ;
			ImprimePeca( qtdPecasBarras[1], Vermelha, f ) ;
			printf( "| " ) ;
			for ( ; i < 25 ; i++ ) {
				printf( " " ) ;
				ImprimePeca( qtdPecasCasas[i-1], coresPecasCasas[i-1], f ) ;
				printf( " " ) ;
			} /* for */
			printf( "|    " ) ;
			ImprimePeca( qtdPecasFinalizadas[0], Preta, f ) ;
			printf( "\n  " ) ;
		} /* for */
		printf( "|-------------------| |-------------------|\n  " ) ;
		printf( "| " ) ;
		for ( i = 13 ; i < 19 ; i++ )
			ImprimeNumeroCasa( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "| | " ) ;
		for ( ; i < 25 ; i++ )
			ImprimeNumeroCasa( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "|\n  " ) ;
		printf( "\\-----------------------------------------/\n  " ) ;
		printf( "  " ) ;
		for ( i = 13 ; i < 19 ; i++ )
			ImprimeSetaSelecao( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
		printf( "    " ) ;
		for ( ; i < 25 ; i++ )
			ImprimeSetaSelecao( i, jogadorAtual, casaSelecionada, casaFixada, dados ) ;
	} /* Fim função: JOG Imprimir Jogo */

/***************************************************************************
*
*  Função: JOG Imprime peça
*
*  ****/

	void ImprimePeca ( int totalCasa, CorPecas cor, int posicao ) 
	{
		if ( posicao == 5 ) {
			if ( totalCasa - 4 > 9 )
				printf( "\b" ) ;
			if ( totalCasa > 5 )
				printf( "\b\033%s+%d\033[0m", cores[cor], totalCasa-4 ) ;
			else if ( totalCasa == 5 )
				printf( "\033%so\033[0m", cores[cor] ) ;
			else
				printf( " " ) ;
			return ;
		} /* if */

		if ( totalCasa >= posicao )
			printf( "\033%so\033[0m", cores[cor] ) ;
		else
			printf( " " ) ;
	} /* Fim função: JOG Imprime peça */

/***************************************************************************
*
*  Função: JOG Verifica se Casa é Apontada Por algum Dado
*
*  ****/

	int CasaApontadaPorDado ( int numeroCasa, CorPecas jogadorAtual, int casaFixada, int dados[4] ) 
	{
		int i, casa ;
		for ( i = 0 ; i < 4 ; i++ ) {
			casa = CasaSelecionada( jogadorAtual, casaFixada, dados[i] ) ;
			if ( dados[i] != 0 && numeroCasa == casa )
				return 1 ;
		} /* for */
		return 0 ;
	} /* Fim função: JOG Verifica se Casa é Apontada Por algum Dado */

/***************************************************************************
*
*  Função: JOG Imprime Numero da Casa
*
*  ****/

	void ImprimeNumeroCasa ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) {
		if ( numeroCasa == casaSelecionada )
			printf( "\033%s%02d\033[0m ", PRIMARIO, numeroCasa ) ;
		else if ( numeroCasa == casaFixada )
			printf( "\033%s%02d\033[0m ", TERCIARIO, numeroCasa ) ;
		else if ( CasaApontadaPorDado( numeroCasa, jogadorAtual, casaFixada, dados ) == 1 )
			printf( "\033%s%02d\033[0m ", SECUNDARIO, numeroCasa ) ;
		else
			printf( "%02d ", numeroCasa ) ;
	} /* Fim função: JOG Imprime Numero da Casa */

/***************************************************************************
*
*  Função: JOG Imprime seta de seleção de casa
*
*  ****/


	void ImprimeSetaSelecao ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) {
		char * tipo ;
		if ( numeroCasa == casaSelecionada )
			tipo = PRIMARIO ;
		else if ( numeroCasa == casaFixada )
			tipo = TERCIARIO ;
		else if ( CasaApontadaPorDado( numeroCasa, jogadorAtual, casaFixada, dados ) == 1 )
			tipo = SECUNDARIO ;
		else {
			printf( "   " ) ;
			return ;
		}
		
		if ( numeroCasa < 13 )
			printf( "\033%s\\/\033[0m ", tipo ) ;
		else
			printf( "\033%s/\\\033[0m ", tipo ) ;
	} /* Fim função: JOG Imprime seta de seleção de casa */

/***************************************************************************
*
*  Função: JOG Fim De Jogo
*
*  ****/

	void FimDeJogo ( CorPecas jogadorVencedor, int valorPartida )
	{
		TAB_DestruirTabuleiro( ) ;
		FIM_DestruirFinalizadas( ) ;
		DPT_DestruirDadoPontos( ) ;
		BAR_DestruirBarra( ) ;
		CLEAR_SCREEN ;
		printf( "\033%s", cores[jogadorVencedor] ) ;

		if ( jogadorVencedor == Preta ) {
			puts( "  __      __                    _           __      __                                     " ) ;
			puts( "  \\ \\    / /                   | |          \\ \\    / /                                     " ) ;
			puts( "   \\ \\  / /    ___   _ __    __| |   ___     \\ \\  / /    ___   _ __     ___    ___   _   _ " ) ;
			puts( "    \\ \\/ /    / _ \\ | '__|  / _` |  / _ \\     \\ \\/ /    / _ \\ | '_ \\   / __|  / _ \\ | | | |" ) ;
			puts( "     \\  /    |  __/ | |    | ( _| | |  __/      \\  /    |  __/ | | | | | ( __  |  __/ | |_| |" ) ;
			puts( "      \\/      \\___| |_|     \\__, _|  \\___|       \\/      \\___| |_| |_|  \\___|  \\___|  \\__, _|" ) ;												
		} /* if */
		else if ( jogadorVencedor == Vermelha ) {
			puts( "  __      __                                   _   _                __      __                                     " ) ;
			puts( "  \\ \\    / /                                  | | | |               \\ \\    / /                                     " ) ;
			puts( "   \\ \\  / /    ___   _ __   _ __ ___     ___  | | | |__     ___      \\ \\  / /    ___   _ __     ___    ___   _   _ " ) ;
			puts( "    \\ \\/ /    / _ \\ | '__| | '_ ` _ \\   / _ \\ | | | '_ \\   / _ \\      \\ \\/ /    / _ \\ | '_ \\   / __|  / _ \\ | | | |" ) ;
			puts( "     \\  /    |  __/ | |    | | | | | | |  __/ | | | | | | | ( _ ) |      \\  /    |  __/ | | | | | ( __  |  __/ | |_| |" ) ;
			puts( "      \\/      \\___| |_|    |_| |_| |_|  \\___| |_| |_| |_|  \\___/        \\/      \\___| |_| |_|  \\___|  \\___|  \\__, _|" ) ;
		} /* else if */

		printf( "\n  \t\t\t\tTotal de pontos obtidos na partida: %d\n  \n  ", valorPartida ) ;
		printf( "\n  \n  \033[0m  \tPressione qualquer tecla para voltar ao menu...\n  \n  " ) ;

		getch( ) ;
	} /* Fim função: JOG Imprime Vitória */


/***************************************************************************
*
*  Função: JOG Verifica Condicao Especial de Vitória
*
*  ****/

	void VerificaCondicaoVitoriaEspecial( int * valorPartida, CorPecas jogadorVencedor )
	{
		int fatorMultiplicador = 1, numPecasFinalizadas = 0, numPecasBarra = 0 ;
		CorPecas jogadorPerdedor = jogadorVencedor == Preta ? Vermelha : Preta ;

		FIM_NumPecas( jogadorPerdedor, &numPecasFinalizadas ) ;
		BAR_NumPecas( jogadorPerdedor, &numPecasBarra ) ;

		if ( numPecasFinalizadas == 0 ) /* Vitória por gamão */
			fatorMultiplicador = 2 ;
		if ( ( numPecasFinalizadas == 0 ) && ( numPecasBarra > 0 ) ) /* Vitória por backgammon */ 
			fatorMultiplicador = 3 ;

		*valorPartida = ( *valorPartida ) * fatorMultiplicador ;
	} /* Fim função: JOG Verifica Condicao Especial de Vitória */

/***************************************************************************
*
*  Função: JOG Trocar Opcao
*  ****/

	int TrocarOpcao( int opcaoSelecionada, int numOpcoes ) 
	{
		int ch = getch( ) ;
		switch ( ch ) {
			case 72: opcaoSelecionada -= 1 ; break ; /* seta para cima */
			case 80: opcaoSelecionada += 1 ; break ; /* seta para baixo */
		} ; /* switch */
		if ( opcaoSelecionada > numOpcoes )
			opcaoSelecionada = 0 ;
		else if ( opcaoSelecionada < 0 )
			opcaoSelecionada = 2 ;
		return opcaoSelecionada ;
	} /* Fim função: JOG Trocar Opcao */

/***************************************************************************
*
*  Função: JOG Casa Selecionada
*
*  ****/

	int CasaSelecionada( CorPecas jogadorAtual, int casaFixada, int dadoAtual )
	{
		if ( jogadorAtual == Vermelha )
			return casaFixada - dadoAtual ;
		return casaFixada + dadoAtual ;
	} /* Fim função: JOG Casa Selecionada */

/********** Fim do módulo de implementação: Módulo Jogo **********/