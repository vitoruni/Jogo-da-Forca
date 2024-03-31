#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

int main()
{
	char palavra[30]="", letra, lacuna[30]="", dica[30]="";
	int a, i, vida=7, cont, venceu=0, pontos=0;

	printf("Digite a palavra secreta: ");
	gets(palavra);
	printf("Digite a dica: ");
	gets(dica);

	for(i=0; i<strlen(palavra); i++)
    {
        if(palavra[i]!=' ') lacuna[i] = '_';
        else lacuna[i] = ' ';
    }

	while(vida > 0 && venceu == 0)
	{
		system("cls");
		printf("Dica: %s\n", dica);
		printf("Quantidade de letras: %d\n", strlen(palavra));
		printf("Vidas: %d\n\n", vida);

		printf("%s", lacuna);
		printf("\n\n");

		printf("Digite uma letra: ");
		letra = getch();

		printf("%c\n", letra);

		for(a=0; a<strlen(palavra); a++)
		{
			if(palavra[a]==letra)
			{
				lacuna[a] = letra;
				cont++;
				pontos+=2;
			}
		}

		if(cont==0)
		{
			printf("Voce errou uma letra!\n");
			vida--;
			Sleep(500);
		}

		if(cont>0)
		{
			printf("Voce acertou uma letra!\n");
			Sleep(500);
		}
		if(vida == 0) venceu=-1;

		if(strcmp(palavra, lacuna)==0) venceu=1;
		cont=0;

	}

	printf("\n");
	if(venceu==1) printf("Parabens! Voce venceu! Fez %d pontos.\n\n", pontos+vida*3);
	if(venceu==-1) printf("Voce perdeu! Fez %d pontos.\n\n", pontos);
	printf("Pressione qualquer tecla para continuar...");
	getch();

}
