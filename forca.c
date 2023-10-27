#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char* montapalavra() {
	static char* palavras[] = {
		"banana", "computador", "teclado", "janela", "programacao", "abacaxi",
		"girassol", "biblioteca", "elefante", "chocolate", "astronomia",
		"diamante", "escorregador", "universo", "paralelepipedo", "ventilador",
		"caminhao", "estrela", "cachoeira", "borboleta", "esqueleto", "astronomo",
		"gramatica", "lamparina", "piramide", "misterioso", "enciclopedia",
		"espinhaco", "retangulo", "planetario", "dinossauro", "orquidea", "palpiteiro"
	};

	int numeroDePalavras = sizeof(palavras) / sizeof(palavras[0]);
	srand(time(NULL));
	int indiceAleatorio = rand() % numeroDePalavras;
	return palavras[indiceAleatorio];
}

void desenhaForca(int erros) {
	printf(" +---+\n");
	printf(" |   |\n");

	if(erros >= 1) printf(" O   |\n");
	else printf("     |\n");

	if(erros == 2) printf(" |   |\n");
	else if(erros == 3) printf("/|   |\n");
	else if(erros >= 4) printf("/|\\  |\n");
	else printf("     |\n");

	if(erros == 5) printf("/    |\n");
	else if(erros >= 6) printf("/ \\  |\n");
	else printf("     |\n");

	printf("     |\n");
	printf("=========\n");
}

void preencheComTracos(char palavra[], char tracos[]) {
	int tamanho = strlen(palavra);
	for (int i = 0; i < tamanho; i++) {
		tracos[i] = '-';
	}
	tracos[tamanho] = '\0';  // Finalizar a string
}

char pedeLetra() {
	char letra;
	printf("Digite uma letra: ");
	scanf(" %c", &letra);  // espaço antes de %c para ignorar whitespace anterior
	return letra;
}

int letraEstaNaPalavra(char letra, char palavra[]) {
	for (int i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == letra) {
			return 1;
		}
	}
	return 0;
}

void atualizaTracos(char letra, char palavra[], char tracos[]) {
	for (int i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == letra) {
			tracos[i] = letra;
		}
	}
}

int main() {
	// Inicialização
	char palavra[100], tracos[100];
	int erros = 0;
	int tentativas = 6; // Reduzido para 6, já que é o número máximo de partes na forca.

	// Escolha uma palavra aleatoriamente
	strcpy(palavra, montapalavra());

	// Substitua palavra por tracos
	preencheComTracos(palavra, tracos);

	// Enquanto não adivinhou e não ultrapassou o número de erros
	while(strcmp(palavra, tracos) != 0 && erros < tentativas) {
		// Mostra tracos
		printf("%s\n", tracos);

		// Pede uma letra ao usuário
		char chute = pedeLetra();

		// Se a letra não está na palavra, aumenta o número de erros
		if(!letraEstaNaPalavra(chute, palavra)) {
			erros++;
		} else {
			atualizaTracos(chute, palavra, tracos);
		}

		// Desenha a forca
		desenhaForca(erros);
	}

	// Mostra mensagem final
	if(strcmp(palavra, tracos) == 0) {
		printf("Você venceu!\n");
	} else {
		printf("Você perdeu. A palavra era: %s\n", palavra);
	}

	return 0;
}
