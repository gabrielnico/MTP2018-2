/* P1.c */
/* Gabriel Nogueira Nico */
/* 11811EEL012 */

#include <stdio.h>

int main() 
{
	int estado = 0, i;
	char bits[256];
	printf("Digite a sequencia de bits: ");
	fflush(stdin);
	scanf("%s", bits);
	for(i = 0; bits[i] != '\0'; i++)
	{
		if(estado == 0 && bits[i] == '0')
			;
		else if(estado == 0 && bits[i] == '1')
			estado = 1;
		else if(estado == 1 && bits[i] == '0')
			estado = 2;
		else if(estado == 1 && bits[i] == '1')
			estado = 0;
		else if(estado == 2 && bits[i] == '0')
			estado = 1;
		else if(estado == 2 && bits[i] == '1')
			;
	}
	printf("O valor da variavel estado eh: %i\n", estado);
	if(estado == 0)
		printf("%s e multiplo de 3", bits);
	else
		printf("%s nao e", bits);
	return 0;
}
