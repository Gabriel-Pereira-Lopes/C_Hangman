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
	char* result = gerarPalavraAleatoria();

	escolherPalavra(palavra);

	while (errosAtuais < maxErros) {
		if (strcmp(palavra, result) != 0) {  // Se as palavras são diferentes
				printf("Continue tentando!\n");
				errosAtuais++;
				if (errosAtuais == 5) {
					printf("Sua última chance!\n");
				}
				escolherPalavra(palavra);
		} else {
				printf("A palavra escolhida foi: %s\n", palavra);
			break;
		}
	}
	if (errosAtuais == maxErros) {
		printf("Você atingiu o número máximo de tentativas!\n");
	}
return 0;
}