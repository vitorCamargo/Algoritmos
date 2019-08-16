#include <stdio.h>
#include <string.h>

char descodifica(char *l);
void mostrarCodigo();

char descodifica(char *l) {
	char r;
	
	if(strcmp(l, ".-") == 0)
		r = 'a';
	else if(strcmp(l,  "-...") == 0)
		r = 'b';
	else if(strcmp(l, "-.-.") == 0)
		r = 'c';
	else if(strcmp(l, "-..") == 0)
		r = 'd';
	else if(strcmp(l, ".") == 0)
		r = 'e';
	else if(strcmp(l, "..-.") == 0)
		r = 'f';
	else if(strcmp(l, "--.") == 0)
		r = 'g';
	else if(strcmp(l, "....") == 0)
		r = 'h';
	else if(strcmp(l, "..") == 0)
		r = 'i';
	else if(strcmp(l, ".---") == 0)
		r = 'j';
	else if(strcmp(l, "-.-") == 0)
		r = 'k';
	else if(strcmp(l, ".-..") == 0)
		r = 'l';
	else if(strcmp(l, "--") == 0)
		r = 'm';
	else if(strcmp(l, "-.") == 0)
		r = 'n';
	else if(strcmp(l, "---") == 0)
		r = 'o';
	else if(strcmp(l, ".--.") == 0)
		r = 'p';
	else if(strcmp(l, "--.-") == 0)
		r = 'q';
	else if(strcmp(l, ".-.") == 0)
		r = 'r';
	else if(strcmp(l, "...") == 0)
		r = 's';
	else if(strcmp(l, "-") == 0)
		r = 't';
	else if(strcmp(l, "..-") == 0)
		r = 'u';
	else if(strcmp(l, "...-") == 0)
		r = 'v';
	else if(strcmp(l, ".--") == 0)
		r = 'w';
	else if(strcmp(l, "-..-") == 0)
		r = 'x';
	else if(strcmp(l, "-.--") == 0)
		r = 'y';
	else if(strcmp(l, "--..") == 0)
		r = 'z';
	else if(strcmp(l, ".----") == 0)
		r = '1';
	else if(strcmp(l, "..---") == 0)
		r = '2';
	else if(strcmp(l, "...--") == 0)
		r = '3';
	else if(strcmp(l, "....-") == 0)
		r = '4';
	else if(strcmp(l, ".....") == 0)
		r = '5';
	else if(strcmp(l, "-....") == 0)
		r = '6';
	else if(strcmp(l, "--...") == 0)
		r = '7';
	else if(strcmp(l, "---..") == 0)
		r = '8';
	else if(strcmp(l, "----.") == 0)
		r = '9';
	else
		r = '0';
		
	return r;
}

void mostrarCodigo() {
	char c;
	FILE *p;
	FILE *r;
	
	p = fopen("codificado.txt", "r");
	r = fopen("decodificado.txt", "r");
	
	if (p == NULL || r == NULL) printf("Erro na abertura\n");
	else{
		printf("\nCodigo Morse: \n");
		while((c = fgetc(p)) != EOF) printf("%c", c);
		
		printf("\n\nAlfanumerico: \n");
		while((c = fgetc(r)) != EOF) printf("%c", c);
	}
	fclose(p);
	fclose(r);
}

void main() {
	char c = 0, cod[6], aux = 0;
	FILE *p;
	FILE *r;
	
	r = fopen("decodificado.txt", "w");
	p = fopen("codificado.txt", "r");
	
	if (p == NULL || r == NULL) printf("Erro na abertura!\n");
	else
		while(c != EOF){
			c = fgetc(p);
			if(c == ' '){
				fputc(descodifica(cod), r);
				aux = 0;
				strncpy(cod, "", 5);
			} else if(c == '/'){
				fputc(' ', r);
				c = fgetc(p);
			} else {
				cod[aux] = c;
				aux++;
			}
		}
	
	fclose(p);
	fclose(r);
	mostrarCodigo();
}
