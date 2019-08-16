#include <stdio.h>
#include <string.h>

void codifica(char l, FILE *r);
void mostrarCodigo();

void codifica(char l, FILE *r) {
	char f[7];
	
	if(l == 'a' || l == 'A')
		strcpy(f, ".- ");
	else if(l == 'b' || l == 'B')
		strcpy(f, "-... ");
	else if(l == 'c' || l == 'C')
		strcpy(f, "-.-. ");
	else if(l == 'd' || l == 'D')
		strcpy(f, "-.. ");
	else if(l == 'e' || l == 'E')
		strcpy(f, ". ");
	else if(l == 'f' || l == 'F')
		strcpy(f, "..-. ");
	else if(l == 'g' || l == 'G')
		strcpy(f, "--. ");
	else if(l == 'h' || l == 'H')
		strcpy(f, ".... ");
	else if(l == 'i' || l == 'I')
		strcpy(f, ".. ");
	else if(l == 'j' || l == 'J')
		strcpy(f, ".--- ");
	else if(l == 'k' || l == 'K')
		strcpy(f, "-.- ");
	else if(l == 'l' || l == 'L')
		strcpy(f, ".-.. ");
	else if(l == 'm' || l == 'M')
		strcpy(f, "-- ");
	else if(l == 'n' || l == 'N')
		strcpy(f, "-. ");
	else if(l == 'o' || l == 'O')
		strcpy(f, "--- ");
	else if(l == 'p' || l == 'P')
		strcpy(f, ".--. ");
	else if(l == 'q' || l == 'Q')
		strcpy(f, "--.- ");
	else if(l == 'r' || l == 'R')
		strcpy(f, ".-. ");
	else if(l == 's' || l == 'S')
		strcpy(f, "... ");
	else if(l == 't' || l == 'T')
		strcpy(f, "- ");
	else if(l == 'u' || l == 'U')
		strcpy(f, "..- ");
	else if(l == 'v' || l == 'V')
		strcpy(f, "...- ");
	else if(l == 'w' || l == 'W')
		strcpy(f, ".-- ");
	else if(l == 'x' || l == 'X')
		strcpy(f, "-..- ");
	else if(l == 'y' || l == 'Y')
		strcpy(f, "-.-- ");
	else if(l == 'z' || l == 'Z')
		strcpy(f, "--.. ");
	else if(l == '1')
		strcpy(f, ".---- ");
	else if(l == '2')
		strcpy(f, "..--- ");
	else if(l == '3')
		strcpy(f, "...-- ");
	else if(l == '4')
		strcpy(f, "....- ");
	else if(l == '5')
		strcpy(f, "..... ");
	else if(l == '6')
		strcpy(f, "-.... ");
	else if(l == '7')
		strcpy(f, "--... ");
	else if(l == '8')
		strcpy(f, "---.. ");
	else if(l == '9')
		strcpy(f, "----. ");
	else if(l == '0')
		strcpy(f, "----- ");
	else
		strcpy(f, "/ ");
	
	fprintf(r, "%s", f);
}

void mostrarCodigo() {
	char c;
	FILE *p;
	FILE *r;
	
	p = fopen("codificado.txt", "r");
	r = fopen("decodificado.txt", "r");
	
	if (p == NULL || r == NULL) printf("Erro na abertura\n");
	else{
		printf("\nAlfanumerico: \n");
		while((c = fgetc(r)) != EOF) printf("%c", c);
		
		printf("\n\nCodigo Morse: \n");
		while((c = fgetc(p)) != EOF) printf("%c", c);
	}
	fclose(p);
	fclose(r);
}

void main() {
	char c;
	FILE *p;
	FILE *r;
	
	r = fopen("codificado.txt", "w");	
	p = fopen("decodificado.txt", "r");
	
	if (p == NULL || r == NULL) printf("Erro na abertura!\n");
	else
		while((c = fgetc(p)) != EOF) codifica(c, r);
	
	fclose(p);
	fclose(r);
	mostrarCodigo();
}
