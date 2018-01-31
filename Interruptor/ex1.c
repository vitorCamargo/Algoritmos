#include <stdio.h>

void verifica(char *ponto);

void verifica(char *ponto){
	int i, aux = 0;
	for(i = 0; i < 5; i++)
		if(ponto[i] == ponto[i+5]){
			aux = -1;
			i = 5;
		}
	
	if(aux == -1) printf("Incompatíveis!!");
	else printf("Compatíveis!!");
}

void main(){
	int i = 0;
	char c, pontos[10];
	FILE *p;
	
	p = fopen("entrada.txt", "r");
	
	if(p == NULL) printf("Erro ao abrir arquivo");
	else{
		while((c = fgetc(p)) != EOF){
			if(c == '1' || c == '0'){
				pontos[i] = c;
				i++;
			}
		}
	}
	verifica(pontos);
	fclose(p);
}
