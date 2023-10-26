#include <stdio.h>
#include <string.h>
char* montapalavra(){
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
int main(){
// Inicialização
char palavra[100], tracos[100];
int erros = 0;
int tentativas = 12;

// Escolha uma palavra aleatoriamente
escolherPalavra(palavra);

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