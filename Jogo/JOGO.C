
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

/***************************************************************************
*
*  Função: JOG Iniciar Jogo
*  ****/

	void JOG_IniciarJogo( void ) 
	{
		int ch1, ch2, se = 1;
		printf("PRESS A KEY TO CONTINUE \n");
		ch1 = getch();
		ch2 = 0;
		CLEAR_SCREEN;
		TAB_CriarTabuleiro();
		JOG_ImprimirJogo();
		system("pause");

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