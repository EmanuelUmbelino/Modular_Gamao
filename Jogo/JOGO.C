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

	static void menuInicial ( void ) ;

	static void novoJogo ( void ) ;

	static void carregarJogo ( char * nomeJogo ) ;
 
	static void salvarJogo ( char * nomeJogo ) ;

	static void jogo ( CorPecas jogadorAtual ) ;

	static int movimentar ( int posInicio, int posFinal, CorPecas jogadorAtual ) ;

	static int podeFinalizar ( CorPecas jogadorAtual ) ;

	static int proxDado ( int *dados, int dAtual ) ;

	static int antDado (int *dados, int dAtual) ;

	static int antCasaDeCor ( int casaSelecionada, CorPecas cor ) ;

	static int proxCasaDeCor ( int casaSelecionada, CorPecas cor ) ;

	static void imprimirJogo ( CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void imprimeResto ( int totalCasa, CorPecas cor ) ;

	static void imprimePeca ( int totalCasa, CorPecas cor, int posicao ) ;

	static int temDadoNessaCasa ( int numeroCasa, CorPecas jogadorAtual, int casaFixada, int dados[4] ) ;

	static void imprimeNumeroCasa ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void imprimeSetaSelecao ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void imprimeVitoria ( CorPecas jogadorVencedor, int valorPartida ) ;

	static void inicializarEstruturas ( void );

	static void destruirEstruturas ( void );

	static void verificaCondicaoVitoriaEspecial( int * valorPartida , CorPecas jogadorVencedor ) ;

/*****  Código das funções exportadas pelo módulo  *****/



/***************************************************************************
*
*  Função: JOG Iniciar Jogo
*  ****/

	void JOG_IniciarJogo( void ) 
	{
		cores[Preta] = PRETO ;
		cores[Vermelha] = VERMELHO ;
		CLEAR_SCREEN ;
		menuInicial() ;

	} /* Fim função: JOG Iniciar Jogo */


/*****  Código das funções encapsuladas no módulo  *****/

	
/***************************************************************************
*
*  $FC Função: JOG Menu Inicial
*
*  ****/

	void menuInicial ( void ) {
		int ch1, ch2, opcaoSelecionada = 0 ;
		char nomeJogo[15] ;

		while(1){
			
			puts("   _____              __  __               ____  ");
			puts("  / ____|     /\\     |  \\/  |     /\\      / __ \\ ");
			puts(" | |  __     /  \\    | \\  / |    /  \\    | |  | |");
			puts(" | | |_ |   / /\\ \\   | |\\/| |   / /\\ \\   | |  | |");
			puts(" | |__| |  / ____ \\  | |  | |  / ____ \\  | |__| |");
			puts("  \\_____| /_/    \\_\\ |_|  |_| /_/    \\_\\  \\____/ ");

			printf("\n\n\t\t");
			if(opcaoSelecionada == 0) { printf("\033%s>",PRIMARIO); }
			printf(" Novo Jogo\033[0m");
			printf("\n\n\t\t");
			if(opcaoSelecionada == 1) { printf("\033%s>",PRIMARIO); }
			printf(" Carregar Jogo\033[0m");
			printf("\n\n\t\t");
			if(opcaoSelecionada == 2) { printf("\033%s>",PRIMARIO); }
			printf(" Sair\033[0m\n\n\n");
			printf("\n\n\t\t");
			ch1 = getch();
			ch2 = 0;
			
			CLEAR_SCREEN;

			if (ch1 == 0xE0) { // a scroll key was pressed
				ch2 = getch();
				// determine what it was
				switch(ch2)
				{
					case 72: opcaoSelecionada -= 1; break;
					case 80: opcaoSelecionada += 1; break;
				};
				if(opcaoSelecionada > 2){ opcaoSelecionada = 0 ; }
				else if(opcaoSelecionada < 0){ opcaoSelecionada = 2 ; }
			}
			else if(ch1 == 13){
				break;
			}
		}
		if(opcaoSelecionada == 0){
			novoJogo();
		}
		else if (opcaoSelecionada == 1)
		{
			CLEAR_SCREEN;
			printf("Insira o nome do jogo que deseja carregar.\n");
			scanf("%s",nomeJogo);
			carregarJogo(nomeJogo);
		}
	} /* Fim função: TAB Configuração Inicial */

/***************************************************************************
*
*  $FC Função: JOG Novo Jogo
*
*  ****/

	void novoJogo( void ){
		int dados[2];
		CorPecas jogadorInicial;
		dados[0]=0;dados[1]=0;

		CLEAR_SCREEN;

		inicializarEstruturas();
		
		printf("\n Sortear os 2 dados pra ver quem comeca\n\n");
		printf("\n Escolha quem sera o \033%sVERMELHO\033[0m",cores[Vermelha]);
		printf(" e quem sera o \033%sVERDE\033[0m\n\n",cores[Preta]);
		printf("\n Pressione qualquer tecla para sortear quem comeca\n\n");
		
		while(1){
			getch();
			
			DAD_JogarDado(&dados[0]);
			DAD_JogarDado(&dados[1]);
			
			CLEAR_SCREEN;

			printf("\n Sortear os 2 dados pra ver quem comeca\n");
			printf("\n \033%sVERMELHO\033[0m:  %d",cores[Vermelha],dados[0]);
			printf("\n \033%sVERDE\033[0m:  %d",cores[Preta],dados[1]);
			
			if(dados[0] == dados[1])
			{
				printf("\n\n Empatou...");
				printf("\n\n Pressione qualquer tecla para sortear novamente\n\n");
			} else 
			{
				if(dados[0] > dados[1]){
					jogadorInicial = Vermelha;
					printf("\n\n \033%sVERMELHO\033[0m comeca!",cores[jogadorInicial]) ;
				} else {
						jogadorInicial = Preta;
						printf("\n\n \033%sVERDE\033[0m comeca!",cores[jogadorInicial]) ;
				}
				break;
			}
		}
		
		printf("\n\n Pressione qualquer tecla para comecar o jogo\n\n") ;
		getch() ;
		jogo( jogadorInicial );
	}/* Fim função: JOG Novo Jogo */

/***************************************************************************
*
*  Função: Carregar Jogo
*
*  ****/

	void carregarJogo ( char * nomeJogo ) 
	{
		FILE * fp;
		int i, j, casa, numPecas, numPecasAux, valorPartida;
		CorPecas corPec = Neutro;
		char Jogo[1];
		
		inicializarEstruturas();

		fp = fopen(nomeJogo, "r");
		if (fp == NULL)
		{
			CLEAR_SCREEN;
			printf(" Nao foi possivel carregar o jogo %s!\n",nomeJogo);
			printf("\n\n Pressione qualquer tecla para voltar ao menu\n\n") ;
			getch() ;
			CLEAR_SCREEN;
			menuInicial();
		}
		else
		{
			while(fscanf(fp, "%s\n", Jogo)!=EOF)
			{
				if (strcmp(Jogo,"T")==0)
				{
					for(i=0 ; i<24 ; i++)
					{
						fscanf(fp,"%d %d %d\n",&casa,&numPecas, &corPec);
						TAB_NumPecasCasa( casa, &numPecasAux ) ;
						for(j=0; j<numPecasAux; j++)
						{
							TAB_RemovePecaCasa( casa ); 
						}
						for(j=0; j<numPecas; j++)
						{
							TAB_InserePecaCasa(casa, corPec); 
						}
					}
				}
				else if (strcmp(Jogo,"B")==0)
				{
					for(i=0 ; i<2 ; i++)
					{
						fscanf(fp,"%d %d\n", &corPec, &numPecas);
						for(j=0; j<numPecas; j++)
							BAR_InserePeca(corPec);
					}
				}
				else if (strcmp(Jogo,"F")==0)
				{
					for(i=0 ; i<2 ; i++)
					{
						fscanf(fp,"%d %d\n", &corPec, &numPecas);
						for(j=0; j<numPecas; j++)
							FIM_FinalizarPeca(corPec);
					}
				}
				else if (strcmp(Jogo,"V")==0)
				{
					fscanf(fp,"%d\n", &valorPartida);
				}
				else
				{
					fscanf(fp,"%d\n", &corPec);
				}
			}
			DPT_CarregaDadoPontos(corPec, valorPartida);
			jogo(corPec);
		}
	}

/***************************************************************************
*
*  Função: Salvar Jogo
*
****************************************************************************/

	void salvarJogo ( char * nomeJogo ) {
		FILE * fp;
		int i, num;
		CorPecas  podeDobrar, corPec;
		fp = fopen(nomeJogo, "w");
		if ( fp == NULL )
		{
			printf("Nao foi possivel salvar o jogo!\n") ;
		}
		else
		{	
			corPec = podeDobrar = Neutro;
			fprintf(fp, "T\n");
			for (i=1 ; i<25 ; i++)
			{
				TAB_NumPecasCasa(i, &num);
				TAB_CorPecasCasa( i,  &corPec );
				fprintf(fp, "%d %d %d\n", i, num, corPec);
			}
			fprintf(fp, "B\n");
			BAR_NumPecas(Vermelha, &num);
			fprintf(fp, "%d %d\n",1, num);
			BAR_NumPecas(Preta, &num);
			fprintf(fp, "%d %d\n",0, num);
			
			fprintf(fp, "F\n");
			FIM_NumPecas(Vermelha, &num);
			fprintf(fp, "%d %d\n",1, num);
			FIM_NumPecas(Preta, &num);
			fprintf(fp, "%d %d\n",0, num);

			DPT_ValorPartida(&num);
			fprintf(fp, "V\n%d\n", num);
			DPT_QuemPodeDobrar(&podeDobrar);
			if (podeDobrar == Vermelha)
				fprintf(fp, "D\n%d\n",1);
			else
				fprintf(fp, "D\n%d\n",0);
			fclose(fp);
		}
	}

/***************************************************************************
*
*  Função: Jogo
*
****************************************************************************/

void jogo ( CorPecas jogadorAtual ){
	int casaSelecionada, casaFixada, dAtual = 0, ch, i, valorPartida;
	int ch1, ch2, opcaoSelecionada = 0;
	CorPecas podeDobrar;
	Passo passo = JogarDado;
	char nomeJogo[15];
	int dados[4];

	for(i = 0; i < 4; i ++){
		dados[i] = 0;
	}

	DPT_ValorPartida(&valorPartida);

	if(jogadorAtual == Vermelha) {
		casaSelecionada = antCasaDeCor( 0, jogadorAtual );
	} else {
		casaSelecionada = proxCasaDeCor( 0, jogadorAtual );
	}
	
	casaFixada = casaSelecionada;
	podeDobrar = Neutro;

	while(1){
		CLEAR_SCREEN;
		if(jogadorAtual == Vermelha){
			printf("Vez do \033%sVERMELHO\033[0m",cores[jogadorAtual]);
		} else {
			printf("Vez do \033%sVERDE\033[0m",cores[jogadorAtual]);
		}
		printf("\nValor da partida: %d",valorPartida);
		imprimirJogo( jogadorAtual, casaSelecionada, casaFixada, dados );
		
		printf("\nJogadas Disponiveis:");
		for(i = 0; i < 4; i ++){
			if(dados[i] > 0){
				printf(" %d ",dados[i]);
			}
		}

		if(passo == JogarDado){
			printf("\nEspaco - jogar dados");
			printf("\nD - Dobrar pontos");
		}
		else if(passo == EscolherPeca){
			printf("\nZ e X - manipulam a seta");
			printf("\nEspaco - selecionar peca");
		}
		else if(passo == EscolherDado){
			printf("\nZ - trocar dado");
			printf("\nEspaco - confirmar jogada");
			printf("\nEsc - voltar para selecao de peca");
		}
	
		printf("\nS - Salvar jogo");
		
		if(passo != EscolherDado) {
			printf("\nEsc - Fechar jogo");
		}
		
		ch = getch();
		if(ch == 'z' ) { // Z
			if(passo == EscolherPeca){
				casaSelecionada = proxCasaDeCor( casaSelecionada, jogadorAtual );
				casaFixada = casaSelecionada;
			} 
			else if(passo == EscolherDado) {
				dAtual = proxDado (dados, dAtual);

				if(jogadorAtual == Vermelha) {
					casaSelecionada = casaFixada - dados[dAtual];
				} else {
					casaSelecionada = casaFixada + dados[dAtual];
				}
			}
		}
		else if(ch == 'x') { // Xq
			if(passo == EscolherPeca){
				casaSelecionada = antCasaDeCor( casaSelecionada, jogadorAtual );
				casaFixada = casaSelecionada;
			} 
			else if(passo == EscolherDado) {
				dAtual = antDado (dados, dAtual);

				if(jogadorAtual == Vermelha) {
					casaSelecionada = casaFixada - dados[dAtual];
				} else {
					casaSelecionada = casaFixada + dados[dAtual];
				}
			}
		}
		else if(ch == 32){ // Espaco
			if(passo == JogarDado) {
				DAD_JogarDado(&dados[0]) ; 
				DAD_JogarDado(&dados[1]) ;

				if(dados[0] == dados[1]){
					dados[2] = dados[0] ;
					dados[3] = dados[0] ;
				}

				passo = EscolherPeca;
				if(casaFixada < 1 || casaFixada > 24){
					passo = EscolherDado;
					if(jogadorAtual == Vermelha) {
						casaSelecionada = casaFixada - dados[dAtual];
					} else {
						casaSelecionada = casaFixada + dados[dAtual];
					}
				}
			}
			else if(passo == EscolherPeca){
				if(dados[dAtual] == 0) {
					dAtual = proxDado (dados, dAtual);
				}
				if(jogadorAtual == Vermelha) {
					casaSelecionada = casaFixada - dados[dAtual];
				} else {
					casaSelecionada = casaFixada + dados[dAtual];
				}
				passo = EscolherDado;
			}
			else if(passo == EscolherDado) {
				if ( movimentar( casaFixada, casaSelecionada, jogadorAtual ) == 1 ) {
					dados[dAtual] = 0;
					dAtual = proxDado (dados, dAtual);

					if(dados[dAtual] == 0) {
						jogadorAtual = !jogadorAtual;
						passo = JogarDado;
					}
					else {
						passo = EscolherPeca;
					}
					if(jogadorAtual == Vermelha) {
						casaSelecionada = antCasaDeCor( 0, jogadorAtual );
					} else {
						casaSelecionada = proxCasaDeCor( 0, jogadorAtual );
					}
					casaFixada = casaSelecionada;
				}
			}
		} 
		else if(ch == 27){ // Esc
			if(passo == EscolherDado){
				dAtual = 0;
				casaSelecionada = casaFixada;
				passo = EscolherPeca;
			}
			else
			{
				CLEAR_SCREEN;
				printf("Se o jogo nao foi salvo ele nao podera ser continuado de onde parou.\nDeseja continuar?[S / N]\n");
				ch = getch();
				if (ch == 's')
				{
					break;
				}
				else
				{
					continue;
				}
			}
		}
		else if (ch == 's')
		{
			CLEAR_SCREEN;
			printf("Insira o nome do jogo para ser salvo (Max de 15 caracteres)..\n");
			scanf("%s",nomeJogo) ;
			salvarJogo(nomeJogo);
		}
		else if (ch == 'd')
		{
			if( passo == JogarDado ){
				if (jogadorAtual == podeDobrar || podeDobrar == Neutro)
				{
					CLEAR_SCREEN;

					while(1){
						if ( jogadorAtual == Vermelha )
						{
							printf("O jogador \033%sVERMELHO\033[0m te desafiou a dobrar os pontos\n", cores[Vermelha]);
						}
						else if ( jogadorAtual == Preta )
						{
							printf("O jogador \033%sVERDE\033[0m te desafiou a dobrar os pontos\n", cores[Preta]);
						}
						
						if(opcaoSelecionada == 0) { printf("\033%s>",PRIMARIO); }
						else{ printf(" "); }
						printf(" Aceitar\033[0m\n");
						if(opcaoSelecionada == 1) { printf("\033%s>",PRIMARIO); }
						else{ printf(" "); }
						printf(" Recusar\033[0m\n");
						ch1 = getch();
						ch2 = 0;
						CLEAR_SCREEN;
						if (ch1 == 0xE0) {
							ch2 = getch();
							switch (ch2)
							{
								case 72: opcaoSelecionada -= 1; break;
								case 80: opcaoSelecionada += 1; break;
							};
							if(opcaoSelecionada > 1){ opcaoSelecionada = 0 ; }
							else if(opcaoSelecionada < 0){ opcaoSelecionada = 1 ; }
						}
						else if (ch1 == 13)
						{
							break;
						}
					}
					if (opcaoSelecionada == 0)
					{
						DPT_DobraPontos(jogadorAtual);
						DPT_QuemPodeDobrar(&podeDobrar);
						DPT_ValorPartida(&valorPartida);
					} else if (opcaoSelecionada == 1)
					{
						DPT_ValorPartida(&valorPartida);
						destruirEstruturas() ;
						imprimeVitoria(jogadorAtual, valorPartida);
						menuInicial();
					}
				}
				else
				{
					CLEAR_SCREEN;
					printf("Voce nao pode dobrar os pontos dessa partida.\nPressione qualquer tecla para continuar...\n");
					getch();
				}
			}
		}
		else if (ch == 'p')
		{
			dados[0] = 0;
			dados[1] = 0;
			dados[2] = 0;
			dados[3] = 0;
			jogadorAtual = !jogadorAtual;
			passo = JogarDado;
			casaSelecionada = proxCasaDeCor( 0, jogadorAtual );
			casaFixada = casaSelecionada;

		}
		else printf("\n\n%c", ch);
	}
}

/***************************************************************************
*
*  Função: Movimentar peça
*
****************************************************************************/

int movimentar ( int posInicio, int posFinal, CorPecas jogadorAtual ) {
	int numPecasFinal, numPecasFinalizadas, valorPartida;
	CorPecas corFinal;

	if(jogadorAtual == Vermelha && posFinal < 1 && !podeFinalizar(jogadorAtual)){
		return 0;
	}
	
	if(jogadorAtual == Preta && posFinal > 24 && !podeFinalizar(jogadorAtual)){
		return 0;
	}
	
	if(posFinal >= 1 && posFinal <= 24){
		
		TAB_NumPecasCasa(posFinal,&numPecasFinal);
		
		if(numPecasFinal > 0){
			TAB_CorPecasCasa(posFinal,&corFinal);
			if(corFinal != jogadorAtual) {
				if(numPecasFinal > 1){
					return 0;
				}
				TAB_RemovePecaCasa(posFinal);
				BAR_InserePeca(corFinal);
			}
		}

		TAB_InserePecaCasa( posFinal , jogadorAtual );
	}
	else {
		FIM_FinalizarPeca( jogadorAtual ) ;
		FIM_NumPecas( jogadorAtual , &numPecasFinalizadas ) ;

		if ( numPecasFinalizadas == 15 ) //condição de vitória
		{
			DPT_ValorPartida( &valorPartida ) ;
			verificaCondicaoVitoriaEspecial( &valorPartida, jogadorAtual ) ;
			destruirEstruturas() ;
			imprimeVitoria( jogadorAtual, valorPartida ) ;
			menuInicial() ;

		}
	}

	if(posInicio < 1 || posInicio > 24){
		BAR_RemovePeca(jogadorAtual);
	} else {
		TAB_RemovePecaCasa(posInicio);
	}

	return 1;
}

/***************************************************************************
*
*  Função: Finalização da peça
*
****************************************************************************/

int podeFinalizar ( CorPecas jogadorAtual ) {
	int i = 1, a, n;
	CorPecas c;

	BAR_NumPecas (jogadorAtual, &n) ;
	
	if( n > 0 ) { return 0; }

	if( jogadorAtual == Vermelha ) { i = 7; }
	
	for (a = 0; a < 18; i++, a++){
		TAB_NumPecasCasa(i,&n);
		if(n > 0){
			TAB_CorPecasCasa(i,&c);
			if(c == jogadorAtual){
				return 0 ;
			}
		}
	}
	return 1 ;
}

/***************************************************************************
*
*  Função: 
*
****************************************************************************/

int proxDado ( int *dados, int dAtual ) {
	int i = 0;
	do {
		dAtual ++;
		i++;
		if(dAtual > 3){
			dAtual = 0;
		}
	} while(dados[dAtual] == 0 && i < 4);
	return dAtual ;
}

int antDado (int *dados, int dAtual) {
	int i = 0;
	do {
		dAtual --;
		i++;
		if(dAtual < 0){
			dAtual = 3;
		}
	} while(dados[dAtual] == 0 && i < 4);
	return dAtual ;
}

int antCasaDeCor ( int casaSelecionada, CorPecas cor ) {
	int i, qtdPecasCasas, bar;
	CorPecas coresPecasCasa;
	BAR_NumPecas (cor, &bar) ;
	if ( bar > 0 ) {
		if ( cor == Vermelha )
			return 25 ;
		else 
			return 0 ;
	}
	for(i = casaSelecionada-1; i > 0; i--){
		TAB_NumPecasCasa(i,&qtdPecasCasas);
		if(qtdPecasCasas > 0){
			// Se tiver peça na casa, ve a cor da peça
			TAB_CorPecasCasa(i,&coresPecasCasa);
			if(coresPecasCasa == cor){
				return i;
			}
		}
	}
	for(i = 24; i >= casaSelecionada; i--){
		TAB_NumPecasCasa(i,&qtdPecasCasas);
		if(qtdPecasCasas > 0){
			// Se tiver peça na casa, ve a cor da peça
			TAB_CorPecasCasa(i,&coresPecasCasa);
			if(coresPecasCasa == cor){
				return i;
			}
		}
	} 
}

int proxCasaDeCor ( int casaSelecionada, CorPecas cor ) {
	int i, qtdPecasCasas, bar;
	CorPecas coresPecasCasa ;
	BAR_NumPecas (cor, &bar) ;

	if ( bar > 0 ) {
		if ( cor == Vermelha )
			return 25 ;
		else 
			return 0 ;
	}

	for( i = casaSelecionada; i < 24; i++){
		TAB_NumPecasCasa(i+1, &qtdPecasCasas);
		if(qtdPecasCasas > 0){
			// Se tiver peça na casa, ve a cor da peça
			TAB_CorPecasCasa(i+1, &coresPecasCasa);
			
			if(coresPecasCasa == cor){
				return i+1;
			}
		}
	}

	for(i = 0; i < casaSelecionada; i++){
		TAB_NumPecasCasa(i+1,&qtdPecasCasas);
		if(qtdPecasCasas > 0){
			// Se tiver peça na casa, ve a cor da peça
			TAB_CorPecasCasa(i+1,&coresPecasCasa);
			if(coresPecasCasa == cor){
				return i+1;
			}
		}
	} 
}

/***************************************************************************
*
*  Função: Imprimir Jogo
*
****************************************************************************/

void imprimirJogo ( CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) 
{
	int i,f;
	int qtdPecasCasas[24], qtdPecasBarras[2], qtdPecasFinalizadas[2];
	CorPecas coresPecasCasas[24];

	// Salvar o tipo de peça da casa
	for(i = 0; i < 24; i++){
		TAB_NumPecasCasa(i+1,&qtdPecasCasas[i]);
		if(qtdPecasCasas[i] > 0){
			// Se tiver peça na casa, ve a cor da peça
			TAB_CorPecasCasa(i+1,&coresPecasCasas[i]);
		}
	}

	BAR_NumPecas (Preta, &qtdPecasBarras[0]) ;
	BAR_NumPecas (Vermelha, &qtdPecasBarras[1]) ;
	FIM_NumPecas (Preta, &qtdPecasFinalizadas[0]) ;
	FIM_NumPecas (Vermelha, &qtdPecasFinalizadas[1]) ;

	printf("\n  ");
	for(i = 12; i > 6; i--){ 
		imprimeSetaSelecao(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("    ");
	for(; i > 0; i--){
		imprimeSetaSelecao(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("\n");
	printf("/-----------------------------------------\\\n");
	printf("| ");
	for(i = 12; i > 6; i--){
		imprimeNumeroCasa(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("| | ");
	for(; i > 0; i--){
		imprimeNumeroCasa(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("|\n");
	printf("|-------------------| |-------------------|\n");

	for(f = 1; f < 6; f ++){
		printf("| ");
		for(i = 12; i > 6; i--){
			imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
			printf("  ");
		}
		printf("|");
		imprimePeca(qtdPecasBarras[0],Preta,f);
		printf("| ");
		for(; i > 0; i--){
			printf(" ");
			imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
			printf(" ");
		}
		printf("|    ");
		imprimePeca(qtdPecasFinalizadas[1],Vermelha,f);
		printf("\n");
	}

	printf("|                   | |                   |\n");
	printf("|                   | |                   |\n");

	for(f = 5; f > 0 ; f --){
		printf("| ");
		for(i = 13; i < 19; i++){
			imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
			printf("  ");
		}
		printf("|");
		imprimePeca(qtdPecasBarras[1],Vermelha,f);
		printf("| ");
		for(; i < 25; i++){
			printf(" ");
			imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
			printf(" ");
		}
		printf("|    ");
		imprimePeca(qtdPecasFinalizadas[0],Preta,f);
		printf("\n");
	}
	printf("|-------------------| |-------------------|\n");
	printf("| ");
	for(i = 13; i < 19; i++){
		imprimeNumeroCasa(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("| | ");
	for(; i < 25; i++){
		imprimeNumeroCasa(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("|\n");
	printf("\\-----------------------------------------/\n");
	printf("  ");
	for(i = 13; i < 19; i++){
		imprimeSetaSelecao(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
	printf("    ");
	for(; i < 25; i++){
		imprimeSetaSelecao(i, jogadorAtual, casaSelecionada, casaFixada, dados);
	}
} /* Fim função: JOG Imprimir Jogo */

/***************************************************************************
*
*  Função: Imprimir resto
*
****************************************************************************/

void imprimeResto ( int totalCasa, CorPecas cor ) {
	if( totalCasa - 4 > 9){
		printf("\b");
	}
	if(totalCasa > 5){
		printf("\b\033%s+%d\033[0m",cores[cor],totalCasa-4);
	} else if(totalCasa == 5) {
		printf("\033%so\033[0m",cores[cor]);
	} else{
		printf(" ");
	}
}

/***************************************************************************
*
*  Função: Imprimir peça
*
****************************************************************************/

void imprimePeca ( int totalCasa, CorPecas cor, int posicao ) {
	if(posicao == 5){
		imprimeResto(totalCasa,cor);
		return;
	}
	if(totalCasa >= posicao){
		printf("\033%so\033[0m",cores[cor]);
	} else{
		printf(" ");
	}
}

/***************************************************************************
*
*  Função: Verifica se tem peca na casa
*
****************************************************************************/

int temDadoNessaCasa ( int numeroCasa, CorPecas jogadorAtual, int casaFixada, int dados[4] ) {
	int i, casa;
	for(i = 0; i < 4; i++){
		if(jogadorAtual == Vermelha) {
			casa = casaFixada - dados[i];
		} else {
			casa = casaFixada + dados[i];
		}
		if(dados[i] != 0 && numeroCasa == casa)
			return 1;
	}
	return 0;
}

/***************************************************************************
*
*  Função: Imprimi Numero da casa
*
****************************************************************************/

void imprimeNumeroCasa ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) {
	if(numeroCasa == casaSelecionada){
		printf("\033%s%02d\033[0m ",PRIMARIO,numeroCasa);
	} else if(numeroCasa == casaFixada){
		printf("\033%s%02d\033[0m ",TERCIARIO,numeroCasa);
	} else if(temDadoNessaCasa(numeroCasa, jogadorAtual, casaFixada, dados) == 1){
		printf("\033%s%02d\033[0m ",SECUNDARIO,numeroCasa);
	} else{
		printf("%02d ",numeroCasa);
	}
}

/***************************************************************************
*
*  Função: Imprime seta de seleção de casa
*
****************************************************************************/

void imprimeSetaSelecao ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) {
	if(numeroCasa == casaSelecionada){
		if(numeroCasa < 13){
			printf("\033%s\\/\033[0m ",PRIMARIO);
		} else {
      		printf("\033%s/\\\033[0m ",PRIMARIO);
		}
	} else if(numeroCasa == casaFixada){
		if(numeroCasa < 13){
			printf("\033%s\\/\033[0m ",TERCIARIO);
		} else {
      		printf("\033%s/\\\033[0m ",TERCIARIO);
		}
	} else if(temDadoNessaCasa(numeroCasa, jogadorAtual, casaFixada, dados) == 1){
		if(numeroCasa < 13){
			printf("\033%s\\/\033[0m ",SECUNDARIO);
		} else {
      		printf("\033%s/\\\033[0m ",SECUNDARIO);
		}
	} else{
		printf("   ");
	}
}

/***************************************************************************
*
*  Função: Imprime Vitória
*
****************************************************************************/

void imprimeVitoria ( CorPecas jogadorVencedor, int valorPartida )
{
	CLEAR_SCREEN ;
	printf("\033%s", cores[jogadorVencedor]) ;

	if ( jogadorVencedor == Preta )
	{
		puts("  __      __                    _           __      __                                     ") ;
		puts("  \\ \\    / /                   | |          \\ \\    / /                                     ") ;
		puts("   \\ \\  / /    ___   _ __    __| |   ___     \\ \\  / /    ___   _ __     ___    ___   _   _ ") ;
		puts("    \\ \\/ /    / _ \\ | '__|  / _` |  / _ \\     \\ \\/ /    / _ \\ | '_ \\   / __|  / _ \\ | | | |") ;
		puts("     \\  /    |  __/ | |    | (_| | |  __/      \\  /    |  __/ | | | | | (__  |  __/ | |_| |") ;
		puts("      \\/      \\___| |_|     \\__,_|  \\___|       \\/      \\___| |_| |_|  \\___|  \\___|  \\__,_|") ;												
	}
	else if ( jogadorVencedor == Vermelha )
	{
		puts("  __      __                                   _   _                __      __                                     ") ;
		puts("  \\ \\    / /                                  | | | |               \\ \\    / /                                     ") ;
		puts("   \\ \\  / /    ___   _ __   _ __ ___     ___  | | | |__     ___      \\ \\  / /    ___   _ __     ___    ___   _   _ ") ;
		puts("    \\ \\/ /    / _ \\ | '__| | '_ ` _ \\   / _ \\ | | | '_ \\   / _ \\      \\ \\/ /    / _ \\ | '_ \\   / __|  / _ \\ | | | |") ;
		puts("     \\  /    |  __/ | |    | | | | | | |  __/ | | | | | | | (_) |      \\  /    |  __/ | | | | | (__  |  __/ | |_| |") ;
		puts("      \\/      \\___| |_|    |_| |_| |_|  \\___| |_| |_| |_|  \\___/        \\/      \\___| |_| |_|  \\___|  \\___|  \\__,_|") ;
                                                                                                
	}

	printf("\n\t\t\t\tTotal de pontos obtidos na partida: %d\n\n", valorPartida ) ;
	printf("\n\n\033[0m  \tPressione qualquer tecla para voltar ao menu...\n\n") ;

	getch() ;
	CLEAR_SCREEN ;
}

void verificaCondicaoVitoriaEspecial( int * valorPartida , CorPecas jogadorVencedor )
{
	int fatorMultiplicador = 1, numPecasFinalizadas = 0, numPecasBarra = 0 ;

	CorPecas jogadorPerdedor = jogadorVencedor == Preta ? Vermelha : Preta ;

	FIM_NumPecas( jogadorPerdedor , &numPecasFinalizadas ) ;
	BAR_NumPecas( jogadorPerdedor , &numPecasBarra ) ;

	// Vitória por gamão
	if ( numPecasFinalizadas == 0 ) fatorMultiplicador = 2 ;
	
	// Vitória por backgammon
	if ( ( numPecasFinalizadas == 0 ) && ( numPecasBarra > 0 ) ) fatorMultiplicador = 3 ;

	*valorPartida = ( *valorPartida ) * fatorMultiplicador ;
}

void inicializarEstruturas ( void )
{
	TAB_CriarTabuleiro() ;
	FIM_CriarFinalizadas() ;
	DPT_CriarDadoPontos() ;
	BAR_CriarBarra() ;
}


void destruirEstruturas ( void )
{
	TAB_DestruirTabuleiro() ;
	FIM_DestruirFinalizadas() ;
	DPT_DestruirDadoPontos() ;
	BAR_DestruirBarra() ;
}
