
#include <conio.h>
#include <stdio.h>
#include <string.h>

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
		int i,f, selected = 1;
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

		printf("\nVez do Jogador v\n");
		printf("\n  ");
		for(i = 12; i > 6; i--){ 
			imprimeSetaSelecao(i,selected);
		}
		printf("    ");
		for(; i > 0; i--){
			imprimeSetaSelecao(i,selected);
		}
		printf("\n");
		printf("/-----------------------------------------\\\n");
		printf("| ");
		for(i = 12; i > 6; i--){
			if(i == selected){
				printf("\033[1;36m%02d\033[0m ",i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("| | ");
		for(; i > 0; i--){
			if(i == selected){
				printf("\033[1;36m%02d\033[0m ",i);
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
			if(i == selected){
				printf("\033[1;36m%02d\033[0m ",i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("| | ");
		for(; i < 25; i++){
			if(i == selected){
				printf("\033[1;36m%02d\033[0m ",i);
			} else{
				printf("%02d ",i);
			}
		}
		printf("|\n");
		printf("\\-----------------------------------------/\n");
		printf("  ");
		for(i = 13; i < 19; i++){
			imprimeSetaSelecao(i,selected);
		}
		printf("    ");
		for(; i < 25; i++){
			imprimeSetaSelecao(i,selected);
		}
		printf("\n");
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
		if(cor == Preta){
			printf("\033[0;32m+%d\033[0m",posicao-4);
		} else {
			printf("\033[0;31m+%d\033[0m",posicao-4);
		}
	} else if(posicao == 5) {
		if(cor == 0){
			printf("\033[0;32mo\033[0m ");
		} else {
			printf("\033[0;31mo\033[0m ");
		}
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
		if(cor == Preta){
			printf("\033[0;32mo\033[0m");
		} else {
			printf("\033[0;31mo\033[0m");
		}
	} else{
		printf(" ");
	}
	printf(" ");
}

void menuInicial() {
	int ch1, ch2, opcaoSelecionada = 0;
	while(1){
		printf("\n      G A M A O \n\n  ");
		if(opcaoSelecionada == 0) { printf("\033[1;36m>"); }
		else{ printf(" "); }
		printf(" Novo Jogo\033[0m\n  ");
		if(opcaoSelecionada == 1) { printf("\033[1;36m>"); }
		else{ printf(" "); }
		printf(" Carregar Jogo\033[0m\n  ");
		if(opcaoSelecionada == 2) { printf("\033[1;36m>"); }
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

void novoJogo(){
	int ch, jg1[2],jg2[2];
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
			break;
		}
	}
	if(jg1[0]+jg1[1] > jg2[0]+jg2[1]){
		printf("\n\n JOGADOR 1 comeca!");
	} else {
		printf("\n\n JOGADOR 2 comeca!");
	}
	printf("\n\n Pressione qualquer tecla para comecar o jogo\n\n");
	getch();
	
}


void imprimeSetaSelecao( int i, int posicaoSelecionada ){
	if(i == posicaoSelecionada){
		if(i < 13){
			printf("\033[1;36m\\/\033[0m ");
		} else {
      printf("\033[1;36m/\\\033[0m ");
		}
	} else{
		printf("   ");
	}
}