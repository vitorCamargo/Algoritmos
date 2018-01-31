#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 3

int jog, peca[2], x = 0;

int calcLinha(int op);
int calcCol(int op);
void mostraJogo(int tabuleiro[][N]);
void jogada(int tabuleiro[][N]);
int checaLocal(int tabuleiro[][N], int i, int j);
int acabou(int tabuleiro[][N]);

int calcLinha(int op){
	int i;
	
	if(op == 1 || op == 2 || op == 3) i = 0;
	else if(op == 4 || op == 5 || op == 6) i = 1;
	else i = 2;
	
	return i;
}

int calcCol(int op){
	int j;
	
	if(op == 1 || op == 4 || op == 7) j = 0;
	else if(op == 2 || op == 5 || op == 8) j = 1;
	else j = 2;
	
	return j;
}

void mostraJogo(int tabuleiro[][N]){
	int i, j;
    printf("\n");
 
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(tabuleiro[i][j] > 0 && x == 0){
                printf("  %d ", tabuleiro[i][j]);
            } else if(tabuleiro[i][j] > 0){
            	printf("    ");
			} else {
                if(tabuleiro[i][j] == -1)
                    printf("  X ");
                else
                    printf("  O ");
 			}
            if(j != 2) printf("|");
        }
        if(i != 2) printf("\n--------------\n");
    }
    printf("\n");
    x++;
}

void jogada(int tabuleiro[][N]) {
	int op, i, j, aux;
	
    jog++;
    printf("\n--> Jogador %d \n", (jog % 2) + 1);
	
    do{
    	do{
    		printf("Lugar: ");
        	scanf("%d", &op);
		} while(op < 1 || op > 9);
        
        i = calcLinha(op);
        j = calcCol(op);
 
        if(checaLocal(tabuleiro, i, j) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
 
    } while(checaLocal(tabuleiro, i, j) == 0);
 
    if(jog%2 == 1)
        tabuleiro[i][j] = peca[0];
    else
        tabuleiro[i][j] = peca[1]; 
}

int checaLocal(int tabuleiro[][N], int i, int j){
	if(tabuleiro[i][j] < 1)
        return 0;
    else
        return 1;
}

int acabou(int tabuleiro[][N]){
	int i, j, s, dp = 0, ds = 0;

	//Vê a linha 
    for(i = 0; i < N; i++){
        s = 0;
        for(j = 0; j < N; j++)
            s += tabuleiro[i][j];
 
        if(s == 0 || s == -3){
        	mostraJogo(tabuleiro);
        	printf("\tACABOU. Jogador %d venceu! (por linha)\n\n", (jog%2)+1);
	        return 1;	
		}
    }

	//Vê a coluna
	for(j = 0; j < N; j++){
        s = 0;
        for(i = 0; i < N; i++)
            s += tabuleiro[i][j];
 
        if(s == 0 || s == -3){
        	mostraJogo(tabuleiro);
        	printf("\tACABOU. Jogador %d venceu! (por coluna)\n\n", (jog%2)+1);
	        return 1;
		}
    }

	//Vê as diagonais
    for(i = 0; i < N; i++){
        dp += tabuleiro[i][i];
        ds += tabuleiro[i][N-i-1];
    }
 
    if(dp == 0 || dp == -3 || ds == 0 || ds == -3){
    	mostraJogo(tabuleiro);
        printf("\tACABOU. Jogador %d venceu! (por diagonal)\n\n", (jog%2)+1);
        return 1;
    }

	//Vê se empatou
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++)
			if(tabuleiro[i][j] > 0) return 0;
	}
 
 	mostraJogo(tabuleiro);
	printf("\tACABOU. Empate\n\n");
    return 1;
}

void main(){
	char op;
	int tabuleiro[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	
	do{
		printf("--> Jogador 1: \tEscolha sua peca (X ou 0): ");
		scanf(" %c", &op);
		if(op == 'X' || op == 'x'){
			peca[1] = -1;
			peca[0] = 0;
		} else if(op == '0'){
			peca[0] = -1;
			peca[1] = 0;
		} else {
			printf("\nDigite corretamente!\n");
		}
	} while(op != 'X' && op != 'x' && op != '0');

	srand(time(NULL));
    jog = 1 + (rand() % 2);
    
    do {
    	printf("\n\n\n");
        mostraJogo(tabuleiro);
		jogada(tabuleiro);
    } while(acabou(tabuleiro) != 1);
    printf("\n\t\t\tObrigado por jogar. ASS: ~Vitor");
}
