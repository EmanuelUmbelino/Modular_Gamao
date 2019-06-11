
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "TABULEIRO.H"
#include "PECASCAPTURADAS.H"
#include "PECASFINALIZADAS.H"
#include "DADO.H"
#include "DADOPONTOS.H"
#include "COR.H"
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
#define SECUNDARIO "[1;34m"
#define TERCIARIO "[1;33m"

	static char *cores[2];

/***** Protótipos das funções encapuladas no módulo *****/

	static void menuInicial ( void ) ;

	static void novoJogo ( void ) ;

	static void jogo ( CorPecas jogadorAtual ) ;

	static int movimentar ( int casaFixada, int casaSelecionada, CorPecas jogadorAtual ) ;

	static int proxCasaDeCor ( int casaSelecionada, CorPecas cor ) ;

	static void imprimirJogo ( CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void imprimeResto ( int totalCasa, CorPecas cor ) ;

	static void imprimePeca ( int totalCasa, CorPecas cor, int posicao ) ;

	static int temDadoNessaCasa( int numeroCasa, CorPecas jogadorAtual, int casaFixada, int dados[4] ) ;

	static void imprimeNumeroCasa ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void imprimeSetaSelecao ( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) ;

	static void salvarJogo ( void ) ;

	static void carregarJogo ( char * nomeJogo ) ; 

/***************************************************************************
*
*  Função: JOG Iniciar Jogo
*  ****/

	void JOG_IniciarJogo( void ) 
	{
		cores[Preta] = PRETO;
		cores[Vermelha] = VERMELHO;
		TAB_CriarTabuleiro();
		FIM_CriarFinalizadas();
		BAR_CriarBarra();
		CLEAR_SCREEN;
		menuInicial();

	} /* Fim função: JOG Iniciar Jogo */

void menuInicial() {
	int ch1, ch2, opcaoSelecionada = 0;
	char nomeJogo[15];
	while(1){
		printf("\n      G A M A O \n\n  ");
		if(opcaoSelecionada == 0) { printf("\033%s>",PRIMARIO); }
		else{ printf(" "); }
		printf(" Novo Jogo\033[0m\n  ");
		if(opcaoSelecionada == 1) { printf("\033%s>",PRIMARIO); }
		else{ printf(" "); }
		printf(" Carregar Jogo\033[0m\n  ");
		if(opcaoSelecionada == 2) { printf("\033%s>",PRIMARIO); }
		else{ printf(" "); }
		printf(" Sair\033[0m\n\n\n");
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
}

void novoJogo(){
	int dados[2];
	CorPecas jogadorInicial;
	dados[0]=0;dados[1]=0;
	CLEAR_SCREEN;
	printf("\n Sortear os 2 dados pra ver quem comeca\n\n");
	printf("\n Escolha quem sera o \033%sVERMELHO\033[0m",cores[Vermelha]);
	printf(" e quem sera o \033%sVERDE\033[0m\n\n",cores[Preta]);
	printf("\n Pressione qualquer tecla para sortear quem comeca\n\n");
	while(1){
		getch();
		DAD_JogarDado(&dados[0]);DAD_JogarDado(&dados[1]);
		CLEAR_SCREEN;
		printf("\n Sortear os 2 dados pra ver quem comeca\n");
		printf("\n \033%sVERMELHO\033[0m:  %d",cores[Vermelha],dados[0]);
		printf("\n \033%sVERDE\033[0m:  %d",cores[Preta],dados[1]);
		if(dados[0] == dados[1]){
			printf("\n\n Empatou...");
			printf("\n\n Pressione qualquer tecla para sortear novamente\n\n");
		} else {
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
}

void carregarJogo ( char * nomeJogo ) 
{
	FILE * fp;
	int i, j, casa, numPecas, numPecasAux, valorPartida;
	CorPecas corPec = Neutro;
	char Jogo[1];
	
	fp = fopen(nomeJogo, "r");
	if (fp == NULL)
	{
		CLEAR_SCREEN;
		printf("Nao foi possivel carregar o jogo %s!\n",nomeJogo);
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
				DPT_SetValorPartida(&valorPartida);
			}
			else
			{
				 fscanf(fp,"%d\n", &corPec);
				 DPT_SetQuemPodeDobrar(&corPec);
			}
		}
		jogo(corPec);
	}
}

void salvarJogo ( char * nomeJogo ){
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
		FIM_QuantidadeFinalizada(Vermelha, &num);
		fprintf(fp, "%d %d\n",1, num);
		FIM_QuantidadeFinalizada(Preta, &num);
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

void jogo( CorPecas jogadorAtual ){
	int casaSelecionada, casaFixada, passo = 0, dAtual = 0, ch, i;
	char nomeJogo[15];
	int dados[4];
	for(i = 0; i < 4; i ++){
		dados[i] = 0;
	}
	casaSelecionada = proxCasaDeCor( 0, jogadorAtual );
	casaFixada = casaSelecionada;
	while(1){
		CLEAR_SCREEN;
		if(jogadorAtual == Vermelha){
			printf("\nVez do \033%sVERMELHO\033[0m\n",cores[jogadorAtual]);
		} else {
			printf("\nVez do \033%sVERDE\033[0m\n",cores[jogadorAtual]);
		}
		imprimirJogo( jogadorAtual, casaSelecionada, casaFixada, dados );
		
		printf("\nJogadas Disponiveis:");
		for(i = 0; i < 4; i ++){
			if(dados[i] > 0){
				printf(" %d ",dados[i]);
			}
		}
		if(passo == 0){
			printf("\nEspaco - jogar dados\n");
		}
		else if(passo == 1){
			printf("\nZ - proxima peca");
			printf("\nEspaco - selecionar peca\n");
		}
		else if(passo == 2){
			printf("\nZ - trocar dado");
			printf("\nEspaco - confirmar jogada\n");
			printf("\nEsc - voltar para selecao de peca\n");
		}

		ch = getch();
		if(ch == 122) { // Z
			if(passo == 1){
				casaSelecionada = proxCasaDeCor( casaSelecionada, jogadorAtual );
				casaFixada = casaSelecionada;
			} 
			else if(passo == 2) {
				do {
					dAtual ++;
					if(dAtual > 3){
						dAtual = 0;
					}
				} while(dados[dAtual] == 0);

				if(jogadorAtual == Vermelha) {
					casaSelecionada = casaFixada - dados[dAtual];
				} else {
					casaSelecionada = casaFixada + dados[dAtual];
				}
			}
		}
		else if(ch == 32){ // Espaco
			if(passo == 0) {
				DAD_JogarDado(&dados[0]) ; DAD_JogarDado(&dados[1]) ;
				if(dados[0] == dados[1]){
					dados[2] = dados[0];
					dados[3] = dados[0];
				}
				passo = 1;
			}
			else if(passo == 1){
				if(dados[dAtual] == 0) dAtual = !dAtual;
				if(jogadorAtual == Vermelha) {
					casaSelecionada = casaFixada - dados[dAtual];
				} else {
					casaSelecionada = casaFixada + dados[dAtual];
				}
				passo = 2;
			}
			else if(passo == 2) {
				if ( movimentar( casaFixada, casaSelecionada, jogadorAtual ) == 1 ) {
					dados[dAtual] = 0;
					i = 0;
					do {
						dAtual ++;
						i++;
						if(dAtual > 3){
							dAtual = 0;
						}
					} while(dados[dAtual] == 0 && i < 3);

					if(dados[dAtual] == 0) {
						if(jogadorAtual == Vermelha) {
							jogadorAtual = Preta;
						} else {
							jogadorAtual = Vermelha;
						}
						passo = 0;
					}
					else {
						passo = 1;
					}
				}
				casaSelecionada = proxCasaDeCor( 0, jogadorAtual );
				casaFixada = casaSelecionada;
			}
		} 
		else if(ch == 27){ // Esc
			if(passo == 2){
				dAtual = 0;
				casaSelecionada = casaFixada;
				passo = 1;
			}
		}
		else if (ch == 115) // S
		{
			CLEAR_SCREEN;
			printf("Insira o nome do jogo para ser salvo (Max de 15 caracteres)..\n");
			scanf("%s",nomeJogo) ;
			salvarJogo(nomeJogo);
		}
	}
}

int movimentar ( int casaFixada, int casaSelecionada, CorPecas jogadorAtual ) {
	int numPecasSelecionada;
	CorPecas corSelecionada; 
	if(casaSelecionada > 24 || casaSelecionada < 0) {
		return 0;
	}
	TAB_NumPecasCasa(casaSelecionada,&numPecasSelecionada);
	if(numPecasSelecionada > 0){
		TAB_CorPecasCasa(casaSelecionada,&corSelecionada);
		if(corSelecionada != jogadorAtual) {
			if(numPecasSelecionada > 1){
				return 0;
			}
			TAB_RemovePecaCasa(casaSelecionada);
			BAR_InserePeca(corSelecionada);
		}
	} 
	TAB_RemovePecaCasa(casaFixada);
	TAB_InserePecaCasa(casaSelecionada,jogadorAtual);
	return 1;
}

int proxCasaDeCor ( int casaSelecionada, CorPecas cor ){
	int i, qtdPecasCasas;
	CorPecas coresPecasCasa;
	for(i = casaSelecionada; i < 24; i++){
		TAB_NumPecasCasa(i+1,&qtdPecasCasas);
		if(qtdPecasCasas > 0){
			// Se tiver peça na casa, ve a cor da peça
			TAB_CorPecasCasa(i+1,&coresPecasCasa);
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

void imprimirJogo( CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ) 
{
	int i,f;
	int qtdPecasCasas[24], qtdPecasBarras[2];
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
		printf("|\n");
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
		printf("|\n");
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

void imprimeResto( int totalCasa, CorPecas cor ) {
	if(totalCasa-4 > 9){
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

void imprimePeca( int totalCasa, CorPecas cor, int posicao ) {
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

int temDadoNessaCasa( int numeroCasa, CorPecas jogadorAtual, int casaFixada, int dados[4] ) {
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

void imprimeNumeroCasa( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ){
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

void imprimeSetaSelecao( int numeroCasa, CorPecas jogadorAtual, int casaSelecionada, int casaFixada, int dados[4] ){
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