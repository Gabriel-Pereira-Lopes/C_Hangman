#include <stdio.h>
#include <string.h>
char* gerarPalavraAleatoria() {
	char* palavras[] = {
		"banana",
		"computador",
		"teclado",
		"janela",
		"programacao",
		"abacaxi",
		"girassol",
		"computador",
		"biblioteca",
		"elefante",
		"chocolate",
		"astronomia",
		"diamante",
		"escorregador",
		"universo",
		"paralelepípedo",
		"ventilador",
		"caminhão",
		"estrela",
		"cachoeira",
		"borboleta",
		"esqueleto",
		"astronomo",
		"gramática",
		"lamparina",
		"pirâmide",
		"misterioso",
		"teclado",
		"enciclopédia",
		"espinhaço",
		"retângulo",
		"planetário",
		"dinossauro",
		"orquídea",
		"palpiteiro"
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
	char* result = gerarPalavraAleatoria();
	int maxErros = 6;
	int errosAtuais = 0;

	escolherPalavra(palavra);

	while (errosAtuais < maxErros) {
		for (int i = 1; i < 5;) {
			if (strcmp(palavra, result) != 0) {
					printf("Continue tentando! %d Tentativa\n", i);
					errosAtuais++;
					i++;
					if (errosAtuais == 5) {
						printf("Sua última chance!\n");
					}
			} else {
					printf("A palavra escolhida foi: %s\n", palavra);
					break;  // Sair do loop for
			}
			escolherPalavra(palavra);
		}

		if (errosAtuais == maxErros) {
			printf("Você atingiu o número máximo de tentativas!\n");
			break;  // Sair do loop while
		}
	}
return 0;
}