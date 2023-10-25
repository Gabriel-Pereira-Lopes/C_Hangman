#include <stdio.h>
#include <string.h>

void escolherPalavra(char with[]) {

	printf("Escolha uma palavra!\n");
	scanf("%s", with);
	}

int main() {
	char palavra[40];
	int maxErros = 6;
	int errosAtuais = 0;

	escolherPalavra(palavra);

	while (errosAtuais < maxErros)
	{
		printf("continue tentando!");
	}

	printf("A palavra escolhida foi: %s\n", palavra);

	// Restante do código...

	return 0;
}