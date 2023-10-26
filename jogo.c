#include <stdio.h>
#include <string.h>
char* gerarPalavraAleatoria() {
	char* palavras[] = {
		"banana",
		"computador",
		"teclado",
		"janela",
		"programacao"
	};

	int numeroDePalavras = sizeof(palavras) / sizeof(palavras[0]);

	srand(time(NULL));

	int indiceAleatorio = rand() % numeroDePalavras;
return palavras[indiceAleatorio];
}
void escolherPalavra(char with[]) {

	printf("Escolha uma palavra!\n");
	scanf("%s", with);
	}

int main() {
	char palavra[40];
	int maxErros = 6;
	int errosAtuais = 0;
	char result[40] ;

	gerarPalavraAleatoria() = result;

	escolherPalavra(palavra);

	while (errosAtuais < maxErros)
	{
		if (palavra != result){
			printf("continue tentando!");
			errosAtuais++;
			escolherPalavra(palavra);
		}
			if (errosAtuais==5){
			printf("Sua ultima chance!");
			}
		else if (palavra == result){
			printf("A palavra escolhida foi: %s\n", palavra);
		}
	}

	return 0;
}