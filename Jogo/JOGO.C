
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "..\Tabuleiro\TABULEIRO.H"
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
#define SECUNDARIO "[1;34m"
#define TERCIARIO "[1;33m"

	static int casaSelecionada = 0, vezDoJogador = 0, dados[2] ;
	static char *cores[2];

/***** Protótipos das funções encapuladas no módulo *****/

	static void imprimeResto( int posicao, CorPecas cor ) ;

	static void imprimePeca( int posicao, CorPecas cor, int totalCasa ) ;

	static void imprimeSetaSelecao( int i, int posicaoSelecionada ) ;

	static void JOG_ImprimirJogo( void ) ;

	static void menuInicial( void ) ;

	static void novoJogo( void ) ;

/***************************************************************************
*
*  Função: JOG Iniciar Jogo
*  ****/

	void JOG_IniciarJogo( void ) 
	{
		cores[Preta] = PRETO;
		cores[Vermelha] = VERMELHO;
		TAB_CriarTabuleiro();
		CLEAR_SCREEN;
		menuInicial();

	} /* Fim função: JOG Iniciar Jogo */

/***************************************************************************
*
*  Função: JOG Imprimir Jogo
*  ****/

	void JOG_ImprimirJogo( void ) 
	{
		int i,f;
  	int qtdPecasCasas[24];
  	CorPecas coresPecasCasas[24];
		// Salvar o tipo de peça da casa
    for(i = 0; i < 24; i++){
			TAB_NumPecasCasa(i+1,&qtdPecasCasas[i]);
			if(qtdPecasCasas[i] > 0){
				// Se tiver peça na casa, ve a cor da peça
				TAB_CorPecasCasa(i+1,&coresPecasCasas[i]);
			}
    } 

		printf("\n  ");
		for(i = 12; i > 6; i--){ 
			imprimeSetaSelecao(i,casaSelecionada);
		}
		printf("    ");
		for(; i > 0; i--){
			imprimeSetaSelecao(i,casaSelecionada);
		}
		printf("\n");
		printf("/-----------------------------------------\\\n");
		printf("| ");
		for(i = 12; i > 6; i--){
			if(i == casaSelecionada){
				printf("\033%s%02d\033[0m ",PRIMARIO,i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("| | ");
		for(; i > 0; i--){
			if(i == casaSelecionada){
				printf("\033%s%02d\033[0m ",PRIMARIO,i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("|\n");
		printf("|-------------------| |-------------------|\n");

		for(f = 1; f < 6; f ++){
			printf("| ");
			for(i = 12; i > 6; i--){
				imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
				printf(" ");
			}
			printf("| | ");
			for(; i > 0; i--){
				printf(" ");
				imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
			}
			printf("|\n");
		}

		printf("|                   | |                   |\n");
		printf("|                   | |                   |\n");

		for(f = 5; f > 0 ; f --){
			printf("| ");
			for(i = 13; i < 19; i++){
				imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
				printf(" ");
			}
			printf("| | ");
			for(; i < 25; i++){
				printf(" ");
				imprimePeca(qtdPecasCasas[i-1],coresPecasCasas[i-1],f);
			}
			printf("|\n");
		}
		printf("|-------------------| |-------------------|\n");
		printf("| ");
		for(i = 13; i < 19; i++){
			if(i == casaSelecionada){
				printf("\033%s%02d\033[0m ",PRIMARIO,i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("| | ");
		for(; i < 25; i++){
			if(i == casaSelecionada){
				printf("\033%s%02d\033[0m ",PRIMARIO,i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("|\n");
		printf("\\-----------------------------------------/\n");
		printf("  ");
		for(i = 13; i < 19; i++){
			imprimeSetaSelecao(i,casaSelecionada);
		}
		printf("    ");
		for(; i < 25; i++){
			imprimeSetaSelecao(i,casaSelecionada);
		}
		printf("\nJogadas Disponiveis: ");
		if(dados[0] > 0){
			printf("%d ",dados[0]);
		}
		if(dados[1] > 0){
			printf("%d ",dados[1]);
		}
		printf("\nj - jogar dados\n");
		printf("d - dobrar pontos\n");
		printf("s - salvar partida\n");
		printf("n - novo jogo\n");
	} /* Fim função: JOG Imprimir Jogo */

void imprimeResto( int posicao, CorPecas cor ) {
	if(posicao-4 > 9){
		printf("\b");
	}
	if(posicao > 5){
		printf("\033%s+%d\033[0m",cores[cor],posicao-4);
	} else if(posicao == 5) {
		printf("\033%so\033[0m ",cores[cor]);
	}else{
		printf("  ");
	}
}

void imprimePeca( int posicao, CorPecas cor, int totalCasa ) {
	if(totalCasa == 5){
		imprimeResto(posicao,cor);
		return;
	}
	if(posicao >= totalCasa){
		printf("\033%so\033[0m",cores[cor]);
	} else{
		printf(" ");
	}
	printf(" ");
}

void menuInicial() {
	int ch1, ch2, opcaoSelecionada = 0;
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
}

void iniciarJogo(){
	CorPecas corAtual = Vermelha;
	while(1){
		CLEAR_SCREEN;
		printf("\nVez do \033%sJogador %d\033[0m\n",cores[corAtual],vezDoJogador);
		JOG_ImprimirJogo();
		getch();
		
	}
}

void novoJogo(){
	int jg1[2],jg2[2];
	jg1[0]=0;jg1[1]=0;
	jg2[0]=0;jg2[1]=0;
	CLEAR_SCREEN;
	printf("\n Escolha quem sera o JOGADOR 1 e quem sera o JOGADOR 2\n\n");
	printf("\n Pressione qualquer tecla para avancar\n\n");
	getch();
	CLEAR_SCREEN;
	printf("\n Sortear os 2 dados pra ver quem comeca\n\n");
	printf("\n Pressione qualquer tecla para sortear\n\n");
	while(1){
		getch();
		DAD_JogarDado(&jg1[0]);DAD_JogarDado(&jg1[1]);
		DAD_JogarDado(&jg2[0]);DAD_JogarDado(&jg2[1]);
		CLEAR_SCREEN;
		printf("\n Sortear os 2 dados pra ver quem comeca\n");
		printf("\n JOGADOR 1:  %d + %d = %d",jg1[0],jg1[1],jg1[0]+jg1[1]);
		printf("\n JOGADOR 2:  %d + %d = %d",jg2[0],jg2[1],jg2[0]+jg2[1]);
		if(jg1[0]+jg1[1] == jg2[0]+jg2[1]){
			printf("\n\n Empatou...");
			printf("\n\n Pressione qualquer tecla para sortear novamente\n\n");
		} else {
			if(jg1[0]+jg1[1] > jg2[0]+jg2[1]){
				vezDoJogador = 1;
				dados[0] = jg1[0];dados[1] = jg1[1];
			} else {
				vezDoJogador = 2;
				dados[0] = jg2[0];dados[1] = jg2[1];
			}
			break;
		}
	}
	printf("\n\n JOGADOR %d comeca! Ele joga com as pecas \033%svermelhas\033[0m",vezDoJogador,cores[Vermelha]);
	printf("\n\n Pressione qualquer tecla para comecar o jogo\n\n");
	getch();

	iniciarJogo();
}


void imprimeSetaSelecao( int i, int posicaoSelecionada ){
	if(i == posicaoSelecionada){
		if(i < 13){
			printf("\033%s\\/\033[0m ",PRIMARIO);
		} else {
      printf("\033%s/\\\033[0m ",PRIMARIO);
		}
	} else{
		printf("   ");
	}
}